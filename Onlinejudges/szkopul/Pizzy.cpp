#include <bits/stdc++.h>

using namespace std;

using ii = pair <int, int>;
using ll = long long;

const int N = 100005;

struct segTree {
    vector <pair <ll, int>> val;
    vector <ll> tag;
    int n, lo, hi; ll res;

    void build(int i, int l, int r) {
        val[i] = {0, l};
        if (l < r) {
            int m = (l + r) / 2;
            build(i * 2, l, m);
            build(i * 2 + 1, m + 1, r);
        }
    }

    segTree(int n): n(n), val(4 * n),
    tag(4 * n) {build(1, 1, n);}

    void apply(int i, ll v) {
        val[i].first += v; tag[i] += v;
    }

    void push(int i) {
        apply(i * 2, tag[i]);
        apply(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }

    void add(int i, int l, int r, ll v) {
        if (l >= lo && r <= hi)
            return apply(i, v);
        push(i); int m = (l + r) / 2;
        if (m >= lo) add(i * 2, l, m, v);
        if (m < hi) add(i * 2 + 1, m + 1, r, v);
        val[i] = max(val[i * 2], val[i * 2 + 1]);
    }
    
    void add(int l, int r, ll v) {
        lo = l; hi = r; add(1, 1, n, v);
    }
};

vector <ii> adj[N];
ll ans = 0; bool vis[N];
int cost[N], par[N], ver[N];
int tin[N], tout[N], leaf;

void DFS(int u) {
    if (par[u]) ans += cost[u] * 2;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != par[u]) {
            par[v] = u;
            cost[v] = w; DFS(v);
            if (!tin[u]) tin[u] = tin[v];
            tout[u] = tout[v];
        }
    }
    if (!tin[u]) {
        tin[u] = tout[u] = ++leaf;
        ver[leaf] = u;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    DFS(1); segTree ST(leaf);
    for (int u = 2; u <= n; u++)
        ST.add(tin[u], tout[u], cost[u]);
    while (k--) {
        int u; ll val;
        tie(val, u) = ST.val[1];
        if (val <= 0) break;
        ans -= val; ST.add(u, u, -1e18);
        u = par[ver[u]];
        while (u > 1) {
            if (vis[u]) break;
            ST.add(tin[u], tout[u], -cost[u] * 2);
            vis[u] = true; u = par[u];
        } 
    }
    cout << ans;
}
