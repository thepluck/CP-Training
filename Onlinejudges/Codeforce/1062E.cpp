#include <bits/stdc++.h>
using namespace std;

#define clz __builtin_clz

const int N = 1e5 + 5;
const int LG = 18;

int p[LG][N], d[N];
int in[N], out[N], tim;
int mn[LG][N], mx[LG][N];
vector <int> adj[N];

void dfs(int u) {
    in[u] = ++tim;
    mn[0][u] = mx[0][u] = u;
    for (int v : adj[u]) {
        d[v] = d[u] + 1; dfs(v);
    }
}

int lca(int u, int v) {
    if (!u || !v) return u | v;
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

int qmin(int l, int r) {
    if (l > r) return 0;
    int k = 31 - clz(r - l + 1);
    if (in[mn[k][l]] < in[mn[k][r + 1 - (1 << k)]])
        return mn[k][l];
    return mn[k][r + 1 - (1 << k)];
}

int qmax(int l, int r) {
    if (l > r) return 0;
    int k = 31 - clz(r - l + 1);
    if (in[mx[k][l]] > in[mx[k][r + 1 - (1 << k)]])
        return mx[k][l];
    return mx[k][r + 1 - (1 << k)];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> p[0][i];
        adj[p[0][i]].push_back(i);
    }
    dfs(1); d[0] = -1;
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++) {
            p[k][i] = p[k - 1][p[k - 1][i]];
            if (i + (1 << k) <= n + 1) {
                int j = i + (1 << k - 1);
                if (in[mn[k - 1][i]] < in[mn[k - 1][j]])
                    mn[k][i] = mn[k - 1][i];
                else mn[k][i] = mn[k - 1][j];
                if (in[mx[k - 1][i]] > in[mx[k - 1][j]])
                    mx[k][i] = mx[k - 1][i];
                else mx[k][i] = mx[k - 1][j];
            }
        }
    while (q--) {
        int l, r; cin >> l >> r;
        int u = qmin(l, r), v = qmax(l, r);
        int x = lca(qmin(l, u - 1), qmax(l, u - 1));
        int y = lca(qmin(u + 1, r), qmax(u + 1, r));
        int a = lca(x, y);
        x = lca(qmin(l, v - 1), qmax(l, v - 1));
        y = lca(qmin(v + 1, r), qmax(v + 1, r));
        int b = lca(x, y);
        if (d[a] > d[b])
            cout << u << ' ' << d[a] << '\n';
        else cout << v << ' ' << d[b] << '\n';
    }
}
