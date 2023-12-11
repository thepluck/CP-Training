#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 1e5 + 5;

struct edge {
    int u, v;
} ed[3][M];

int p[N], c[3];

int fin(int u) {
    return u == p[u] ?
    u : p[u] = fin(p[u]);
}

bool mer(int u, int v) {
    u = fin(u); v = fin(v);
    if (u == v) return 0;
    p[v] = u; return 1;
}

int main() {
    freopen("mrg.inp", "r", stdin);
    freopen("mrg.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t; t--;
        ed[t][c[t]++] = {u, v};
    }
    iota(p + 1, p + n + 1, 1);
    int res = 0;
    for (int i = 0; i < c[1]; i++)
        res += mer(ed[1][i].u, ed[1][i].v);
    for (int i = 0; i < c[0]; i++)
        res += mer(ed[0][i].u, ed[0][i].v);
    
    for (int i = 1; i <= n; i++)
        if (fin(1) != fin(i)) {
            cout << "-1\n"; return 0;
        }
    iota(p + 1, p + n + 1, 1);
    for (int i = 0; i < c[1]; i++)
        mer(ed[1][i].u, ed[1][i].v);
    for (int i = 0; i < c[2]; i++)
        res += mer(ed[2][i].u, ed[2][i].v);
    for (int i = 1; i <= n; i++)
        if (fin(1) != fin(i)) {
            cout << "-1\n"; return 0;
        }
    cout << m - res << '\n';
}