#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back

using ii = pair <int, int>;

struct edge {
    int u, v, w;
};

const int N = 2e5 + 5;
const int LG = 19;
const int inf = 0x3f3f3f3f;

edge ed[N]; bool in_mst[N];
vector <ii> adj[N], mst[N];
int p[LG][N], mx[LG][N], ord[N];
int d[N], ans[N], pred[N];

struct dsu {
    int p[N];

    void reset() {
        iota(p, p + N, 0);
    }

    dsu() {
        iota(p, p + N, 0);
    }

    int find(int u) {
        return u == p[u] ?
        u : p[u] = find(p[u]);
    }

    bool merge(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return 0;
        p[v] = u; return 1;
    }
} ds;

void dfs(int u) {
    for (ii pp : mst[u]) {
        int v, i; tie(v, i) = pp;
        if (v == p[0][u]) continue;
        p[0][v] = u; d[v] = d[u] + 1;
        mx[0][v] = ed[i].w;
        pred[v] = i; dfs(v);
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int k = LG - 1; ~k; k--)
        if (d[p[k][u]] >= d[v])
            u = p[k][u];
    if (u == v) return u;
    for (int k = LG - 1; ~k; k--)
        if (p[k][u] != p[k][v]) {
            u = p[k][u]; v = p[k][v];
        }
    return p[0][u];
}

int maxe(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int res = 0;
    for (int k = LG - 1; ~k; k--)
        if (d[p[k][u]] >= d[v]) {
            res = max(res, mx[k][u]);
            u = p[k][u];
        }
    if (u == v) return res;
    for (int k = LG - 1; ~k; k--)
        if (p[k][u] != p[k][v]) {
            res = max(res, mx[k][u]);
            res = max(res, mx[k][v]);
            u = p[k][u]; v = p[k][v];
        }
    res = max(res, mx[0][u]);
    res = max(res, mx[0][v]);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    memset(ans, 0, sizeof ans);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> ed[i].u >> ed[i].v;
        cin >> ed[i].w;
        adj[ed[i].u].eb(ed[i].v, i);
        adj[ed[i].v].eb(ed[i].u, i);
    }
    ed[m].w = inf;
    iota(ord, ord + m, 0);
    sort(ord, ord + m,
    [&](int i, int j) {
        return ed[i].w < ed[j].w;
    });
    /// kruskal
    for (int i = 0; i < m; i++) {
        int j = ord[i];
        if (ds.merge(ed[j].u, ed[j].v)) {
            mst[ed[j].u].eb(ed[j].v, j);
            mst[ed[j].v].eb(ed[j].u, j);
            in_mst[j] = 1;
        }
    }
    dfs(1);
    /// prepare sparse table
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++) {
            p[k][i] = p[k - 1][p[k - 1][i]];
            mx[k][i] = max(mx[k - 1][i],
                mx[k - 1][p[k - 1][i]]);
        }
    ds.reset();
    for (int i = 0; i < m; i++) {
        /// non-mst edge
        int j = ord[i];
        if (in_mst[j]) continue;
        ans[j] = maxe(ed[j].u, ed[j].v);
        int r = lca(ed[j].u, ed[j].v);
        int u = ds.find(ed[j].u);
        while (d[u] > d[r]) {
            ans[pred[u]] = ed[j].w;
            ds.p[u] = p[0][u];
            u = ds.find(u);
        }
        u = ds.find(ed[j].v);
        while (d[u] > d[r]) {
            ans[pred[u]] = ed[j].w;
            ds.p[u] = p[0][u];
            u = ds.find(u);
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] - 1 << ' ';
}
