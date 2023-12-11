// Problem: E. Opening Portals
// Contest: Codeforces - Codeforces Round #124 (Div. 1)
// URL: https://codeforces.com/contest/196/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

struct path {
    int v; ll w;
    
    path(int v, ll w): v(v), w(w) {}
    
    bool operator < (const path &o) const {
        return w > o.w;
    }
};

struct edge {
    int u, v; ll w;
    
    edge(int u, int v, ll w): u(u), v(v), w(w) {}
    
    bool operator < (const edge &o) const {
        return w < o.w;
    }
};

const int N = 1e5 + 5;

ll dis[N]; int src[N], par[N];
priority_queue <path> pq;
vector <path> adj[N];
vector <edge> lst;

int fin(int u) {
    return par[u] == 0 ? u :
    par[u] = fin(par[u]);
}

bool mer(int u, int v) {
    u = fin(u); v = fin(v);
    if (u == v) return false;
    par[v] = u; return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].eb(v, w);
        adj[v].eb(u, w);
    }
    memset(dis, 0x3f, sizeof dis);
    int k; cin >> k;
    while (k--) {
        int u; cin >> u; src[u] = u;
        pq.emplace(u, dis[u] = 0);
    }
    while (pq.size()) {
        path t = pq.top(); pq.pop();
        if (dis[t.v] < t.w) continue;
        for (path e : adj[t.v])
            if (cmin(dis[e.v], t.w + e.w)) {
                src[e.v] = src[t.v];
                pq.emplace(e.v, dis[e.v]);
            }
    }
    ll res = dis[1];
    for (int u = 1; u <= n; u++)
        for (path e : adj[u])
            if (src[u] != src[e.v])
                lst.eb(src[u], src[e.v],
                dis[u] + dis[e.v] + e.w);
    sort(lst.begin(), lst.end());
    for (edge e : lst)
        if (mer(e.u, e.v)) res += e.w;
    cout << res << '\n';
}