#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

long long dp[N][N];
int par[N][N], siz[N][N];
vector<int> adj[N];

void dfs(int u, int r) {
    siz[r][u] = 1;
    for (int v : adj[u])
        if (v != par[r][u]) {
            par[r][v] = u; dfs(v, r);
            siz[r][u] += siz[r][v];
        }
}

long long rec(int u, int v) {
    long long &res = dp[u][v];
    if (res >= 0) return res;
    if (u == v) return res = 0;
    return res = max(rec(u, par[u][v]), rec
    (par[v][u], v)) + siz[u][v] * siz[v][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, i);
    memset(dp, -1, sizeof dp);
    long long res = 0;
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            res = max(res, rec(u, v));
    cout << res;
}