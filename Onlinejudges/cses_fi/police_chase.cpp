#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int inf = INT_MAX;

vector <int> dist, to, nxt, head;
vector <int> flow, capa, work;
int n, m; queue <int> q;

void init(int n = 0) {
    ::n = n; m = 0;
    dist.assign(n + 5, 0);
    head.assign(n + 5, -1);
    work.assign(n + 5, 0);
    to.clear(); capa.clear();
    nxt.clear(); flow.clear();
}

int add_edge(int u, int v, int c, bool r = 0) {
    to.eb(v); capa.eb(c); flow.eb(0);
    nxt.eb(head[u]); head[u] = m++;
    to.eb(u); capa.eb(c * r); flow.eb(0);
    nxt.eb(head[v]); head[v] = m++;
    return m - 2;
}

bool bfs(int s, int t) {
    for (int i = 0; i <= n; i++)
        dist[i] = -1;
    dist[s] = 0; q.emplace(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i >= 0; i = nxt[i])
            if (flow[i] < capa[i] && dist[to[i]] < 0) {
                dist[to[i]] = dist[u] + 1;
                q.emplace(to[i]);
            }
    }
    return dist[t] >= 0;
}

int dfs(int s, int t, int f) {
    if (s == t) return f;
    for (int &i = work[s]; i >= 0; i = nxt[i])
        if (flow[i] < capa[i] && dist[to[i]] == dist[s] + 1) {
            int d = dfs(to[i], t, min(f, capa[i] - flow[i]));
            if (d > 0) {
                flow[i] += d; flow[i ^ 1] -= d; return d;
            }
        }
    return 0;
}

int max_flow(int s, int t) {
    int res = 0, aug;
    while (bfs(s, t)) {
        for (int i = 0; i <= n; i++)
            work[i] = head[i];
        while ((aug = dfs(s, t, inf)) > 0)
            res += aug;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m; init(n);
    vector <pair <int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v, 1, 1);
        edges.emplace_back(u, v);
    }
    cout << max_flow(1, n) << '\n';
    bfs(1, n);
    for (pair <int, int> e : edges) {
        bool u = dist[e.first] < 0, v = dist[e.second] < 0;
        if (u ^ v) cout << e.first << ' ' << e.second << '\n';
    }
}