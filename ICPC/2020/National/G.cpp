#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1e5 + 5;
const int V = 5e5 + 5;
const int LG = 17;

vector <int> divs[V], vers[V], cur;
vector <pair <int, int>> adj[N];
int rmq[LG][N], tin[N], tim; ll dep[N];
int n, tour[N], m, lg[N]; bool occ[V];

void dfs(int u, int p = 0) {
    tin[u] = tim++;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != p) {
            tour[m] = u;
            rmq[0][m++] = tin[u];
            dep[v] = dep[u] + w;
            dfs(v, u);
        }
    }
}

void prepare() {
    for (int i = 1; i < V; i++)
        for (int j = i; j < V; j += i)
            divs[j].emplace_back(i);
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
}

void init_lca() {
    for (int k = 1; k < LG; k++)
        for (int i = 0; i + (1 << k) <= m; i++)
            rmq[k][i] = min(rmq[k - 1][i],
            rmq[k - 1][i + (1 << (k - 1))]);
}

int lca(int u, int v) {
    if (u == v) return u;
    tie(u, v) = minmax(tin[u], tin[v]);
    return tour[min(rmq[lg[v - u]][u],
    rmq[lg[v - u]][v - (1 << lg[v - u])])];
}

ll dis(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

ll diam(int d) {
    int u = vers[d].front(), v = u;
    for (int w : vers[d])
        if (dis(u, w) > dis(u, v)) v = w;
    u = v;
    for (int w : vers[d])
        if (dis(v, w) > dis(v, u)) u = w;
    return dis(v, u);
}

void solve() {
    if (n == 0) return;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        for (int d : divs[x]) {
            vers[d].emplace_back(i);
            if (!occ[d])
                cur.emplace_back(d);
            occ[d] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1); init_lca(); ll res = 0;
    for (int d : cur)
        res = max(res, diam(d) * d);
    cout << res << '\n';
    for (int d : cur) {
        vers[d].clear(); occ[d] = 0;
    }
    cur.clear(); tim = 0; m = 0;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    prepare();
    while (cin >> n) solve();
}