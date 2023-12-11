#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const int M = 1000005;

struct graph {
    vector <int> adj[N];
    int tin[N], tout[N], root, timer;

    void addEdge(int u, int v) {
        if (u == 0) root = v;
        else adj[u].push_back(v);
    }

    void DFS(int u) {
        tin[u] = ++timer;
        for (int v : adj[u]) DFS(v);
        tout[u] = timer;
    }

    void compute() {DFS(root);}
};

struct event {
    int x, l, r, t;
    
    bool operator < (const event &o) const {
        return x < o.x;
    }
};

struct query {
    int x, p, id;

    bool operator < (const query &o) const {
        return x < o.x;
    }
};

int BIT[N], ans[N];
event ev[M]; query qr[N];

void update(int i, int v) {
    for (; i < N; i += i & -i) BIT[i] += v;
}

void update(int l, int r, int v) {
    update(l, v); update(r + 1, -v);
}

int getVal(int i) {
    int v = 0;
    for (; i > 0; i -= i & -i) v += BIT[i];
    return v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; graph G[2];
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p, q; cin >> p >> q;
        G[0].addEdge(p, i);
        G[1].addEdge(q, i);
    }
    G[0].compute(); G[1].compute();
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        int l1 = G[0].tin[u];
        int r1 = G[0].tout[u];
        int l2 = G[1].tin[v];
        int r2 = G[1].tout[v];
        ev[i] = {l1, l2, r2, 1};
        ev[i + m] = {r1 + 1, l2, r2, -1};
    }
    sort(ev + 1, ev + 2 * m + 1);
    for (int u = 1; u <= n; u++)
        qr[u] = {G[0].tin[u], G[1].tin[u], u};
    sort(qr + 1, qr + n + 1);
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= 2 * m && ev[j].x <= qr[i].x) {
            update(ev[j].l, ev[j].r, ev[j].t); j++;
        }
        ans[qr[i].id] = getVal(qr[i].p);
    }
    for (int u = 1; u <= n; u++)
        cout << ans[u] << '\n';
}