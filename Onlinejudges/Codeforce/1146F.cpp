#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 200005;
const int MOD = 998244353;

ll dp[N][2];
vector <int> adj[N];

void dfs(int u) {
    ll cnt[2], tot;
    cnt[0] = tot = 1; cnt[1] = 0;
    for (int v : adj[u]) {
        dfs(v);
        cnt[1] = (cnt[1] * dp[v][0] + cnt[0] * dp[v][1]) % MOD;
        cnt[0] = cnt[0] * dp[v][0] % MOD;
        tot = tot * (dp[v][0] + dp[v][1]) % MOD;
    }
    dp[u][0] = (tot - cnt[1] + MOD) % MOD;
    dp[u][1] = (tot - cnt[0] + MOD) % MOD;
    if (adj[u].empty()) dp[u][1] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int j; cin >> j;
        adj[j].push_back(i);
    }
    dfs(1); cout << dp[1][0] << '\n';
}