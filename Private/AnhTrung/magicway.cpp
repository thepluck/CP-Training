#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

struct path {
    int v, t; ll w;

    path(int v, int t, ll w): v(v), t(t), w(w) {}

    bool operator < (const path &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 5;
const ll inf = 1e18;

int par[N], sz[N], root[N][2];
ll d[N][2]; int best[N];
vector <int> spec, lst;
vector <path> adj[N];
priority_queue <path> pq;

int find_set(int u) {
    return u == par[u] ?
    u : par[u] = find_set(par[u]);
}

bool union_set(int u, int v) {
    u = find_set(u); v = find_set(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v]; par[v] = u;
    return 1;
}

bool same_set(int u, int v) {
    return find_set(u) == find_set(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].eb(v, 0, w);
        adj[v].eb(u, 0, w);
    }
    int k; cin >> k; d[0][1] = inf;
    for (int i = 1; i <= n; i++) {
        d[i][0] = inf;
        par[i] = i; sz[i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        int u; cin >> u;
        spec.eb(u); d[u][0] = 0;
        pq.emplace(u, 0, 0);
        root[u][0] = u;
    }
    while (!pq.empty()) {
        path cur = pq.top(); pq.pop();
        int u = cur.v; ll w = cur.w;
        if (w != d[u][0]) continue;
        for (path e : adj[u])
            if (d[e.v][0] > w + e.w) {
                d[e.v][0] = w + e.w;
                root[e.v][0] = root[u][0];
                pq.emplace(e.v, 0, d[e.v][0]);
            }
    }
    ll res = d[1][0]; lst = spec;
    while (lst.size() > 1) {
        for (int i = 1; i <= n; i++) {
            pq.emplace(i, 0, d[i][0]);
            root[i][1] = -1;
            d[i][1] = inf;
            best[i] = 0;
        }
        while (!pq.empty()) {
            path cur = pq.top(); pq.pop();
            int u = cur.v; ll w = cur.w;
            int t = cur.t, r = root[u][t];
            if (d[u][t] != w) continue;
            for (path e : adj[u])
                if (d[e.v][1] > w + e.w
                && !same_set(r, root[e.v][0])) {
                    d[e.v][1] = w + e.w;
                    root[e.v][1] = r;
                    pq.emplace(e.v, 1, d[e.v][1]);
                }
        }
        for (int u : spec) {
            int v = root[u][1];
            if (v == -1) continue;
            int r = find_set(u);            
            if (d[best[r]][1] > d[u][1])
                best[r] = u;
            r = find_set(v);
            if (d[best[r]][1] > d[u][1])
                best[r] = u;
        }
        for (int u : lst) {
            if (!best[u]) continue;
            int v = root[best[u]][1];
            if (union_set(best[u], v)) {
                res += d[best[u]][1];
            }
        }
        lst.clear();
        for (int u : spec)
            if (u == par[u]) lst.eb(u);
    }
    cout << res << '\n';
}