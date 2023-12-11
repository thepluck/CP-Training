#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 5e5 + 5;

int par[N], dsu[N], val[N];
int fu[N], fv[N], fw[N];
int gu[N], gv[N], dep[N];
vector <int> adj[N];

int fin(int u) {
    return dsu[u] == u ?
    u : dsu[u] = fin(dsu[u]);
}

bool mer(int u, int v) {
    u = fin(u); v = fin(v);
    if (u == v) return 0;
    dsu[v] = u; return 1;
}

void dfs(int u, int p = 0) {
    for (int v : adj[u])
        if (v != p) {
            dep[v] = dep[u] + 1;
            par[v] = u; dfs(v, u);
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
    for (int i = 1; i <= k; i++) {
        cin >> gu[i] >> gv[i];
        adj[gu[i]].eb(gv[i]);
        adj[gv[i]].eb(gu[i]);
        mer(gu[i], gv[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> fu[i] >> fv[i] >> fw[i];
        if (mer(fu[i], fv[i])) {
            adj[fu[i]].eb(fv[i]);
            adj[fv[i]].eb(fu[i]);
        }
    }
    dfs(1); long long res = 0;
    for (int i = 1; i <= n; i++)
        dsu[i] = i;
    for (int i = 1; i <= m; i++) {
        int u = fin(fu[i]);
        int v = fin(fv[i]);
        while (u != v) {
            
            if (dep[u] < dep[v])
                swap(u, v);
            val[u] = fw[i];
            dsu[u] = par[u];
            u = fin(u);
        }
    }
    for (int i = 1; i <= k; i++) {
        int u = gu[i], v = gv[i];
        if (dep[u] < dep[v])
            swap(u, v);
        if (!val[u]) {
            cout << "-1\n"; return 0;
        }
        res += val[u];
    }
    cout << res << '\n';
}