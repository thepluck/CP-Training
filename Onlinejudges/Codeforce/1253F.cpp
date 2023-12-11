#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second

using ll = long long;
using ii = pair <int, int>;

struct path {
    int v; ll w;

    path(): v(0), w(0) {}

    path(int v, ll w): v(v), w(w) {}

    bool operator < (const path &o) const {
        return w > o.w;
    }
};

struct edge {
    int u, v; ll w;

    edge(): u(0), v(0), w(0) {}

    edge(int u, int v, ll w): u(u), v(v), w(w) {}

    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

const int N = 3e5 + 5;
const ll inf = 1e18;

vector <path> adj[N];
edge ed[N];
ll di[N], ans[N];
int par[N], sz[N];
priority_queue <path> pq;
vector <ii> que[N];

int find_set(int u) {
    if (u != par[u])
        par[u] = find_set(par[u]);
    return par[u];
}

void union_set(int u, int v, ll w) {
    u = find_set(u); v = find_set(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    for (ii p : que[u]) {
        if (find_set(p.fi) == v)
            ans[p.se] = w;
        else que[v].push_back(p);
    }
    que[u].clear();
    que[u].shrink_to_fit();
    sz[v] += sz[u]; par[u] = v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        adj[ed[i].u].eb(ed[i].v, ed[i].w);
        adj[ed[i].v].eb(ed[i].u, ed[i].w);
    }
    for (int i = 1; i <= n; i++) {
        if (i <= k)
            pq.emplace(i, di[i] = 0);
        else di[i] = inf;
        sz[i] = 1;
    }
    while (!pq.empty()) {
        path cur = pq.top(); pq.pop();
        if (di[cur.v] < cur.w) continue;
        for (path e : adj[cur.v])
            if (di[e.v] > cur.w + e.w) {
                di[e.v] = cur.w + e.w;
                pq.emplace(e.v, di[e.v]);
            }
    }
    for (int i = 1; i <= m; i++)
        ed[i].w += di[ed[i].u] + di[ed[i].v];
    sort(ed + 1, ed + m + 1);
    iota(par, par + N, 0);
    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        que[u].eb(v, i); que[v].eb(u, i);
    }
    for (int i = 1; i <= m; i++)
        union_set(ed[i].u, ed[i].v, ed[i].w);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}