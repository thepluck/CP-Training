#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
const int N = 200005;
 
vector <int> adj[N];
bool vis[N];
 
void DFS(int u, int &cnt) {
    cnt++; vis[u] = true;
    for (int v : adj[u])
        if (!vis[v]) DFS(v, cnt);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            adj[i].clear(); vis[i] = false;
        }
        ll tmp = ll(n) * (n - 1) / 2 - m;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (n & 1) {
            if (tmp & 1)
                cout << "Kien\n";
            else cout << "The\n";
            continue;
        }
        int cnt1 = 0, cntn = 0;
        DFS(1, cnt1); DFS(n, cntn);
        if ((cnt1 ^ cntn) & 1)
            cout << "Kien\n";
        else if ((tmp - ll(cnt1) * cntn) & 1)
            cout << "Kien\n";
        else cout << "The\n";
        
    }
}