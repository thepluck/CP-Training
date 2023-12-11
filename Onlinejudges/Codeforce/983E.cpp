#include <bits/stdc++.h>

using namespace std;

struct item {
    int c, u, v;
};

struct thing {
    int x, l, r, id;
};

const int MAXN = 200005;
const int LOG = 18;

vector <int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer;
int par[MAXN][LOG], dep[MAXN];
int jump[MAXN][LOG], dsu[MAXN];
int ans[MAXN], BIT[MAXN], tmp[MAXN];

void DFS(int u) {
    tin[u] = ++timer;
    for (int k = 1; k < LOG; k++)
        par[u][k] = par[par[u][k - 1]][k - 1];
    dep[u] = dep[par[u][0]] + 1;
    for (int v : adj[u])
        if (v != par[u][0]) DFS(v);
    tout[u] = timer;
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LOG - 1; k >= 0; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    for (int k = LOG - 1; k >= 0; k--)
        if (par[u][k] != par[v][k]) {
            u = par[u][k]; v = par[v][k];
        }
    return u == v ? u : par[u][0];
}

int root(int u) {
    return dsu[u] ? dsu[u] = root(dsu[u]) : u;
}

void add(int i) {
    for (; i < MAXN; i += i & -i)
        BIT[i]++;
}

int sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio();
    int N; cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> par[i][0];
        adj[par[i][0]].push_back(i);
    }
    DFS(1); int M; cin >> M;
    vector <item> path;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        if (tin[u] > tin[v]) swap(u, v);
        path.push_back({LCA(u, v), u, v});
    }
    sort(path.begin(), path.end(),
    [](item x, item y) {
        return dep[x.c] < dep[y.c];
    });
    vector <pair <int, int>> point;
    for (auto p : path) {
        int u = p.u, v = p.v, c = p.c;
        if (tout[u] < tin[v])
            point.emplace_back(tin[u], tin[v]);
        while (dep[u = root(u)] > dep[c]) {
            jump[u][0] = c;
            dsu[u] = par[u][0];
        }
        while (dep[v = root(v)] > dep[c]) {
            jump[v][0] = c;
            dsu[v] = par[v][0];
        }
    }
    for (int k = 1; k < LOG; k++)
        for (int u = 1; u <= N; u++)
            jump[u][k] = jump[jump[u][k - 1]][k - 1];
    vector <thing> query;
    int Q; cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int u, v; cin >> u >> v;
        if (root(u) != root(v)) {
            ans[i] = -1; continue;
        }
        if (tin[u] > tin[v]) swap(u, v);
        int c = LCA(u, v);
        for (int k = LOG - 1; k >= 0; k--) {
            if (dep[jump[u][k]] > dep[c]) {
                ans[i] += 1 << k;
                u = jump[u][k];
            }
            if (dep[jump[v][k]] > dep[c]) {
                ans[i] += 1 << k;
                v = jump[v][k];
            }
        }
        if (u == c || v == c) {
            ans[i]++; continue;
        }
        query.push_back({tin[u] - 1, tin[v], tout[v], -i});
        query.push_back({tout[u], tin[v], tout[v], i});
        ans[i] += 2;
    }
    sort(point.begin(), point.end());
    sort(query.begin(), query.end(),
    [](thing a, thing b) {return a.x < b.x;});
    for (int i = 0, j = 0; i < int(query.size()); i++) {
        while (j < int(point.size()) &&
        point[j].first <= query[i].x)
            add(point[j++].second);
        tmp[abs(query[i].id)] += (sum(query[i].r) -
        sum(query[i].l - 1)) * (query[i].id < 0 ? -1 : 1);
    }
    for (int i = 1; i <= Q; i++)
        cout << ans[i] - (tmp[i] > 0) << '\n';
}