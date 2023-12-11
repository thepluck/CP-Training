// Problem: E - Attack to a Tree
// Contest: AtCoder - AISing Programming Contest 2019
// URL: https://atcoder.jp/contests/aising2019/tasks/aising2019_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dp[N][N][2], tmp[N][2];
int a[N], sz[N];
vector <int> adj[N];

void dfs(int u, int p) {
    memset(dp[u], 0x3f, sizeof dp[u]);
    dp[u][0][a[u] < 0] = a[u];
    for (int v : adj[u]) {
        if (v == p) continue; dfs(v, u);
        memset(tmp, 0x3f, sizeof tmp);
        for (int i = 0; i <= sz[u]; i++)
            for (int j = 0; j <= sz[v]; j++) {
                if (dp[u][i][0] < INF) {
                    if (dp[v][j][0] < INF)
                        cmin(tmp[i + j][0],
                        dp[u][i][0] + dp[v][j][0]);
                    if (dp[v][j][1] < INF)
                        cmin(tmp[i + j][1],
                        dp[u][i][0] + dp[v][j][1]);
                }
                if (dp[u][i][1] < INF) {
                    if (dp[v][j][0] < INF)
                        cmin(tmp[i + j][1],
                        dp[u][i][1] + dp[v][j][0]);
                    if (dp[v][j][1] < INF)
                        cmin(tmp[i + j][1],
                        dp[u][i][1] + dp[v][j][1]);
                }
            }
        sz[u] += sz[v];
        for (int i = 0; i <= sz[u]; i++) {
            dp[u][i][0] = tmp[i][0];
            dp[u][i][1] = tmp[i][1];
        }
    }
    for (int i = sz[u]; i >= 0; i--) {
        if (dp[u][i][0] < INF)
            cmin(dp[u][i + 1][0], 0);
        if (dp[u][i][1] < 0)
            cmin(dp[u][i + 1][0], 0);
    }
    sz[u]++;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        if (dp[1][i][0] == 0)
            return cout << i - 1, 0;
}