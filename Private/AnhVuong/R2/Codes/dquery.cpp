#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

using ll = long long;

int par[N], siz[N], curCh;
ll dep[N]; bool vis[N];
vector <ll> tot[N], ofPar[N], cur;
vector <pair <int, int>> adj[N];
map <int, ll> dis[N]; int root;

void DFSsiz(int u, int p) {
    siz[u] = 1;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != p && !vis[v]) {
            DFSsiz(v, u);
            siz[u] += siz[v];
        }
    }
}

int findCen(int u) {
    int p = 0, c = u;
    while (true) {
        bool flag = false;
        for (auto e : adj[c]) {
            int v; tie(v, ignore) = e;
            if (v != p && !vis[v] &&
            siz[v] * 2 >= siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        }
        if (flag) continue; break;
    }
    return c;
}

int cntLeq(const vector <ll> &v, ll x) {
    return distance(v.begin(),
    upper_bound(v.begin(), v.end(), x));
}

void DFSdep(int u, int p) {
    cur.push_back(dep[u]);
    tot[root].push_back(dep[u]);
    dis[root][u] = dep[u];
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != p && !vis[v]) {
            dep[v] = dep[u] + w;
            DFSdep(v, u);
        }
    }
}

int DFScen(int u) {
    DFSsiz(u, 0); u = findCen(u);
    vis[u] = true; root = u;
    tot[u].push_back(0);
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (!vis[v]) {
            cur.clear(); dep[v] = w;
            root = u; DFSdep(v, u);
            sort(cur.begin(), cur.end());
            vector <ll> tmp = cur;
            int c = DFScen(v);
            par[c] = u; ofPar[c] = tmp;
        }
    }
    sort(tot[u].begin(), tot[u].end());
    return u;
}

int cntPath(int u, ll x) {
    int res = cntLeq(tot[u], x), v = u;
    while (par[v]) {
        ll y = x - dis[par[v]][u];
        res += cntLeq(tot[par[v]], y)
        - cntLeq(ofPar[v], y);
        v = par[v];
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    DFScen(1);
    while (q--) {
        int u; ll x; cin >> u >> x;
        cout << cntPath(u, x) << '\n';
    }
}