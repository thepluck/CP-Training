#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int ninf = 0xc0c0c0c0;

struct edge {
    int v, w;

    edge(int v, int w): v(v), w(w) {}

    bool operator != (const edge &o) {
        return v != o.v || w != o.w;
    }
};

vector <edge> adj[N];
int mx[N], dp[N], a[N], d[N], nxt[N][26];
int in[N], out[N], ver[N], tim;

int dfs_hv(int u) {
    ver[in[u] = ++tim] = u;
    int u_sz = 1, v_sz, mxv_sz = 0;
    for (edge &e : adj[u]) {
        d[e.v] = d[u] + 1;
        a[e.v] = a[u] ^ (1 << e.w);
        u_sz += v_sz = dfs_hv(e.v);
        if (mxv_sz < v_sz) {
            mxv_sz = v_sz;
            swap(e, adj[u][0]);
        }
    }
    out[u] = tim; return u_sz;
}

void dfs_sol(int u, bool cl) {
    for (edge e : adj[u])
        if (e != adj[u][0]) {
            dfs_sol(e.v, 1);
            dp[u] = max(dp[u], dp[e.v]);
        }
    if (!adj[u].empty()) {
        dfs_sol(adj[u][0].v, 0);
        dp[u] = max(dp[u], dp[adj[u][0].v]);
    }
    for (edge e : adj[u])
        if (e != adj[u][0]) {
            for (int i = in[e.v]; i <= out[e.v]; i++) {
                dp[u] = max(dp[u], d[ver[i]] + mx[a[ver[i]]] - 2 * d[u]);
                for (int j = 0; j < 26; j++)
                    dp[u] = max(dp[u], d[ver[i]] + mx[nxt[ver[i]][j]] - 2 * d[u]);
            }
            for (int i = in[e.v]; i <= out[e.v]; i++)
                mx[a[ver[i]]] = max(mx[a[ver[i]]], d[ver[i]]);
        }
    dp[u] = max(dp[u], mx[a[u]] - d[u]);
    for (int j = 0; j < 26; j++)
        dp[u] = max(dp[u], mx[nxt[u][j]] - d[u]);
    mx[a[u]] = max(mx[a[u]], d[u]);
    if (cl)
        for (int i = in[u]; i <= out[u]; i++)
            mx[a[ver[i]]] = ninf;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 2, j; i <= n; i++) {
        char x; cin >> j >> x;
        adj[j].emplace_back(i, x - 'a');
    }
    memset(mx, 0xc0, sizeof mx);
    dfs_hv(1); vector <int> cmp;
    for (int i = 1; i <= n; i++)
        cmp.emplace_back(a[i]);
    sort(cmp.begin(), cmp.end());
    cmp.resize(distance(cmp.begin(),
    unique(cmp.begin(), cmp.end())));
    for (int i = 1; i <= n; i++) {
        decltype(cmp.begin()) it;
        for (int j = 0; j < 26; j++) {
            int tmp = a[i] ^ (1 << j);
            it = lower_bound(cmp.begin(), cmp.end(), tmp);
            if (it != cmp.end() && *it == tmp)
                nxt[i][j] = distance(cmp.begin(), it) + 1;
        }
        it = upper_bound(cmp.begin(), cmp.end(), a[i]);
        a[i] = distance(cmp.begin(), it);
    }
    dfs_sol(1, 0);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
}