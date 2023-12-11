#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

struct path {
    int v; ll w;

    path(int v, ll w): v(v), w(w) {}

    bool operator < (const path &o) const {
        return w > o.w;
    }
};


const int N = 2e5 + 5;
const int LOG = 19;
const ll inf = 1e17;

vector <path> adj[N];
priority_queue <path> pq;
ll dis[N];
int h[N], p[LOG][N], sz[N];

int lca(int u, int v) {
    if (!u || !v) return u | v;
    if (h[u] < h[v]) swap(u, v);
    for (int k = LOG - 1; ~k; k--)
        if (h[p[k][u]] >= h[v])
            u = p[k][u];
    if (u == v) return u;
    for (int k = LOG - 1; ~k; k--)
        if (p[k][u] != p[k][v]) {
            u = p[k][u];
            v = p[k][v];
        }
    return p[0][u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, s, res = 0; h[0] = -1;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    fill_n(dis + 1, n, inf);
    vector <int> ord;
    pq.emplace(s, dis[s] = 0);
    while (!pq.empty()) {
        path t = pq.top(); pq.pop();
        if (dis[t.v] != t.w) continue;
        if (t.v != s) ord.eb(t.v);
        for (path e : adj[t.v]) {
            if (dis[e.v] + e.w == t.w)
                p[0][t.v] = lca(p[0][t.v], e.v);
            if (dis[e.v] > t.w + e.w) {
                dis[e.v] = t.w + e.w;
                pq.emplace(e.v, dis[e.v]);
            }
        }
        if (p[0][t.v]) {
            h[t.v] = h[p[0][t.v]] + 1;
            for (int k = 1; k < LOG; k++)
                p[k][t.v] = p[k - 1][p[k - 1][t.v]];
        }
    }
    reverse(ord.begin(), ord.end());
    for (auto u : ord) {
        sz[u]++; res = max(res, sz[u]);
        sz[p[0][u]] += sz[u];
    }
    cout << res << '\n';
}