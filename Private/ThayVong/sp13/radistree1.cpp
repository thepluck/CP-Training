#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
const int N = 1e5 + 5;
vector <int> adj[N];
int res, id, n;

void dfs(int u, int p, int k){
    if (res < k){
        res = k; id = u;
    }
    for (int v : adj[u]) if (v != p)
        dfs(v, u, k + 1);
}

int main(){
    freopen("radistree1.inp", "r", stdin);
    freopen("radistree1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n; int u, v;
    for (int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1, 0, 0); dfs(id, 0, 0);
    cout << res << '\n';
}