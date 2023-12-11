#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

struct edge {
    int u, v;
};

using ii = pair <int, int>;

const int N = 1005;
const int M = 200005;

vector <ii> adj[2][N];
edge ed[M]; int root[N], n, m;
bool vs[N]; vector <int> ext;

void dfs1(int u) {
    vs[u] = 1; int v, i;
    for (ii p : adj[0][u]) {
        tie(v, i) = p;
        if (!vs[v]) dfs1(v);
    }
    ext.push_back(u);
}

void dfs2(int u, int r) {
    root[u] = r; int v, i;
    for (ii p : adj[1][u]) {
        tie(v, i) = p;
        if (!root[v]) dfs2(v, r);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v;
        adj[0][ed[i].u].
        emplace_back(ed[i].v, i);
        adj[1][ed[i].v].
        emplace_back(ed[i].u, i);
    }
    memset(vs, 0, sizeof vs);
    for (int u = 1; u <= n; u++)
        if (!vs[u]) dfs1(u);
    reverse(ext.begin(), ext.end());
    for (int u : ext)
        if (!root[u]) dfs2(u, u);
    for (int u = 1; u <= n; u++)
        cout << root[u] << '\n';
}
