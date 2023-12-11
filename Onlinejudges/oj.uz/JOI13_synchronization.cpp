#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int LOG = 17;

int tin[MAXN], tout[MAXN];
int BIT[MAXN]; bool stat[MAXN];
pair <int, int> edge[MAXN];
vector <pair <int, int>> adj[MAXN];
int anc[MAXN][LOG];
int last[MAXN], val[MAXN];

void add(int i, int v) {
    for (i++; i < MAXN; i += i & -i)
        BIT[i] += v;
}

int sum(int i) {
    int sum = 0;
    for (i++; i > 0; i -= i & -i)
        sum += BIT[i];
    return sum;
}

int root(int u) {
    for (int i = LOG; --i >= 0; ) {
        if (anc[u][i] && sum(tin[u])
        == sum(tin[anc[u][i]]))
            u = anc[u][i];
    }
    return u;
}

void DFS(int u) {
    static int timer = 0;
    tin[u] = timer++;
    for (int i = 0; ++i < LOG; )
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for (auto e : adj[u]) {
        int v, i; tie(v, i) = e;
        if (v != anc[u][0]) {
            anc[v][0] = u;
            edge[i] = {u, v}; DFS(v);
        }
    }
    tout[u] = timer; val[u] = 1;
    add(tin[u], -1); add(tout[u], 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    DFS(1);
    while (M--) {
        int i, u, v; cin >> i;
        tie(u, v) = edge[i];
        if (stat[i]) {
            last[v] = val[v] = val[root(u)];
            add(tin[v], -1); add(tout[v], 1);
        } else {
            val[root(u)] += val[v] - last[v];
            add(tin[v], 1); add(tout[v], -1);
        }
        stat[i] ^= 1;
    }
    while (Q--) {
        int u; cin >> u;
        cout << val[root(u)] << '\n';
    }
}