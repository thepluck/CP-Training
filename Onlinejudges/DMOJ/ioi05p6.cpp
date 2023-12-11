
// Problem : IOI '05 P6 - Rivers
// Contest : DMOJ
// URL : https://dmoj.ca/problem/ioi05p6
// Memory Limit : 32 MB
// Time Limit : 600 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 101;
const int K = 51;

ll dp[N][N][K], f[N][N][K], g[N][K];
int n, k, d[N], t[N], w[N], p[N];
vector <int> adj[N];

void dfs(int u) {
    for (int j = 0; j <= d[u]; j++)
        for (int x = 0; x <= k; x++)
            f[0][j][x] = 0;
    for (int x = 0; x <= k; x++)
        g[0][x] = 0;
    for (int i = 1; i <= adj[u].size(); i++) {
        int v = adj[u][i - 1];
        d[v] = d[u] + 1; dfs(v);
        for (int j = 0; j <= d[u]; j++) {
            for (int x = 0; x <= k; x++) {
                f[i][j][x] = f[i - 1][j][x] + dp[v][j][0];
                for (int y = 1; y <= x; y++)
                    cmin(f[i][j][x], f[i - 1][j][x - y] + dp[v][j][y]);
            }
        }
        for (int x = 0; x < k; x++) {
            g[i][x] = g[i - 1][x] + dp[v][d[u]][0];
            for (int y = 1; y <= x; y++)
                cmin(g[i][x], g[i - 1][x - y] + dp[v][d[u]][y]);
        }
    }
    ll dis = 0; int par = u;
    for (int j = d[u]; ~j; j--) {
        for (int x = 0; x <= k; x++)
            dp[u][j][x] = dis * t[u] + f[adj[u].size()][j][x];
        for (int x = 1; x <= k; x++)
            cmin(dp[u][j][x], g[adj[u].size()][x - 1]);
        dis += w[par]; par = p[par];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i] >> w[i];
        adj[p[i]].push_back(i);
    }
    dfs(0); cout << dp[0][0][k] << '\n';
}