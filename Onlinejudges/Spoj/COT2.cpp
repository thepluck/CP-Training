// Problem: Count on a tree II
// Contest: SPOJ - Classical
// URL: https://www.spoj.com/problems/COT2/
// Memory Limit: 1536 MB
// Time Limit: 1207 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int LG = 16;
const int B = 500;

struct query {
    int i, l, r, x;
};

int tin[N], tout[N], timer, dep[N];
bool vis[N]; query que[N];
int cnt[N], a[N], n, q, ans[N];
int par[N][LG], res, ver[N];
vector <int> adj[N]; 

void add(int i) {
    if (vis[i] && --cnt[a[i]] == 0) res--;
    if (!vis[i] && cnt[a[i]]++ == 0) res++;
    vis[i] = !vis[i];
}

void dfs(int u) {
    ver[tin[u] = ++timer] = u;
    for (int k = 1; k < LG; k++)
        par[u][k] = par[par[u][k - 1]][k - 1];
    for (int v : adj[u]) if (v != par[u][0]) {
        dep[v] = dep[par[v][0] = u] + 1; dfs(v);
    }
    ver[tout[u] = ++timer] = u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG - 1; k >= 0; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    if (u == v) return u;
    for (int k = LG - 1; k >= 0; k--)
        if (par[u][k] != par[v][k]) {
            u = par[u][k]; v = par[v][k];
        }
    return par[u][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector <int> cmp; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; cmp.push_back(a[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(),
    cmp.end()), cmp.end());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(cmp.begin(),
        cmp.end(), a[i]) - cmp.begin();
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[0] = -1; dfs(1);
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        if (tin[u] > tin[v]) swap(u, v);
        int x = lca(u, v);
        if (x == u)
            que[i] = {i, tin[u], tin[v], x};
        else que[i] = {i, tout[u], tin[v], x};
    }
    sort(que + 1, que + q + 1,
    [](const query &x, const query &y) {
        return x.l / B != y.l / B ?
        x.l < y.l : x.r < y.r;
    });
    int lo = 1, hi = 0;
    for (int i = 1; i <= q; i++) {
        int l = que[i].l, r = que[i].r;
        int u = ver[l], v = ver[r];
        while (lo > l) add(ver[--lo]);
        while (hi < r) add(ver[++hi]);
        while (lo < l) add(ver[lo++]);
        while (hi > r) add(ver[hi--]);
        if (que[i].x != u) add(que[i].x);
        ans[que[i].i] = res;
        if (que[i].x != u) add(que[i].x);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}