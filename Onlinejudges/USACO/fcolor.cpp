
// Problem : Problem 2. Favorite Colors
// Contest : USACO - USACO 2020 US Open Contest, Gold
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=1042
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

vector <int> g[N];
int p[N], c[N];
queue <int> q;

int fin(int u) {
    return p[u] == u ?
    u : p[u] = fin(p[u]);
}

void mer(int u, int v) {
    u = fin(u); v = fin(v);
    if (u == v) return;
    if (g[u].size() < g[v].size())
        swap(u, v);
    for (int x : g[v])
        g[u].push_back(x);
    g[v].clear(); p[v] = u;
    g[v].shrink_to_fit();
    if (g[u].size() > 1)
        q.push(u);
}

int main() {
    freopen("fcolor.in", "r", stdin);
    freopen("fcolor.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 1)
            q.push(i);
        p[i] = i;
    }
    while (!q.empty()) {
        int u = q.front();
        if (g[u].size() < 2) {
            q.pop(); continue;
        }
        int x = g[u].back();
        g[u].pop_back();
        mer(x, g[u].back());
    }
    int col = 0;
    for (int i = 1; i <= n; i++) {
        if (!c[fin(i)])
            c[fin(i)] = ++col;
        cout << c[fin(i)] << '\n';
    }
}