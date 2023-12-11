#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ii = pair <int, int>;
using ll = long long;

const int N = 1e5 + 5;
ll dp[N][4]; ll res;
vector <ii> adj[N];

/// 0 la 0 0
/// 1 la 1 1
/// 2 la 1 0
/// 3 la 0 1

void dfs(int v, int p){
    for (auto cc : adj[v]){
        int u, x; tie(u, x) = cc;
        if (u == p) continue; dfs(u, v);
        if (x){
            res += dp[v][1] * (dp[u][1] + 1 + dp[u][2] + dp[u][0]);
            res += dp[v][0] * (dp[u][1] + 1);
            res += dp[v][2] * (dp[u][1] + 1);
            dp[v][1] += dp[u][1] + 1;
            dp[v][2] += dp[u][0] + dp[u][2];
        }
        else {
            res += dp[v][0] * (dp[u][0] + 1 + dp[u][3] + dp[u][1]);
            res += dp[v][1] * (dp[u][0] + 1);
            res += dp[v][3] * (dp[u][0] + 1);
            dp[v][0] += dp[u][0] + 1;
            dp[v][3] += dp[u][1] + dp[u][3];
        }
    }
    res += dp[v][0] + dp[v][1] + dp[v][2] + dp[v][3];
}

int main(){
    freopen("path01.inp", "r", stdin);
    freopen("path01.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v, x; i < n; i++){
        cin >> u >> v >> x;
        adj[u].eb(v, x); adj[v].eb(u, x);
    }
    dfs(1, 0); cout << res << '\n';
}