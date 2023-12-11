#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1e5 + 5;

vector <int> adj[N];
int low[N], num[N], tim, bri, cut;

void dfs(int u, int p = 0) {
    low[u] = num[u] = ++tim;
    bool ok = 0; int cnt = 0;
    for (int v : adj[u])
        if (!num[v]) {
            dfs(v, u); cnt++;
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) bri++;
            if (low[v] >= num[u]) ok = 1;
        }
        else if (v != p)
            low[u] = min(low[u], num[v]);
    if (!p) {
        if (cnt > 1) cut++;
    }
    else if (ok) cut++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i);
    cout << cut << ' ' << bri << '\n';
}
