#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back

template <class X, class Y>
bool chkmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int u, v, w;

    edge() {}
    
    edge(int u, int v, int w):
    u(u), v(v), w(w) {}
};

using ii = pair <int, int>;
using ll = long long;

const int N = 300005;
const int M = 300005;

vector <ii> adj[N], tree[N];
edge ed[M];
int n, m, k;
bool brid[M], mk[N];
int comp[N], tin[N], c[N];
int tmn[N], tim, cnt[N];
ll sum[N], dp[N], ans[N];

void dfs1(int u, int e) {
    tin[u] = tmn[u] = ++tim;
    for (ii p : adj[u]) {
        int v = p.fi, i = p.se;
        if (i == e) continue;
        if (tin[v])
            chkmin(tmn[u], tin[v]);
        else {
            dfs1(v, i);
            chkmin(tmn[u], tmn[v]);
            if (tin[u] < tmn[v])
                brid[i] = 1;
        }
    }
}

void dfs2(int u, int cc) {
    if (comp[u]) return;
    comp[u] = cc;
    cnt[cc] += mk[u];
    sum[cc] += c[u];
    for (ii p : adj[u])
        if (!brid[p.se])
            dfs2(p.fi, cc);
}

void change(edge e, int t) {
    ll tmp = dp[e.v];
    /// subtree v has special vertices
    /// but not all special vertices
    if (cnt[e.v] && cnt[e.v] < k)
        tmp = max(0ll, tmp - e.w);
    cnt[e.u] += t * cnt[e.v];
    dp[e.u] += t * tmp;
}

void link(int u, int v, int w) {
    change({u, v, w}, 1);
}

void cut(int u, int v, int w) {
    change({u, v, w}, -1);
}

void dfs3(int u, int p) {
    dp[u] = sum[u];
    for (ii pp : tree[u]) {
        int v = pp.fi, i = pp.se;
        if (v == p) continue;
        dfs3(v, u);
        link(u, v, ed[i].w);
    }
}

void dfs4(int u, int p) {
    ans[u] = dp[u];
    for (ii pp : tree[u]) {
        int v = pp.fi, i = pp.se;
        if (v == p) continue;
        cut(u, v, ed[i].w);
        link(v, u, ed[i].w);
        dfs4(v, u);
        cut(v, u, ed[i].w);
        link(u, v, ed[i].w);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int u; cin >> u; mk[u] = 1;
    }
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= m; i++)
        cin >> ed[i].w;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v;
        adj[ed[i].u].eb(ed[i].v, i);
        adj[ed[i].v].eb(ed[i].u, i);
    }
    /// find bridges
    dfs1(1, 0); int cc = 0;
    /// find biconnected components
    for (int i = 1; i <= n; i++)
        if (!comp[i]) dfs2(i, ++cc);
    for (int i = 1; i <= m; i++)
        if (brid[i]) {
            tree[comp[ed[i].u]].
            eb(comp[ed[i].v], i);
            tree[comp[ed[i].v]].
            eb(comp[ed[i].u], i);
        }
    /// calculate dp table
    /// change root
    dfs3(1, 0); dfs4(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[comp[i]] << ' ';
}