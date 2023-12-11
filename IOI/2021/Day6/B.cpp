#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 120005;
const int LOG = 17;

int tin[MAXN], tout[MAXN], timer;
int rmq[LOG][MAXN], par[MAXN];
int up_hei[MAXN], dn_hei[MAXN];
int up_head[MAXN], dn_head[MAXN];
vector <int> order, adj[MAXN];
int dep[MAXN], tour[MAXN], last, lg[MAXN];

struct segment {
    int x, t1, t2;
 
    segment(int x, int t1, int t2): x(x), t1(t1), t2(t2) {}
 
    bool operator < (const segment &o) const {
        return x < o.x || (x == o.x && t1 < o.t1);
    }
};

void DFS(int u) {
    tin[u] = timer++;
    order.push_back(u);
    dn_hei[u] = 0;
    dep[u] = dep[par[u]] + 1;
    for (int v : adj[u])
        if (v != par[u]) {
            tour[last] = u;
            rmq[0][last++] = tin[u];
            par[v] = u; DFS(v);
            cmax(dn_hei[u], dn_hei[v] + 1);
        }
    tout[u] = timer;
}

int LCA(int u, int v) {
    static int k;

    if (u == v) return u;
    tie(u, v) = minmax(tin[u], tin[v]);
    k = lg[v - u];
    return tour[min(rmq[k][u], rmq[k][v - (1 << k)])];
}

bool is_anc(int r, int u) {
    return tin[r] <= tin[u] && tout[r] > tin[u];
}

void get_seq(int s, int t, int st, int cut,
vector <segment> &lef, vector <segment> &rig) {
    while (dep[dn_head[s]] > dep[cut]) {
        lef.emplace_back(dn_hei[s], 1, 0);
        lef.emplace_back(dn_hei[dn_head[s]] + 1, -1, 0);
        s = par[dn_head[s]];
    }
    if (dep[s] > dep[cut]) {
        lef.emplace_back(dn_hei[s], 1, 0);
        lef.emplace_back(dn_hei[cut], -1, 0);
    }
    while (dep[dn_head[t]] > dep[st]) {
        rig.emplace_back(dn_hei[t], 1, 1);
        rig.emplace_back(dn_hei[dn_head[t]] + 1, -1, 1);
        t = par[dn_head[t]];
    }
    if (dep[t] > dep[st]) {
        rig.emplace_back(dn_hei[t], 1, 1);
        rig.emplace_back(dn_hei[t] + dep[t] - dep[st], -1, 1);
    }
    int last = rig.size(); s = cut;
    while (dep[up_head[s]] > dep[st]) {
        rig.emplace_back(up_hei[s] + 1, -1, 1);
        rig.emplace_back(up_hei[up_head[s]], 1, 1);
        
        s = par[up_head[s]];
    }
    if (dep[s] > dep[st]) {
        rig.emplace_back(up_hei[s] + 1, -1, 1);
        rig.emplace_back(up_hei[s] - dep[s] + dep[st] + 1, 1, 1);
    }
    reverse(rig.begin() + last, rig.end());
}

void solve() {
    int N, Q; cin >> N >> Q;
    timer = last = 0; order.clear();
    for (int i = 1; i <= N; i++)
        adj[i].clear();
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i + (1 << k) <= last; i++)
            rmq[k][i] = min(rmq[k - 1][i],
            rmq[k - 1][i + (1 << (k - 1))]);
    up_hei[1] = -1;
    for (int u : order) {
        int w;
        for (int v : adj[u])
            if (v != par[u]) {
                up_hei[v] = up_hei[u] + 1;
                if (dn_hei[v] + 1 == dn_hei[u])
                    w = v;
            }
        for (int v : adj[u])
            if (v != par[u] && v != w) {
                cmax(up_hei[v], dn_hei[w] + 1);
                cmax(up_hei[w], dn_hei[v] + 1);
            }
        if (dn_hei[u] + 1 == dn_hei[par[u]])
            dn_head[u] = dn_head[par[u]];
        else dn_head[u] = u;
        if (up_hei[u] - 1 == up_hei[par[u]])
            up_head[u] = up_head[par[u]];
        else up_head[u] = u;
    }
    while (Q--) {
        int r, s, t; cin >> r >> s >> t;
        int rs = LCA(r, s), rt = LCA(r, t);
        int st = LCA(s, t), cut;
        if (rs == rt) cut = st;
        else cut = rs != st ? rs : rt;
        vector <segment> lef, rig, all;
        long long res;
        if (is_anc(cut, s)) {
            int dis = dep[t] + dep[cut] - 2 * dep[st];
            res = 1ll * dis * (dis + 1) / 2;
            get_seq(s, t, st, cut, lef, rig);
        } else {
            int dis = dep[t] - dep[cut];
            res = 1ll * dis * (dis + 1) / 2; 
            get_seq(t, s, st, cut, rig, lef);
            for (auto &p : lef) p.t2 = 0;
            for (auto &p : rig) p.t2 = 1;
        }
        merge(lef.begin(), lef.end(), rig.begin(),
        rig.end(), back_inserter(all));
        int lenB = 0, lim = 0, cntA = 0, cntB = 0;
        for (auto s : all) {
            if (cntA) {
                res += 1ll * lenB * (s.x - lim);
                if (cntB)
                    res += 1ll * (s.x - lim - 1) * (s.x - lim) / 2;
                }
                if (cntB) lenB += s.x - lim;
                if (s.t2) cntB += s.t1;
                else cntA += s.t1;
                lim = s.x;
            }
        cout << res << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i >> 1] + 1;
    int T; cin >> T;
    while (T--) solve();
}