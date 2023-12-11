#include <bits/stdc++.h>
using namespace std;

namespace dinic{
    #define eb emplace_back
    
    const int inf = numeric_limits <int>::max();
    
    vector <int> dist, to, nxt, head;
    vector <int> flow, capa, work;
    int n, m; queue <int> q;
    
    void init(int n = 0) {
        dinic::n = n; m = 0;
        dist.assign(n + 5, 0);
        head.assign(n + 5, -1);
        work.assign(n + 5, 0);
        to.clear(); capa.clear();
        nxt.clear(); flow.clear();
    }
    
    int add_edge(int u, int v, int c, bool r = 0) {
        to.eb(v); capa.eb(c); flow.eb(0);
        nxt.eb(head[u]); head[u] = m++;
        to.eb(u); capa.eb(r ? c : 0); flow.eb(0);
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
        int res = 0, new_flow;
        while (bfs(s, t)) {
            for (int i = 0; i <= n; i++)
                work[i] = head[i];
            while ((new_flow = dfs(s, t, inf)) > 0)
                res += new_flow;
        }
        return res;
    }
};

#define eb emplace_back

const int N = 105;

vector <int> adj[N], dest;
int n, m, k, t;

int id(int i, int j) {
    return (i - 1) * (t + 1) + j;
}

int compute() {
    dinic::init(n * (t + 1) + 5);
    int src = id(1, 0), sink = id(n + 1, 0);
    for (int u = 1; u <= n; u++)
        for (int i = 0; i < t; i++) {
            dinic::add_edge(id(u, i), id(u, i + 1), 1);
            for (int v : adj[u])
                dinic::add_edge(id(u, i), id(v, i + 1), 1);
        }
    for (int i = 1; i <= t; i++)
        dinic::add_edge(src, id(1, i), k);
    for (int u : dest)
        dinic::add_edge(id(u, t), sink, 1);
    return dinic::max_flow(src, sink);
}

int main() {
    freopen("messages.inp", "r", stdin);
    freopen("messages.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);    
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u; cin >> u; dest.eb(u);
    }
    int lo = 0, hi = n * 2;
    while (lo < hi) {
        t = (lo + hi) / 2;
        if (compute() >= k) hi = t;
        else lo = t + 1;
    }
    cout << hi << '\n';
}