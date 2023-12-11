#include <bits/stdc++.h>

using namespace std;

struct segTree {
    vector <int> val, tag;
    int n, lo, hi;

    segTree(int n):
    val(n * 4), tag(n * 4), n(n) {}
    
    void pushTag(int i, int v) {
        val[i] += v; tag[i] += v;
    }

    void pushDown(int i) {
        pushTag(i * 2, tag[i]);
        pushTag(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }

    void update(int i, int l, int r, int v) {
        if (l >= lo && r <= hi)
            return pushTag(i, v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v);
        if (m < hi) update(i * 2 + 1, m + 1, r, v);
        val[i] = max(val[i * 2], val[i * 2 + 1]);
    }

    void update(int l, int r, int v) {
        lo = l; hi = r; update(1, 1, n, v);
    }
};

const int N = 1e5 + 5;

int hv[N], tin[N], timer;
int par[N], head[N], ver[N], dep[N];
vector <int> adj[N];

int DFSpre(int u) {
    int big = 0, sz = 1, tmp;
    for (int v : adj[u]) {
        if (v == par[u]) continue;
        dep[v] = dep[par[v] = u] + 1;
        sz += tmp = DFSpre(v);
        if (tmp > big) {
            big = tmp; hv[u] = v;
        }   
    }
    return sz;
}
 
void DFSsplit(int u) {
    ver[tin[u] = ++timer] = u;
    if (par[u] && u == hv[par[u]])
        head[u] = head[par[u]];
    else head[u] = u;
    if (hv[u]) DFSsplit(hv[u]);
    for (int v : adj[u])
        if (v != par[u] && v != hv[u])
            DFSsplit(v);
}

void update(int u, int v, int t, segTree &ST) {
    while (head[u] != head[v]) {
        if (dep[head[u]] < dep[head[v]]) swap(u, v);
        ST.update(tin[head[u]], tin[u], t);
        u = par[head[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    ST.update(tin[v], tin[u], t);
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
    segTree ST(n);
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t) update(u, v, -1, ST);
        else update(u, v, 1, ST);
        cout << ST.val[1] << '\n';
    }
}