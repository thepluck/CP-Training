#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 200005;

int tin[N], tout[N], timer;
vector <int> adj[N]; ll bit[N], tot;
int head[N], par[N], dep[N], hv[N];
multiset <ll> ans[N];

void updateBIT(int i, ll v) {
    for (; i < N; i += i & -i)
        bit[i] += v;
}

ll queryBIT(int i) {
    ll res = 0;
    for (; i > 0; i -= i & -i)
        res += bit[i];
    return res;
}

int DFSpre(int u) {
    int mx = 0, sz = 1, tmp;
    dep[u] = dep[par[u]] + 1;
    for (int v : adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        sz += tmp = DFSpre(v);
        if (tmp > mx) {
            mx = tmp; hv[u] = v;
        }
    }
    return sz;
}

void DFSsplit(int u) {
    tin[u] = ++timer;
    if (par[u] && u == hv[par[u]])
        head[u] = head[par[u]];
    else head[u] = u;
    if (hv[u]) DFSsplit(hv[u]);
    for (int v : adj[u])
        if (v != par[u] && v != hv[u])
            DFSsplit(v);
    tout[u] = timer;
}

ll queryBIT(int l, int r) {
    return queryBIT(r) - queryBIT(l - 1);
}

void updateTree(int u, ll w) {
    int v = u;
    while (head[u] != 1) {
        ll cur = queryBIT(tout[head[u]])
        - queryBIT(tin[head[u]] - 1);
        ans[par[head[u]]].erase
        (ans[par[head[u]]].find(cur));
        ans[par[head[u]]].insert(cur + w);
        u = par[head[u]];
    }
    updateBIT(tin[v], w); tot += w;
}

ll queryTree(int u) {
    ll res = 0;
    if (par[u]) res = tot -
        queryBIT(tout[u])
        + queryBIT(tin[u] - 1);
    if (hv[u]) res = max(res,
        queryBIT(tout[hv[u]]) -
        queryBIT(tin[hv[u]] - 1));
    if (ans[u].size())
        res = max(res, *ans[u].rbegin());
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFSpre(1); DFSsplit(1);
    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
            if (v != hv[u] && v != par[u])
                ans[u].insert(0);
    for (int u = 1; u <= n; u++) {
        ll w; cin >> w; updateTree(u, w);
    }
    while (q--) {
        char cmd; cin >> cmd;
        if (cmd == 'U') {
            ll w; int u; cin >> w >> u;
            updateTree(u, w);
        }
        else {
            int u; cin >> u;
            cout << queryTree(u) << '\n';
        }
    }
}