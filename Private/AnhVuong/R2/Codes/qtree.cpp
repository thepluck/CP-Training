#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ll = long long;

const int N = 200005;
const ll INF = 1e18;

struct segTree1 {
    vector <ll> val, pre;
    vector <int> tag;
    int n, lo, hi; ll res;

    void init(int n) {
        this->n = n;
        val.resize(n * 4 + 5);
        tag.resize(n * 4 + 5, 2);
        pre.resize(n + 5);
    }

    void pushTag(int i, int l, int r, int tg) {
        if (tg) val[i] = pre[r] - pre[l - 1];
        else val[i] = 0;
        tag[i] = tg;
    }
    
    void pushDown(int i, int l, int r) {
        if (tag[i] < 2) {
            int m = (l + r) / 2;
            pushTag(i * 2, l, m, tag[i]);
            pushTag(i * 2 + 1, m + 1, r, tag[i]);
            tag[i] = 2;
        }
    }

    void update(int i, int l, int r, int tg) {
        if (l >= lo && r <= hi)
            return pushTag(i, l, r, tg);
        pushDown(i, l, r); int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, tg);
        if (m < hi) update(i * 2 + 1, m + 1, r, tg);
        val[i] = val[i * 2] + val[i * 2 + 1];
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res += val[i]);
        pushDown(i, l, r); int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi) query(i * 2 + 1, m + 1, r);
    }

    void update(int l, int r, int tg) {
        if (l > r) return;
        lo = l; hi = r; update(1, 1, n, tg);
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        lo = l; hi = r; res = 0;
        query(1, 1, n); return res;
    }
} ST1;

struct segTree2 {
    vector <ll> val;
    int n, lo, hi; ll res;

    void init(int n) {
        this->n = n;
        val.resize(n * 4, -INF);
    }

    void update(int i, int l, int r, ll v) {
        if (l == r) return void(val[i] = v);
        int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v);
        else update(i * 2 + 1, m + 1, r, v);
        val[i] = max(val[i * 2], val[i * 2 + 1]);
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res = max(res, val[i]));
        int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi) query(i * 2 + 1, m + 1, r);
    }
 
    void update(int p, ll v) {
        lo = p; update(1, 1, n, v);
    }

    ll query(int l, int r) {
        if (l > r) return -INF;
        lo = l; hi = r; res = -INF;
        query(1, 1, n); return res;
    }
} ST2;

struct segTree3 {
    vector <pair <ll, int>> val;
    int n, lo, hi; pair <ll, int> res;

    void build(int i, int l, int r) {
        val[i] = {-INF, l};
        if (l != r) {
            int m = (l + r) / 2;
            build(i * 2, l, m);
            build(i * 2 + 1, m + 1, r);
        }
    }

    void init(int n) {
        this->n = n;
        val.resize(n * 4);
        build(1, 1, n);
    }

    void update(int i, int l, int r, ll v) {
        if (l == r) return void(val[i].fi = v);
        int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v);
        else update(i * 2 + 1, m + 1, r, v);
        val[i] = max(val[i * 2], val[i * 2 + 1]);
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res = max(res, val[i]));
        int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi) query(i * 2 + 1, m + 1, r);
    }

    void update(int p, ll v) {
        lo = p; update(1, 1, n, v);
    }

    pair <ll, int> query(int l, int r) {
        if (l > r) return {-INF, 0};
        lo = l; hi = r; res.fi = -INF;
        query(1, 1, n); return res;
    }
} ST3;

int hv[N], dep[N], head[N];
int par[18][N], col[N]; ll dis[N];
int tin[N], tout[N], timer, ver[N];
vector <pair <int, int>> adj[N];
set <int> lst;

int DFS1(int u) {
    for (int i = 1; i < 18; i++)
        par[i][u] = par[i - 1][par[i - 1][u]];
    int siz = 1, tmp = 0, big = 0;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != par[0][u]) {
            dep[v] = dep[u] + 1;
            dis[v] = dis[u] + w;
            par[0][v] = u;
            siz += tmp = DFS1(v);
            if (tmp > big) {
                big = tmp; hv[u] = v;
            }
        }
    }
    return siz;
}

void DFS2(int u) {
    ver[tin[u] = ++timer] = u;
    if (u == hv[par[0][u]])
        head[u] = head[par[0][u]];
    else head[u] = u;
    if (hv[u]) DFS2(hv[u]);
    for (auto e : adj[u]) {
        int v; tie(v, ignore) = e;
        if (v != par[0][u] && v != hv[u])
            DFS2(v);
    }
    tout[u] = timer;
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 17; i >= 0; i--)
        if (dep[par[i][u]] >= dep[v])
            u = par[i][u];
    if (u == v) return u;
    for (int i = 17; i >= 0; i--)
        if (par[i][u] != par[i][v]) {
            u = par[i][u]; v = par[i][v];
        }
    return par[0][u];
}

void add(int u) {
    int r = -1, tmp = u;
    ST3.update(tin[u], dis[u]);
    while (u = par[0][head[u]])
        ST2.update(tin[u],
        ST3.query(tout[hv[u]] + 1,
        tout[u]).fi - dis[u] * 2);
    u = tmp;
    if (lst.empty()) {
        lst.insert(tin[u]); return;
    }
    auto it = lst.lower_bound(tin[u]);
    if (it != lst.end())
        r = LCA(u, ver[*it]);
    if (it != lst.begin()) {
        int v = LCA(u, ver[*prev(it)]);
        if (r < 0 || dep[r] < dep[v]) r = v;
    }
    while (head[u] != head[r]) {
        ST1.update(tin[head[u]], tin[u], 1);
        u = par[0][head[u]];
    }
    ST1.update(tin[r] + 1, tin[u], 1);
    int p = LCA(ver[*lst.begin()],
    ver[*lst.rbegin()]);
    if (dep[p] >= dep[r]) {
        while (head[p] != head[r]) {
            ST1.update(tin[head[p]], tin[p], 1);
            p = par[0][head[p]];
        }
        ST1.update(tin[r] + 1, tin[p], 1);
    }
    lst.insert(tin[u = tmp]);
}

void remove(int u) {
    int r = -1, tmp = u;
    ST3.update(tin[u], -INF);
    while (u = par[0][head[u]])
        ST2.update(tin[u],
        ST3.query(tout[hv[u]] + 1,
        tout[u]).fi - dis[u] * 2);
    lst.erase(tin[u = tmp]);
    if (lst.empty()) return;
    auto it = lst.lower_bound(tin[u]);
    if (it != lst.end())
        r = LCA(u, ver[*it]);
    if (it != lst.begin()) {
        int v = LCA(u, ver[*prev(it)]);
        if (r < 0 || dep[r] < dep[v]) r = v;
    }
    while (head[u] != head[r]) {
        ST1.update(tin[head[u]], tin[u], 0);
        u = par[0][head[u]];
    }
    ST1.update(tin[r] + 1, tin[u], 0);
    int p = LCA(ver[*lst.begin()],
    ver[*lst.rbegin()]);
    if (dep[p] >= dep[r]) {
        while (head[p] != head[r]) {
            ST1.update(tin[head[p]], tin[p], 0);
            p = par[0][head[p]];
        }
        ST1.update(tin[r] + 1, tin[p], 0);
    }
}

ll getDiam(int u) {
    int v; ll res;
    tie(res, v) = ST3.query(tin[u], tout[u]);
    ll tmp = res; res -= dis[u]; v = ver[v];
    while (head[u] != head[v]) {
        if (v != head[v])
            res = max(res, tmp + ST2.query
            (tin[head[v]], tin[par[0][v]]));
        v = head[v]; int p = par[0][v];
        res = max(res, tmp - dis[p] * 2 +
        max(ST3.query(tin[p] + 1, tin[v] - 1).fi,
        ST3.query(tout[v] + 1, tout[p]).fi));
        v = p;
    }
    if (u != v)
        res = max(res, tmp + ST2.query
        (tin[u], tin[par[0][v]]));
    return res;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c; col[i] = c - '0';
    }
    for (int i = 1; i < n; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    DFS1(1); DFS2(1); dep[0] = -1;
    ST1.init(n); ST2.init(n); ST3.init(n);
    for (int u = 1; u <= n; u++)
        for (auto e : adj[u]) {
            int v, w; tie(v, w) = e;
            if (v != par[0][u])
                ST1.pre[tin[v]] = w;
        }
    for (int i = 1; i <= n; i++)
        ST1.pre[i] += ST1.pre[i - 1];
    for (int i = 1; i <= n; i++)
        if (col[i]) add(i);
    int q; cin >> q;
    while (q--) {
        int cmd, u; cin >> cmd >> u;
        if (cmd == 1) {
            if (col[u] ^= 1) add(u); else remove(u);
        }
        if (cmd == 2) {
            auto it1 = lst.lower_bound(tin[u]);
            if (it1 != lst.end() && *it1 <= tout[u]) {
                auto it2 = lst.upper_bound(tout[u]);
                int r = LCA(ver[*it1], ver[*prev(it2)]);
                cout << ST1.query(tin[r] + 1,
                tout[r]) * 2 << '\n';
            }
            else cout << 0 << '\n';
        }
        if (cmd == 3) {
            auto it1 = lst.lower_bound(tin[u]);
            if (it1 != lst.end() && *it1 <= tout[u]) {
                auto it2 = lst.upper_bound(tout[u]);
                int r = LCA(ver[*it1], ver[*prev(it2)]);
                cout << ST1.query(tin[r] + 1,
                tout[r]) * 2 - getDiam(r) << '\n';
            }
            else cout << 0 << '\n';
        }
    }
}
