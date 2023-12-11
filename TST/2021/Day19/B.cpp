#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
    int v; ll w;

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 5;
const ll inf = 1e18;
const int MOD = 1e9 + 7;

int n, m, s, t, ord[N];
vector <edge> adj[N];
vector <int> dag[N];
priority_queue <edge> pq;
ll ds[N], dt[N]; int f[N], g[N];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

void dijkstra(int s, ll d[]) {
    fill(d + 1, d + n + 1, inf);
    pq.push({s, d[s] = 0});
    while (pq.size()) {
        edge cur = pq.top(); pq.pop();
        if (d[cur.v] != cur.w) continue;
        for (edge e : adj[cur.v])
            if (d[e.v] > cur.w + e.w) {
                d[e.v] = cur.w + e.w;
                pq.push({e.v, d[e.v]});
            }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(s, ds); dijkstra(t, dt);
    for (int i = 1; i <= n; i++)
        ord[i] = i;
    sort(ord + 1, ord + n + 1,
    [&](int x, int y) {
        return ds[x] < ds[y];
    });
    f[s] = g[t] = 1;
    for (int i = 2; i <= n; i++) {
        int u = ord[i];
        if (ds[u] + dt[u] != ds[t]) continue;
        for (edge e : adj[u])
            if (ds[u] == ds[e.v] + e.w)
                f[u] = madd(f[u], f[e.v]);
    }
    sort(ord + 1, ord + n + 1,
    [&](int x, int y) {
        return dt[x] < dt[y];
    });
    for (int i = 2; i <= n; i++) {
        int u = ord[i];
        if (ds[u] + dt[u] != ds[t]) continue;
        for (edge e : adj[u])
            if (dt[u] == dt[e.v] + e.w)
                g[u] = madd(g[u], g[e.v]);
    }
    int res = mmul(f[t], f[t]);
    for (int u = 1; u <= n; u++) {
        if (ds[u] + dt[u] != ds[t]) continue;
        if (ds[u] == dt[u]) {
            int tmp = mmul(f[u], g[u]);
            res = msub(res, mmul(tmp, tmp));
        }
        for (edge e : adj[u])
            if (ds[u] == ds[e.v] + e.w &&
            max(ds[e.v], dt[u]) * 2 < ds[t]) {
                int tmp = mmul(f[e.v], g[u]);
                res = msub(res, mmul(tmp, tmp));
            }
    }
    cout << res << '\n';
}