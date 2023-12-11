#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int deg[N];
vector <int> adj[N], leaf;

void dfs(int u, int p){
    if (deg[u] == 1)
        leaf.push_back(u);
    for (int v : adj[u])
        if (v != p) dfs(v, u);
}

int main(){
    //freopen("kingdom.in", "r", stdin);
    //freopen("kingdom.out", "w", stdout);
    freopen("kingdom.err", "w", stderr);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        deg[u]++; deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int res = (leaf.size() + 1) / 2;
    cout << res << '\n';
    for (int i = 0; i < leaf.size() / 2; i++)
        cout << leaf[i] << ' ' << leaf[res + i] << '\n';
    if (leaf.size() & 1)
        cout << leaf[leaf.size() / 2] << " 1\n";
    cerr << 3;
}