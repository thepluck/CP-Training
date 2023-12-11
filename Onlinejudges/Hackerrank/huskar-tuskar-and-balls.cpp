
// Problem : Huskar, Tuskar, and Balls
// Contest : HackerRank
// URL : https://www.hackerrank.com/contests/w15/challenges/huskar-tuskar-and-balls
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LG = 18;

int p[LG][N], d[N];
vector <int> g[N];	

void bfs() {
    queue <int> q; d[1] = 1; q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            d[v] = d[u] + 1; q.push(v);
        }
    }
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    for (int k = LG - 1; ~k; k--)
        if (d[p[k][u]] >= d[v])
            u = p[k][u];
    if (u == v) return u;
    for (int k = LG - 1; ~k; k--)
        if (p[k][u] != p[k][v]) {
            u = p[k][u]; v = p[k][v];
        }
    return p[0][u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> p[0][i];
        g[p[0][i]].push_back(i);
    }
    bfs(); d[0] = 0;
    for (int k = 1; k < LG; k++)
        for (int u = 1; u <= n; u++)
            p[k][u] = p[k - 1][p[k - 1][u]];
    while (q--) {
        int u, v; cin >> u >> v;
        cout << d[u] << ' ';
        cout << d[v] - d[lca(u, v)] << '\n';
    }
}
