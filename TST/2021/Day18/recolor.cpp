#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector <int> adj[N];
int col[N];

int calc(int u) {
    if (col[u]) return col[u];
    for (int v : adj[u])
        col[u] = max(col[u], calc(v));
    return ++col[u];
}

void DFS(int u) {
    cout << u << ' ';
    for (int v : adj[u])
        if (col[u] == col[v] + 1) {
            DFS(v); return;
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k, root = 1;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> col[i];
    while (m--) {
        int u, v; cin >> u >> v;
        if (col[u] < col[v])
            adj[u].push_back(v);
        else adj[v].push_back(u);
    }
    memset(col, 0, sizeof col);
    for (int u = 1; u <= n; u++)
        calc(u);
    for (int u = 1; u <= n; u++)
        if (col[u] > col[root])
            root = u;
    cout << col[root];
    for (int u = 1; u <= n; u++)
        cout << ' ' << col[u];
    cout << '\n'; DFS(root);
}