#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
    int u, v; ll w;
};

const int N = 5e5 + 5;
const int LG = 20;

int p[LG][N], a[N];
vector <int> g[N]; ll e[N];

void dfs(int u) {
    for (const int &v : g[u])
        if (v != p[0][u]) {
            p[0][v] = u; dfs(v);
        }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n, r = 1; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; e[i] = LLONG_MAX;
        if (a[i] < a[r]) r = i;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(r); ll tot = 0;
    for (int k = 1; k < LG; k++)
        for (int u = 1; u <= n; u++)
            p[k][u] = p[k - 1][p[k - 1][u]];
    for (int k = 0; k < LG; k++)
        for (int u = 1; u <= n; u++) {
            if (u == r) continue;
            if (p[k][u])
                e[u] = min(e[u], ll(k + 1)
                * a[p[k][u]] + a[u]);
            else e[u] = min(e[u],
            ll(k + 1) * a[r] + a[u]);
        }
    for (int i = 1; i <= n; i++)
        if (i != r) tot += e[i];
    cout << tot << '\n';
}