#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int LG = 18;

struct edge {int u, v, w;};

int anc[LG][N], dep[N];
long long stat[LG][N]; edge lst[N];
int par[N], ls[N], rs[N], val[N];

int Find(int u) {
    return u == par[u] ? u : par[u] = Find(par[u]);
}

void DFS(int u) {
    dep[u] = dep[anc[0][u]] + 1;
    if (ls[u]) {
        anc[0][ls[u]] = anc[0][rs[u]] = u;
        DFS(ls[u]); DFS(rs[u]);
        stat[0][u] = stat[0][ls[u]] + stat[0][rs[u]];
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG - 1; k >= 0; k--)
        if (dep[anc[k][u]] >= dep[v])
            u = anc[k][u];
    if (u == v) return u;
    for (int k = LG - 1; k >= 0; k--)
        if (anc[k][u] != anc[k][v]) {
            u = anc[k][u]; v = anc[k][v];
        }
    return anc[0][u];
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> stat[0][i];
    for (int i = 0; i < m; i++)
        cin >> lst[i].u >> lst[i].v >> lst[i].w;
    sort(lst, lst + m,
    [](const edge &p, const edge &q) {
        return p.w < q.w;
    });
    for (int i = 1; i < 2 * n; i++) {
        val[i] = ls[i] = rs[i] = 0; par[i] = i;
        for (int k = 0; k < LG; k++)
            anc[k][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u = Find(lst[i].u), v = Find(lst[i].v);
        if (u != v) {
            val[par[u] = par[v] = ++n] = lst[i].w;
            ls[n] = u; rs[n] = v;
        }
    }
    for (int i = 1; i <= n; i++)
        if (par[i] == i) DFS(i);
    for (int i = 1; i <= n; i++) {
        stat[0][i] = -stat[0][i] + val[anc[0][i]];
        if (stat[0][i] < 0) stat[0][i] = 0;
    }
    for (int k = 1; k < LG; k++) {
        for (int i = 1; i <= n; i++) {
            anc[k][i] = anc[k - 1][anc[k - 1][i]];
            stat[k][i] = max(stat[k - 1][i],
            stat[k - 1][anc[k - 1][i]]);
        }
    }
    int q; cin >> q;
    while (q--) {
        int u, v; long long res = 0;
        cin >> u >> v;
        if (Find(u) != Find(v)) {
            cout << "-1\n"; continue;
        }
        int r = LCA(u, v);
        for (int k = LG - 1; k >= 0; k--)
            if (dep[anc[k][u]] >= dep[r]) {
                res = max(res, stat[k][u]);
                u = anc[k][u];
            }
        cout << res << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}