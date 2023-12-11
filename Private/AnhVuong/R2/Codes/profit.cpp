#include <bits/stdc++.h>

using namespace std;

struct segTree {
    vector <int> val, tag; int n, lo, hi;

    void init(int n) {
        this->n = n;
        val.assign(n * 4 + 5, 0);
        tag.assign(n * 4 + 5, 0);
    }

    void pushTag(int i, int v) {
        val[i] += v; tag[i] += v;
    }

    void pushDown(int i) {
        pushTag(i * 2, tag[i]);
        pushTag(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }

    void update(int i, int l, int r, int v) {
        if (l > hi || r < lo) return;
        if (l >= lo && r <= hi) return pushTag(i, v);
        pushDown(i); int m = (l + r) / 2;
        update(i * 2, l, m, v);
        update(i * 2 + 1, m + 1, r, v);
        val[i] = max(val[i * 2], val[i * 2 + 1]);
    }

    void update(int l, int r, int v) {
        if (l > r) return;
        lo = l; hi = r; update(1, 1, n, v);
    }

    int query(int i, int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l >= lo && r <= hi) return val[i];
        pushDown(i); int m = (l + r) / 2;
        return max(query(i * 2, l, m),
        query(i * 2 + 1, m + 1, r));
    }

    int query(int l, int r) {
        lo = l; hi = r; return query(1, 1, n);
    }
};

const int N = 1e6 + 5;

struct query {int x, l, r, v;};

int tin[N], tout[N], timer;
int n, m, res, dep[N], ver[N];
vector <int> adj[N]; segTree ST;
vector <pair <int, int>> path[N];
vector <query> que;

void addRect(int x, int y, int l, int r, int v) {
    que.push_back({x, l, r, v});
    que.push_back({y + 1, l, r, -v});
}

bool isAnc(int u, int p) {
    return tin[u] >= tin[p] && tin[u] <= tout[p];
}

void DFS1(int u, int p) {
    tin[u] = ++timer;
    for (int v : adj[u]) if (v != p) DFS1(v, u);
    tout[u] = timer;
}

void DFS2(int u, int p) {
    ver[dep[u] = dep[p] + 1] = u;
    for (auto e : path[u]) {
        int v, w; tie(v, w) = e;
        if (isAnc(v, u)) continue;
        if (isAnc(u, v)) {
            int x = ver[dep[v] + 1];
            addRect(1, tin[x] - 1, tin[u], tout[u], w);
            addRect(tout[x] + 1, n, tin[u], tout[u], w);
            addRect(tin[u], tout[u], 1, tin[x] - 1, w);
            addRect(tin[u], tout[u], tout[x] + 1, n, w);
        }
        else addRect(tin[u], tout[u], tin[v], tout[v], w);
    }
    for (int v : adj[u]) if (v != p) DFS2(v, u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        path[u].emplace_back(v, w);
        path[v].emplace_back(u, w);
    }
    ST.init(n); DFS1(1, 0); DFS2(1, 0);
    sort(que.begin(), que.end(),
    [](const query &a, const query &b) {
        return a.x != b.x ? a.x < b.x : a.v < b.v;
    });
    for (auto ev : que) {
        ST.update(ev.l, ev.r, ev.v);
        res = max(res, ST.val[1]);
    }
    cout << res << '\n';
}