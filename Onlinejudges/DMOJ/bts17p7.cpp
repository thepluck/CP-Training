
// Problem : Back to School '17: Hot and Cold
// Contest : DMOJ
// URL : https://dmoj.ca/problem/bts17p7
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define eb emplace_back

const int N = 1e5 + 5;
const int LG = 17;

int p[LG][N], d[N];
ll b[N], c[N];
vector <int> g[N];

void dfs(int u) {
    for (int v : g[u]) {
        if (v == p[0][u]) continue;
        d[v] = d[u] + 1;
        p[0][v] = u; dfs(v);
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

void cal(int u) {
    for (int v : g[u]) {
        if (v == p[0][u]) continue;
        cal(v);
        b[u] += b[v]; c[u] += c[v];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v), g[v].eb(u);
    }
    dfs(1); d[0] = -1;
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++)
            p[k][i] = p[k - 1][p[k - 1][i]];
    while (q--) {
        int u, v, w;
        cin >> u >> v >> w;
        int x = lca(u, w);
        int y = lca(v, w);
        int r = lca(u, v);
        int du = d[u] + d[w] - 2 * d[x];
        int dv = d[v] + d[w] - 2 * d[y];
        if (d[x] < d[y]) {
            swap(x, y); swap(u, v);
        }
        if (d[x] > d[r]) {
            b[u] += du - d[u];
            b[x] -= du - d[u];
            c[u]++; c[x]--;
            b[x] += d[x]; b[r] -= d[x];
            c[x]--; c[r]++;
        }
        else {
            b[u] += du - d[u];
            b[r] -= du - d[u];
            c[u]++; c[r]--;
        }
        b[v] += dv - d[v];
        b[p[0][r]] -= dv - d[v];
        c[v]++; c[p[0][r]]--;
    }
    cal(1);
    for (int i = 1; i <= n; i++)
        cout << b[i] + c[i] * d[i] << ' ';
}