#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

const int N = 3e5 + 5;
vector <int> adj[N];
int c[N]; ll dp[N][2];

void dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    if (c[u]) {
        dp[u][1] = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            dp[u][1] += dp[v][0];
        }
        dp[u][0] = N;
    }
    else {
        ll sum[2];
        sum[0] = 1; sum[1] = 0;
        for (int v : adj[u]) {
            if (v == p) continue;
            sum[0] += min(dp[v][0], dp[v][1]);
            sum[1] += dp[v][0];
        }
        dp[u][1] = N;
        for (int v : adj[u]) {
            if (v == p) continue;
            dp[u][1] = min(dp[u][1],
            sum[1] + dp[v][1] - dp[v][0]);
        }
        dp[u][0] = min(sum[0], sum[1]);
    }
}

int main() {
    freopen("dienbien.inp", "r", stdin);
    freopen("dienbien.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n;
    while (cin >> n >> k) {
        if (n == -1) return 0;
        while (k--) {
            int u; cin >> u; c[u] = 1;
        }
        bool flag = 0;
        for (int i = 1; i < n; i++) {
            int u, v; cin >> u >> v;
            adj[u].eb(v); adj[v].eb(u);
            if (c[u] && c[v]) flag = 1;
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++) {
            adj[i].clear(); c[i] = 0;
        }
        if (flag) cout << "-1\n";
        else cout << min(dp[1][0], dp[1][1]) << '\n';
    }
}
