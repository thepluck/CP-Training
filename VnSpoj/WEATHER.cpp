#include <bits/stdc++.h>
using namespace std;

int num[105], low[105], siz[105], trace[105];
vector <int> adj[105]; int color, ans, n;

void dfs(int u){
    siz[u] = 1; low[u] = num[u] = ++color;
    for (int v : adj[u])
        if (num[v] == 0){
            trace[v] = u; dfs(v); siz[u] += siz[v];
            if (low[v] > num[u]){
                ans += siz[v] * (n - siz[v]);
            }
            low[u] = min(low[u], low[v]);
        }
        else if (v != trace[u])
            low[u] = min(low[u], num[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, u, v; cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (num[i] == 0) dfs(i);
    cout << ans << '\n';
}