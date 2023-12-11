#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second
const int N = 1e5 + 5;
int dis[N]; long long res = 0;
vector <int> adj[N];

void dfs(int u, int p){
    for (int v : adj[u])
        if (v != p){
            dis[v] = dis[u] + 1;
            dfs(v, u);
        }
}

int main(){
    freopen("sumdisv1.inp", "r", stdin);
    freopen("sumdisv1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1, 0);
    cout << accumulate(dis + 1, dis + n + 1, 0ll) << '\n';
}