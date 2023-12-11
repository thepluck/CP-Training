#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

const int N = 1e5 + 5;
ll dp[N], res; int sz[N];
vector <int> adj[N];

void dfs(int u, int p){
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p){
            dfs(v, u);
            res += dp[u] * sz[v] + (dp[v] + sz[v]) * sz[u];
            dp[u] += dp[v] + sz[v]; sz[u] += sz[v];
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("sumdistree.inp", "r", stdin);
    freopen("sumdistree.out", "w", stdout);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1, 0); cout << res << '\n';
}