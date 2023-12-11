// Problem: F - Two Faced Edges
// Contest: AtCoder - AtCoder Regular Contest 092
// URL: https://atcoder.jp/contests/arc092/tasks/arc092_d
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

using ii = pair <int, int>;

const int N = 1005;
const int M = 200005;

vector <ii> adjList[N];
int banVer; bool visited[N];
bool answer[M], closure[N][N];
bool reachable[N];

void dfs1(int u) {
    visited[u] = true;
    for (auto edge : adjList[u]) {
        int v, i; tie(v, i) = edge;
        if (!visited[v]) dfs1(v);
    }
}

void dfs2(int u) {
    if (u == banVer) return;
    visited[u] = true;
    for (auto edge : adjList[u]) {
        int v, i; tie(v, i) = edge;
        if (!visited[v]) dfs2(v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adjList[u].eb(v, i);
    }
    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++)
            visited[v] = false;
        dfs1(u);
        for (int v = 1; v <= n; v++)
            if (visited[v])
                closure[u][v] = true;
    }
    for (int u = 1; u <= n; u++) {
        banVer = u;
        for (int v = 1; v <= n; v++) {
            visited[v] = false;
            reachable[v] = false;
        }
        for (int i = 0; i <
        int(adjList[u].size()); i++) {
            int v, j;
            tie(v, j) = adjList[u][i];
            reachable[v] |= visited[v];
            if (!visited[v]) dfs2(v);
        }
        for (int v = 1; v <= n; v++)
            visited[v] = false;
        for (int i = adjList[u].size()
        - 1; i >= 0; i--) {
            int v, j;
            tie(v, j) = adjList[u][i];
            reachable[v] |= visited[v];
            if (reachable[v]
            == closure[v][u])
                answer[j] = 1;
            if (!visited[v]) dfs2(v);
        }
        
    }
    for (int i = 0; i < m; i++)
        if (answer[i]) cout << "same\n";
        else cout << "diff\n";
}