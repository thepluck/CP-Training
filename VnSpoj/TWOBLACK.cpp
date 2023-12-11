#include <bits/stdc++.h>
using namespace std;

namespace dinic {
    const int inf = 0x3f3f3f3f;

    vector <int> head, dis, work;
    vector <int> to, nxt, capa, flow;
    int n; queue <int> q;

    void init(int n) {
        dinic::n = n;
        head.assign(n + 5, -1);
        dis.assign(n + 5, 0);
        work.assign(n + 5, 0);
        to.clear(); nxt.clear();
        capa.clear(); flow.clear();
    }

    void add_edge(int u, int v, int c, bool r = 0) {
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(c); flow.push_back(0);
        head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(c * r); flow.push_back(0);
        head[v] = to.size() - 1;
    }

    bool bfs(int s, int t) {
        fill(dis.begin(), dis.end(), -1);
        dis[s] = 0; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (int i = head[u]; i >= 0; i = nxt[i])
                if (flow[i] < capa[i] && dis[to[i]] < 0) {
                    dis[to[i]] = dis[u] + 1; q.push(to[i]);
                }
        }
        return dis[t] >= 0;
    }

    int dfs(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (flow[i] < capa[i] && dis[to[i]] == dis[s] + 1) {
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
            copy(head.begin(), head.end(), work.begin());
            while ((aug = dfs(s, t, inf)) > 0) res += aug;
        }
        return res;
    }
};

const int N = 105;

char a[N][N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> (a[i] + 1);
    int lo = 1, hi = n;
    int src = 0, sink = n + m + 1;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        dinic::init(n + m + 2);
        for (int i = 1; i <= n; i++)
            dinic::add_edge(src, i, 2);
        for (int j = 1; j <= m; j++)
            dinic::add_edge(j + n, sink, mi);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] == '1')
                    dinic::add_edge(i, j + n, 1);
        if (dinic::max_flow(src, sink) == n * 2)
            hi = mi; else lo = mi + 1;
    }
    cout << hi << '\n';
}