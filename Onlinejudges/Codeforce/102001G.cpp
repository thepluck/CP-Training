#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int deg[N], mx[N], a[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, res = INT_MAX;
    cin >> n >> m; deg[0] = -1;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        a[u][v] = a[v][u] = 1;
    }
    for (int u = 1; u <= n; u++) a[u][u] = 1;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            if (!a[u][v] && deg[v] > deg[mx[u]])
                mx[u] = v;
    while (true) {
        int u, v, best = -1;
        for (int x = 1; x <= n; x++)
            if (mx[x] && deg[x] + deg[mx[x]] > best) {
                u = x; v = mx[x];
                best = deg[x] + deg[mx[x]];
            }
        if (best == -1) break;
        res = min(res, deg[u] + deg[v]);
        mx[u] = mx[v] = 0;
        a[u][v] = a[v][u] = 1;
        deg[u]++; deg[v]++;
        for (int x = 1; x <= n; x++)
            if (!a[u][x] && deg[x] > deg[mx[u]])
                mx[u] = x;
        for (int x = 1; x <= n; x++)
            if (!a[v][x] && deg[x] > deg[mx[v]])
                mx[v] = x;
    }
    cout << res << '\n';
}