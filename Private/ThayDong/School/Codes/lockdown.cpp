#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

struct edge {
    int v; ll w;
    
    bool operator < (const edge &o) const {
        return w > o.w;
    }
    
    edge(int v, ll w): v(v), w(w) {}
};

const int N = 505;
const int LG = 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll dis[N]; bool vs[N];
int p[LG][N], d[N];
int n, sz[N], ord[N];
vector <edge> adj[N];
vector <edge> rev[N];

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

int dijkstra(int s) {
    fill_n(dis + 1, n, inf);
    fill_n(vs + 1, n, 0);
    vector <int> ord;
    dis[s] = 0; dis[0] = inf;
    while (true) {
        int u = 0;
        for (int v = 1; v <= n; v++)
            if (dis[v] < dis[u] && !vs[v])
                u = v;
        if (!u) break; vs[u] = 1;
        if (u != s) ord.push_back(u);
        for (edge e : adj[u])
            cmin(dis[e.v], dis[u] + e.w);
        for (edge e : rev[u])
            if (dis[e.v] + e.w == dis[u])
                p[0][u] = lca(p[0][u], e.v);
        d[u] = d[p[0][u]] + 1;
        for (int k = 1; k < LG; k++)
            p[k][u] = p[k - 1][p[k - 1][u]];
    }
    int res = 0;
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
        sz[u]++; sz[p[0][u]] += sz[u];
        for (edge e : rev[u])
            if (e.v == p[0][u])
                res = max(res, sz[u]);
    }
    return res;
}

int main() {
    freopen("lockdown.inp", "r", stdin);
    freopen("lockdown.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            int w; cin >> w;
            if (~w && i != j) {
                adj[i].emplace_back(j, w);
                rev[j].emplace_back(i, w);
            }
        }
    d[0] = -1;
    cout << dijkstra(1) << '\n';
}