#include <bits/stdc++.h>

using namespace std;

struct DinicFlow {
    vector <int> head, dist, work;
    vector <int> to, nxt;
    vector <int> capa, flow;
    queue <int> que;
 
    void init(int n) {
        head.assign(n + 5, -1);
        dist.assign(n + 5, 0);
        work.assign(n + 5, 0);
        to.clear(); nxt.clear();
        capa.clear(); flow.clear();
    }
 
    int addEdge(int u, int v, int c, bool r = 0) {
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(c); flow.push_back(0);
        head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(c * r); flow.push_back(0);
        head[v] = to.size() - 1;
        return head[u];
    }
 
    bool BFS(int s, int t) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0; que.push(s);
        while (que.size()) {
            s = que.front(); que.pop();
            for (int i = head[s]; i >= 0; i = nxt[i])
                if (dist[to[i]] < 0 && capa[i] > flow[i]) {
                    dist[to[i]] = dist[s] + 1; que.push(to[i]);
                }
        }
        return dist[t] >= 0;
    }
 
    int DFS(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (dist[to[i]] == dist[s] + 1 && capa[i] > flow[i]) {
                int d = DFS(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }
 
    int maxFlow(int s, int t) {
        int tot = 0; int aug;
        while (BFS(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = DFS(s, t, INT_MAX)) > 0) tot += aug;
        }
        return tot;
    }
};

const int N = 305;

int a[N], b[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    DinicFlow dinic; dinic.init(2 * n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    while (m--) {
        int u, v; cin >> u >> v;
        dinic.addEdge(u + n, v, INT_MAX);
        dinic.addEdge(v + n, u, INT_MAX);
    }
    int sum = 0;
    for (int u = 1; u <= n; u++) {
        if (b[u] > 0) {
            sum += b[u];
            dinic.addEdge(u, u + n, a[u] + b[u]);
            dinic.addEdge(u + n, 2 * n + 1, 2 * b[u]);
        }
        else {
            sum -= b[u];
            dinic.addEdge(0, u, -2 * b[u]);
            dinic.addEdge(u, u + n, a[u] - b[u]);
        }
    }
    cout << sum - dinic.maxFlow(0, 2 * n + 1);
}