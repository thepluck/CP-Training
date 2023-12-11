#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

struct edge{
    int v, w;

    edge(int v, int w): v(v), w(w){}
};

const int N = 1e5 + 5;
ll dp[N], res; int sz[N];
vector <edge> adj[N];

void dfs(int u, int p){
    sz[u] = 1;
    for (auto e : adj[u]){
        if (e.v == p) continue; dfs(e.v, u);
        res += dp[u] * sz[e.v] + dp[e.v] * sz[u] +
                        1ll * sz[u] * sz[e.v] * e.w;
        dp[u] += dp[e.v] + 1ll * sz[e.v] * e.w;
        sz[u] += sz[e.v];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        adj[u].eb(v, w); adj[v].eb(u, w);
    }
    dfs(0, -1); cout << res << '\n';
}