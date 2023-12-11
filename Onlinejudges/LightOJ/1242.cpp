#include <bits/stdc++.h>
using namespace std;

struct hopcroft_karp {
    vector <vector <int>> g;
    vector <int> x, y, d;
    int n, m; queue <int> q;

    hopcroft_karp(int n = 0, int m = 0) {
        this->n = n; this->m = m;
        g.assign(n + 5, vector <int> ());
        x.assign(n + 5, 0);
        y.assign(m + 5, 0);
        d.assign(n + 5, 0);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
    }

    bool bfs() {
        for (int u = 1; u <= n; u++)
            if (!x[u]) {
                d[u] = 0; q.emplace(u);
            }
            else d[u] = -1;
        bool flag = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (!y[v]) flag = true;
                else if (d[y[v]] < 0) {
                    d[y[v]] = d[u] + 1;
                    q.emplace(y[v]);
                }
            }
        }
        return flag;
    }

    bool dfs(int u) {
        for (int v : g[u])
            if (!y[v] || (d[y[v]] ==
            d[u] + 1 && dfs(y[v]))) {
                x[u] = v; y[v] = u;
                return true;
            }
        d[u] = -1; return false;
    }

    int max_matching() {
        int tot = 0;
        while (bfs())
            for (int u = 1; u <= n; u++)
                if (!x[u]) tot += dfs(u);
        return tot;
    }
};

const int N = 105;

bool vs[2][N]; int n, m;
vector <int> adj[2][N];

bool match(int u, int x) {
    vs[0][u] = vs[1][x] = 1;
    hopcroft_karp dev(
    adj[0][u].size(), adj[1][x].size());
    for (int i = 0; i < adj[0][u].size(); i++) {
        int v = adj[0][u][i];
        if (vs[0][v]) continue;
        for (int j = 0; j < adj[1][x].size(); j++) {
            int y = adj[1][x][j];
            if (vs[1][y]) continue;
            if (match(v, y))
                dev.add_edge(i + 1, j + 1);
        }
    }
    vs[0][u] = vs[1][x] = 0;
    int cnt = adj[0][u].size() - (u != 1);
    int mat = dev.max_matching();
    return mat == cnt;
}

void process() {
    cin >> m;
    for (int i = 1; i <= m; i++)
        adj[1][i].clear();
    for (int i = 1; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[1][u].push_back(v);
        adj[1][v].push_back(u);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
        adj[0][i].clear();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[0][u].push_back(v);
        adj[0][v].push_back(u);
    }
    cout << (match(1, 1) ? "Yes\n" : "No\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        process();
    }
}