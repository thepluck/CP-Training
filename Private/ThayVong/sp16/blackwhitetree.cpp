#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

const int N = 1e5 + 5;
ll dp[N][3], res; int c[N];
vector <int> adj[N];

void dfs(int u, int p){
    dp[u][c[u]]++;
    for (int v : adj[u]){
        if (v == p) continue; dfs(v, u);
        res += dp[u][0] * (dp[v][1] + dp[v][2]);
        res += dp[u][1] * (dp[v][0] + dp[v][2]);
        res += dp[u][2] * (dp[v][0] + dp[v][1] + dp[v][2]);
        dp[u][2] += dp[v][2] + dp[v][c[u] ^ 1];
        dp[u][c[u]] += dp[v][c[u]];
    }
}

int main(){
    freopen("blackwhitetree.inp", "r", stdin);
    freopen("blackwhitetree.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 1; i <= n; cin >> c[i++]);
    dfs(1, 0); cout << res << '\n';
}