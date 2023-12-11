#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge{
    int v; ll w;
};

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll dp[N], res; 
vector <edge> adj[N];

void dfs(int v, int p){
    dp[v] = 1;
    for (auto e : adj[v]) 
        if (e.v != p){
            dfs(e.v, v);
            res = (res + dp[e.v] * e.w % mod * dp[v] % mod) % mod;
            dp[v] = (dp[v] + dp[e.v] * e.w % mod) % mod;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0); cout << res << '\n';
}