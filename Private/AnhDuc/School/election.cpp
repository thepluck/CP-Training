#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

#define eb emplace_back

using ll = long long;

struct path {
    int u, v, w;

    path(int u, int v, int w):
    u(u), v(v), w(w) {}
};

const int N = 1e5 + 5;
const int LG = 17;

vector <int> adj[N];
vector <path> own[N];
int p[LG][N], d[N], dp[2][N];
int in[N], out[N], tim;
int n, m; ll bit[N];

void update(int i, int v) {
    for (; i <= n; i += i & -i)
        bit[i] += v;
}

void update(int l, int r, int v) {
    update(l, v); update(r + 1, -v);
}

ll query(int i) {
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

void dfs(int u) {
    in[u] = ++tim;
    for (int v : adj[u])
        if (v != p[0][u]) {
            d[v] = d[u] + 1;
            p[0][v] = u; dfs(v);
        }
    out[u] = tim;
}

int jump(int u, int l) {
    if (l < 0) return -1;
    for (int k = LG - 1; ~k; k--)
        if (l >> k & 1) u = p[k][u];
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v])
        v = jump(v, d[v] - d[u]);
    else u = jump(u, d[u] - d[v]);
    if (u == v) return u;
    for (int k = LG - 1; ~k; k--)
        if (p[k][u] != p[k][v]) {
            u = p[k][u]; v = p[k][v];
        }
    return p[0][u];
}

void vis(int u) {
    for (int v : adj[u]) {
        if (v == p[0][u]) continue;
        vis(v); dp[0][u] += dp[1][v];
    }
    dp[1][u] = dp[0][u];
    for (path e : own[u])
        cmax(dp[1][u], dp[0][u] + e.w +
        query(in[e.u]) + query(in[e.v]));
    update(in[u], out[u],
    dp[0][u] - dp[1][u]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1); d[0] = -1; cin >> m;
    for (int k = 1; k < LG; k++)
        for (int i = 1; i <= n; i++)
            p[k][i] = p[k - 1][p[k - 1][i]];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        own[lca(u, v)].eb(u, v, w);
    }
    vis(1); cout << dp[1][1] << '\n';
}