// Problem: C. Vasya and Maximum Matching
// Contest: Codeforces - Codeforces Round #522 (Div. 1, based on Technocup 2019 Elimination Round 3)
// URL: https://codeforces.com/problemset/problem/1078/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 300005;

int dp[N][3];
vector <int> adj[N];

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

void dfs(int u, int p) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        dp[u][2] = add(mul(dp[u][2],
        add(dp[v][1], mul(dp[v][2], 2))),
        mul(dp[u][0], dp[v][0]));
        dp[u][1] = mul(dp[u][1],
        add(dp[v][1], dp[v][2]));
        dp[u][0] = mul(dp[u][0],
        add(dp[v][1], mul(dp[v][2], 2)));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << add(dp[1][1], dp[1][2]);
}