#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using pii = pair <int, int>;

struct query {int l, r, t, id;};

const int N = 200005;

int par[2][N], val[2][N], siz[2][N];
vector <int> adj[2][N]; int ver[2][N];
int tin[2][N], tout[2][N], timer;
int ans[N], BIT[N]; vector <query> que[N];

void updateBIT(int i) {
    for (; i < N; i += i & -i) BIT[i]++;
}

int queryBIT(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) res += BIT[i];
    return res;
}

int getRoot(int id, int u) {
    if (!par[id][u]) return u ;
    return getRoot(id, par[id][u]);
}

void uniteSet(int id, int u, int v, int w) {
    u = getRoot(id, u); v = getRoot(id, v);
    if (u == v) return;
    if (siz[id][u] < siz[id][v]) swap(u, v);
    par[id][v] = u; val[id][v] = w;
    siz[id][u] += siz[id][v];
    adj[id][u].push_back(v);
}

void DFS(int id, int u) {
    ver[id][tin[id][u] = ++timer] = u;
    for (int v : adj[id][u]) DFS(id, v);
    tout[id][u] = timer;
}

vector <int> check_validity(int n, vector <int> x,
vector <int> y, vector <int> s, vector <int> e,
vector <int> ll, vector <int> rr) {
    int m = x.size(), q = s.size();
    vector <pii> edge(m);
    for (int i = 0; i < m; i++)
        edge[i] = {++x[i], ++y[i]};
    for (int i = 1; i <= n; i++)
        siz[0][i] = siz[1][i] = 1;
    sort(edge.begin(), edge.end(),
    [](const pii &x, const pii &y) {
        return max(x.fi, x.se) < max(y.fi, y.se);
    });
    for (auto e : edge)
        uniteSet(0, e.fi, e.se, max(e.fi, e.se));
    for (int i = 1; i <= n; i++)
        if (!par[0][i]) DFS(0, i);
    sort(edge.begin(), edge.end(),
    [](const pii &x, const pii &y) {
        return min(x.fi, x.se) > min(y.fi, y.se);
    });
    for (auto e : edge)
        uniteSet(1, e.fi, e.se, min(e.fi, e.se));
    timer = 0;
    for (int i = 1; i <= n; i++)
        if (!par[1][i]) DFS(1, i);
    for (int i = 0; i < q; i++) {
        int u, v, l, r;
        u = s[i]; v = e[i]; l = ll[i]; r = rr[i];
        u++; v++; l++; r++; swap(u, v);
        if (u > r || v < l) continue;
        while (par[0][u] && val[0][u] <= r)
            u = par[0][u];
        int lo = 0, hi = adj[0][u].size() - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (val[0][adj[0][u][mi]] <= r)
                lo = mi;
            else hi = mi - 1;
        }
        int x1 = tin[0][u], x2;
        if (adj[0][u].empty() ||
        val[0][adj[0][u][lo]] > r)
            x2 = tin[0][u];
        else x2 = tout[0][adj[0][u][lo]];
        while (par[1][v] && val[1][v] >= l)
            v = par[1][v];
        lo = 0, hi = adj[1][v].size() - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (val[1][adj[1][v][mi]] >= l)
                lo = mi;
            else hi = mi - 1;
        }
        int y1 = tin[1][v], y2;
        if (adj[1][v].empty() ||
        val[1][adj[1][v][lo]] < l)
            y2 = tin[1][v];
        else y2 = tout[1][adj[1][v][lo]];
        que[x1 - 1].push_back({y1, y2, -1, i});
        que[x2].push_back({y1, y2, 1, i});
    }
    vector <int> res(q);
    for (int i = 1; i <= n; i++) {
        updateBIT(tin[1][ver[0][i]]);
        for (auto ev : que[i])
            ans[ev.id] += (queryBIT(ev.r)
            - queryBIT(ev.l - 1)) * ev.t;
    }
    for (int i = 0; i < q; i++)
        res[i] = ans[i] > 0;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector <pii> edge(m);
    for (int i = 0; i < m; i++) {
        cin >> edge[i].fi >> edge[i].se;
        edge[i].fi++; edge[i].se++;
    }
    for (int i = 1; i <= n; i++)
        siz[0][i] = siz[1][i] = 1;
    sort(edge.begin(), edge.end(),
    [](const pii &x, const pii &y) {
        return max(x.fi, x.se) < max(y.fi, y.se);
    });
    for (auto e : edge)
        uniteSet(0, e.fi, e.se, max(e.fi, e.se));
    for (int i = 1; i <= n; i++)
        if (!par[0][i]) DFS(0, i);
    sort(edge.begin(), edge.end(),
    [](const pii &x, const pii &y) {
        return min(x.fi, x.se) > min(y.fi, y.se);
    });
    for (auto e : edge)
        uniteSet(1, e.fi, e.se, min(e.fi, e.se));
    timer = 0;
    for (int i = 1; i <= n; i++)
        if (!par[1][i]) DFS(1, i);
    for (int i = 1; i <= q; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        u++; v++; l++; r++; swap(u, v);
        if (u > r || v < l) continue;
        while (par[0][u] && val[0][u] <= r)
            u = par[0][u];
        int lo = 0, hi = adj[0][u].size() - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (val[0][adj[0][u][mi]] <= r)
                lo = mi;
            else hi = mi - 1;
        }
        int x1 = tin[0][u], x2;
        if (adj[0][u].empty() ||
        val[0][adj[0][u][lo]] > r)
            x2 = tin[0][u];
        else x2 = tout[0][adj[0][u][lo]];
        while (par[1][v] && val[1][v] >= l)
            v = par[1][v];
        lo = 0, hi = adj[1][v].size() - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (val[1][adj[1][v][mi]] >= l)
                lo = mi;
            else hi = mi - 1;
        }
        int y1 = tin[1][v], y2;
        if (adj[1][v].empty() ||
        val[1][adj[1][v][lo]] < l)
            y2 = tin[1][v];
        else y2 = tout[1][adj[1][v][lo]];
        que[x1 - 1].push_back({y1, y2, -1, i});
        que[x2].push_back({y1, y2, 1, i});
    }
    for (int i = 1; i <= n; i++) {
        updateBIT(tin[1][ver[0][i]]);
        for (auto ev : que[i])
            ans[ev.id] += (queryBIT(ev.r)
            - queryBIT(ev.l - 1)) * ev.t;
    }
    for (int i = 1; i <= q; i++)
        cout << (ans[i] > 0) << '\n';
}