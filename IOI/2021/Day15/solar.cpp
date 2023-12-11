#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 200005;
const int LOG = 18;

struct segmentTree {
#define il i * 2
#define ir i * 2 + 1

    vector <ll> val, tag;
    int lo, hi, N; ll res;

    void init(int N) {
        this->N = N;
        val.assign(4 * N, 0);
        tag.assign(4 * N, 0);
    }

    void add(int i, int l, int r, ll v) {
        if (l >= lo && r <= hi) {
            val[i] += v * (r - l + 1);
            tag[i] += v; return;
        }
        int m = (l + r) / 2;
        if (tag[i]) {
            val[il] += tag[i] * (m - l + 1);
            tag[il] += tag[i];
            val[ir] += tag[i] * (r - m);
            tag[ir] += tag[i];
            tag[i] = 0;
        }
        if (m >= lo) add(il, l, m, v);
        if (m < hi) add(ir, m + 1, r, v);
        val[i] = val[il] + val[ir];
    }

    void add(int l, int r, ll v) {
        lo = l; hi = r; add(1, 1, N, v);
    }

    void get(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res += val[i]);
        int m = (l + r) / 2;
        if (tag[i]) {
            val[il] += tag[i] * (m - l + 1);
            tag[il] += tag[i];
            val[ir] += tag[i] * (r - m);
            tag[ir] += tag[i];
            tag[i] = 0;
        }
        if (m >= lo) get(il, l, m);
        if (m < hi) get(ir, m + 1, r);
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        lo = l; hi = r; res = 0;
        get(1, 1, N); return res;
    }

    int find(ll v) {
        if (val[1] < v) return -1;
        int i = 1, l = 1, r = N;
        while (l < r) {
            int m = (l + r) / 2;
            if (tag[i]) {
                val[il] += tag[i] * (m - l + 1);
                tag[il] += tag[i];
                val[ir] += tag[i] * (r - m);
                tag[ir] += tag[i];
                tag[i] = 0;
            }
            if (val[il] >= v) {
                i = il; r = m;
            } else {
                v -= val[il];
                i = ir; l = m + 1;
            }
        }
        return l;
    }
};

int par[LOG][MAXN], timer;
int tin[MAXN], tout[MAXN];
int bel[MAXN];
vector <int> adj[MAXN];
segmentTree ST;

void DFSpre(int u) {
    for (int i = 1; i < LOG; i++)
        par[i][u] = par[i - 1][par[i - 1][u]];
    bel[tin[u] = ++timer] = u;
    for (int v : adj[u])
        if (v != par[0][u]) {
            par[0][v] = u; DFSpre(v);
        }
    tout[u] = timer;
}

ll getSum(int u) {
    return ST.get(tin[u], tout[u]);
}

int findCen() {
    ll half = (getSum(1) + 1) / 2;
    int u = bel[ST.find(half)];
    if (getSum(u) >= half) return u;
    for (int i = LOG - 1; i >= 0; i--)
        if (par[i][u] && getSum(par[i][u]) < half)
            u = par[i][u];
    return par[0][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFSpre(1); ST.init(N);
    for (int i = 1; i <= N; i++) {
        int c; cin >> c;
        ST.add(tin[i], tin[i], c);
    }
    while (Q--) {
        int cmd, u, w;
        cin >> cmd >> u >> w;
        if (cmd == 1)
            ST.add(tin[u], tin[u], w);
        else if (cmd == 2)
            ST.add(tin[u], tin[u], -w);
        else if (cmd == 3)
            ST.add(tin[u], tout[u], w);
        else if (cmd == 4)
            ST.add(tin[u], tout[u], -w);
        cout << findCen() << '\n';
    }
}
