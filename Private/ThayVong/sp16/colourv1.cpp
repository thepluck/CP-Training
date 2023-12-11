#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

const ll ninf = -1e17;
const int N = 1e5 + 5;
ll a[N], dp[N][3], res = ninf;
vector <int> adj[N];

void dfs(int u, int p){
    dp[u][1] = dp[u][2] = ninf;
    for (int v : adj[u]){
        if (v == p) continue; dfs(v, u);
        res = max(res, dp[u][0] + dp[v][0] - a[u] - a[v]);
        res = max(res, dp[u][0] + dp[v][1] - a[v]);
        res = max(res, dp[u][0] + dp[v][2]);
        res = max(res, dp[u][1] + dp[v][0] - a[u]);
        res = max(res, dp[u][1] + max(dp[v][1], dp[v][2]));
        res = max(res, dp[u][2] + max({dp[v][0], dp[v][1], dp[v][2]}));
        dp[u][1] = max(dp[u][1], dp[v][0]);
        dp[u][2] = max({dp[u][2], dp[v][2], dp[v][1]});
    }
}

int main(){
    freopen("colourv1.inp", "r", stdin);
    freopen("colourv1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i]; dp[i][0] = a[i];
    }
    for (int u = 1; u <= n; u++)
        for (int v : adj[u]) dp[u][0] += a[v];
    dfs(1, 0); cout << res << '\n';
}