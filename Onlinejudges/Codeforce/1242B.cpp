#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

set <int> f, g[N];

void dfs(int u) {
    f.erase(u); int v;
    for (auto it = f.begin();
    it != f.end();
    it = f.upper_bound(v))
        if (!g[u].count(v = *it))
            dfs(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    for (int i = 1; i <= n; i++)
        f.insert(i);
    int cc = -1;
    for (int i = 1; i <= n; i++)
        if (f.count(i)) {
            dfs(i); cc++;
        }
    cout << cc << '\n';
}