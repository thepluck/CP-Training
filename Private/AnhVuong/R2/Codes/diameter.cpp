#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = -3e18;

struct segTree1 {
    using Tp = pair <ll, int>;

    vector <Tp> tr; vector <ll> tg;
    int n, lo, hi; Tp res;

    void buildTree(int i, int l, int r) {
        tr[i].second = l;
        if (l != r) {
            int m = (l + r) / 2;
            buildTree(i * 2, l, m);
            buildTree(i * 2 + 1, m + 1, r);
        }
    }

    void initTree(int n) {
        this->n = n;
        tr.assign(n * 4, Tp());
        tg.assign(n * 4, 0);
        buildTree(1, 1, n);
    }

    void pushTag(int i, ll v) {
        tr[i].first += v; tg[i] += v;
    }

    void pushDown(int i) {
        pushTag(i * 2, tg[i]);
        pushTag(i * 2 + 1, tg[i]);
        tg[i] = 0;
    }

    void update(int i, int l, int r, ll v) {
        if (l >= lo && r <= hi)
            return pushTag(i, v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v);
        if (m < hi)
            update(i * 2 + 1, m + 1, r, v);
        tr[i] = max(tr[i * 2], tr[i * 2 + 1]);
    }

    void update(int l, int r, ll v) {
        lo = l; hi = r; update(1, 1, n, v);
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi) {
            res = max(res, tr[i]); return;
        }
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi)
            query(i * 2 + 1, m + 1, r);
    }

    ll query(int l, int r) {
        if (l > r) return INF;
        lo = l; hi = r; res = {INF, 0};
        query(1, 1, n); return res.first;
    }
};

struct segTree2 {
    vector <ll> tr, tg;
    int n, lo, hi; ll res;

    void initTree(int n) {
        this->n = n;
        tr.assign(n * 4, 0);
        tg.assign(n * 4, 0);
    }

    void pushTag(int i, ll v) {
        tr[i] += v; tg[i] += v;
    }

    void pushDown(int i) {
        pushTag(i * 2, tg[i]);
        pushTag(i * 2 + 1, tg[i]);
        tg[i] = 0;
    }

    void replace(int i, int l, int r, ll v) {
        if (l == r) return void(tr[i] = v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) replace(i * 2, l, m, v);
        else replace(i * 2 + 1, m + 1, r, v);
        tr[i] = max(tr[i * 2], tr[i * 2 + 1]);
    }

    void replace(int p, ll v) {
        lo = p; replace(1, 1, n, v);
    }

    void update(int i, int l, int r, ll v) {
        if (l >= lo && r <= hi)
            return pushTag(i, v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v);
        if (m < hi)
            update(i * 2 + 1, m + 1, r, v);
        tr[i] = max(tr[i * 2], tr[i * 2 + 1]);
    }

    void update(int l, int r, ll v) {
        lo = l; hi = r; update(1, 1, n, v);
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi) {
            res = max(res, tr[i]); return;
        }
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi)
            query(i * 2 + 1, m + 1, r);
    }

    ll query(int l, int r) {
        if (l > r) return INF;
        lo = l; hi = r; res = INF;
        query(1, 1, n); return res;
    }
};

struct edge {int u, v; ll w;};

const int N = 100005;

int hv[N], tin[N], tout[N], timer;
vector <int> adj[N]; edge ed[N];
int par[N], head[N], n, q, ver[N];
segTree1 ST1; segTree2 ST2; ll M;

int DFSpre(int u) {
    int big = 0, sz = 1, tmp;
    for (int v : adj[u]) {
        if (v == par[u]) continue;
        par[v] = u;
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
    tout[u] = timer;
}

ll getUp(int u) {
    return ST1.query(tin[u], tin[u]);
}

void update(int i, ll w) {
    int u = ed[i].u;
    ll x = ed[i].w; ed[i].w = w;
    ST1.update(tin[u], tout[u], w - x);
    ST2.update(tin[u], tout[u], x - w);
    while ((u = par[head[u]]))
        ST2.replace(tin[u],
        ST1.query(tout[hv[u]] + 1,
        tout[u]) - getUp(u) * 2);
}

ll query() {
    ll res = 0, tmp; int u;
    tie(res, u) = ST1.tr[1];
    u = ver[u]; tmp = res;
    while (u) {
        if (u != head[u])
            res = max(res, tmp + ST2.query
            (tin[head[u]], tin[par[u]]));
        u = head[u]; int p = par[u];
        if (!p) break;
        res = max(res, tmp - getUp(p) * 2 +
        max(ST1.query(tin[p] + 1, tin[u] - 1),
        ST1.query(tout[u] + 1, tout[p])));
        u = p;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> M; ll last = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        ed[i] = {u, v, w};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFSpre(1); DFSsplit(1);
    ST1.initTree(n); ST2.initTree(n);
    for (int u = 1; u <= n; u++) {
        int light = 0;
        for (int v : adj[u])
            if (v != par[u] && v != hv[u])
                light++;
        if (light) ST2.replace(tin[u], 0);
        else ST2.replace(tin[u], INF);
    }
    for (int i = 0; i < n - 1; i++) {
        if (par[ed[i].v] == ed[i].u)
            swap(ed[i].u, ed[i].v);
        ll w = ed[i].w; ed[i].w = 0;
        update(i, w);
    }
    while (q--) {
        int i; ll w; cin >> i >> w;
        i = (last + i) % (n - 1);
        w = (last + w) % M; update(i, w);
        cout << (last = query()) << '\n';
    }
}