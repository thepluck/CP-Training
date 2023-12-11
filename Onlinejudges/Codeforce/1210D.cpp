#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector <int> adj[N];
int deg[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    long long res = 0;
    while (m--) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        adj[u].push_back(v);
        deg[u]++; deg[v]++;
    }
    for (int u = 1; u <= n; u++)
        res += adj[u].size() * (deg[u] - int(adj[u].size()));
    cout << res;
    int q; cin >> q;
    while (q--) {	
        int u; cin >> u;
        res -= adj[u].size() * (deg[u] - int(adj[u].size()));
        for (int v : adj[u]) {
            res += deg[v] - int(adj[v].size()) * 2 - 1;
            adj[v].push_back(u);
        }
        adj[u].clear();
        cout << '\n' << res;
    }
}