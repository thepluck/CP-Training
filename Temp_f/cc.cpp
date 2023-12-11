#include <bits/stdc++.h>

using namespace std;

struct HopcroftKarp {
    vector <int> dis, mat;
    vector <char> vis; int n, m;
    queue <int> que;
    vector <vector <int>> adj;
    
    HopcroftKarp(int n, int m):
    n(n), m(m), adj(n + 1), dis(n + 1),
    vis(n + 1), mat(m + 1) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    bool BFS() {
        for (int u = 1; u <= n; u++)
            if (!vis[u]) {
                dis[u] = 0; que.push(u);
            }
            else dis[u] = -1;
        bool flag = false;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u])
                if (!mat[v]) flag = true;
                else if (dis[mat[v]] < 0) {
                    dis[mat[v]] = dis[u] + 1;
                    que.push(mat[v]);
                }
        }
        return flag;
    }
    
    bool DFS(int u) {
        for (int v : adj[u])
            if (!mat[v] || (dis[mat[v]] ==
            dis[u] + 1 && DFS(mat[v]))) {
                mat[v] = u; vis[u] = true;
                return true;
            }
        dis[u] = -1; return false;
    }
    
    int maxMatch() {
        int match = 0;
        while (BFS())
            for (int u = 1; u <= n; u++)
                if (!vis[u]) match += DFS(u);
        return match;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector <vector <char>> con(
    n + 1, vector <char> (n + 1));
    vector <vector <int>> adj(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        adj[u + 1].push_back(v + 1);
    }
    queue <int> que;
    for (int i = 1; i <= n; i++) {
        que.push(i); con[i][i] = true;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u])
                if (!con[i][v]) {
                    con[i][v] = true;
                    que.push(v);
                }
        }
    }
    HopcroftKarp mat(n, n);
    for (int u = 1; u <= n; u++)
        for (int v = 1; v <= n; v++)
            if (con[u][v] && !con[v][u])
                mat.addEdge(u, v);
    cout << n - mat.maxMatch() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}