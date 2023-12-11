#include <bits/stdc++.h>
using namespace std;

namespace dinic{
    #define eb emplace_back

    const int inf = INT_MAX;

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
                    dist[to[i]] = dist[u] + 1; q.emplace(to[i]);
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
};

void solve() {
    map <string, int> cc, qq;
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    dinic::init(n + m * 2 + k + 1);
    int src = 0, sink = n + m * 2 + k + 1;
    for (int i = 1; i <= m; i++)
        dinic::add_edge(i + n, i + n + m, 1);
    for (int i = 1; i <= n; i++)
        dinic::add_edge(src, i, 1);
    for (int i = 1; i <= k; i++)
        dinic::add_edge(i + n + m * 2, sink, 1);
    while (l--) {
        int a, b, c; string s, t;
        cin >> a >> s >> t;
        if (!cc.count(s)) cc[s] = cc.size() + 1;
        if (!qq.count(t)) qq[t] = qq.size() + 1;
        b = cc[s]; c = qq[t];
        dinic::add_edge(a, b + n, 1);
        dinic::add_edge(b + n + m, c + n + m * 2, 1);
    }
    cout << dinic::max_flow(src, sink) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}
