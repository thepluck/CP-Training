// Problem: F. Up and Down the Tree
// Contest: Codeforces - Educational Codeforces Round 52 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1065/problem/F
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int dp[N][2], d[N], n, k;
vector <int> adj[N]; int res;

void dfs(int u) {
    if (adj[u].empty()) {
        dp[u][0] = dp[u][1] = 1; return;
    }
    d[u] = n + 1; int mx = 0;
    for (int v : adj[u]) {
        dfs(v); d[u] = min(d[u], d[v] + 1);
        if (d[v] < k) {
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][0];
            mx = max(mx, dp[v][1] - dp[v][0]);
        }
        else mx = max(mx, dp[v][1]);
    }
    dp[u][1] += mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    dfs(1); cout << dp[1][1] << '\n';
}