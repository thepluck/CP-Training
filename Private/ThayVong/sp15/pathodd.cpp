#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int res = 0, n, k;
vector <int> adj[N];

void dfs(int u, int p, int l, int o){
    res = max(res, o);
    if (l == k) return;
    for (int v : adj[u]) if (v != p)
        dfs(v, u, l + 1, o + (v & 1));
}

int main(){
    freopen("pathodd.inp", "r", stdin);
    freopen("pathodd.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0, 1); cout << res << '\n';
}