#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

struct edge {
    int v, i;

    edge(int v, int i): v(v), i(i) {}
};

const int N = 1e5 + 5;
const int LG = 17;

vector <edge> adj[N];
vector <int> path, ret;
int tin[N], tim, n, m, k;
int rmq[LG][N], lg[N], ss[N];
int st[N], tp, sp[N], d[N];


void dfs(int u, int p) {
    tin[u] = tim++;
    for (edge e : adj[u])
        if (e.v != p) {
            ret.eb(tin[u]); path.eb(u);
            d[e.v] = d[u] + 1; dfs(e.v, u);
        }
}

int lca(int u, int v) {
    if (!u || !v) return u | v;
    if (u == v) return u;
    tie(u, v) = minmax(tin[u], tin[v]);
    int k = lg[v - u];
    return path[min(rmq[k][u],
        rmq[k][v - (1 << k)])];
}

void add(int u, int r) {
    ss[u]++; ss[r]--;
}

void init() {
    dfs(1, 0);
    for (int i = 0; i < n - 1; i++)
        rmq[0][i] = ret[i];
    for (int i = 2; i < n; i++)
        lg[i] = lg[i / 2] + 1;
    for (int x = 1; (1 << x) < n; x++)
        for (int i = 0; i + (1 << x) < n; i++)
            rmq[x][i] = min(rmq[x - 1][i],
            rmq[x - 1][i + (1 << (x - 1))]);
}

void vis(int u, int p) {
    for (edge e : adj[u])
        if (e.v != p) {
            vis(e.v, u); ss[u] += ss[e.v];
        }
    if (ss[u] >= k)
        for (edge e : adj[u])
            if (e.v == p) ret.eb(e.i);
}

void input() {
    cin >> n >> m >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v, i); adj[v].eb(u, i);
    }
}

void process() {
    auto cmp = [&](int x, int y) {
        return tin[x] < tin[y];
    };
    ret.clear();
    for (int i = 0; i < m; i++) {
        int s; cin >> s;
        st[tp = 0] = 0;
        for (int i = 0; i < s; i++) {
            cin >> sp[i];
            st[0] = lca(st[0], sp[i]);
        }
        sort(sp, sp + s, cmp);
        for (int i = 0; i < s; i++) {
            if (sp[i] == st[0]) continue;
            int r = lca(st[tp], sp[i]);
            while (tp && d[r] < d[st[tp - 1]]) {
                add(st[tp], st[tp - 1]); tp--;
            }
            if (d[r] < d[st[tp]]) add(st[tp--], r);
            if (st[tp] != r) st[++tp] = r;
            st[++tp] = sp[i];
        }
        while (tp) {
            add(st[tp], st[tp - 1]); tp--;
        }
    }
    vis(1, 0);
}

void output() {
    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (int i : ret) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    input(); init(); process(); output();
}