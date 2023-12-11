#include <bits/stdc++.h>

using namespace std;

struct DinicFlow {
    vector <int> head, dist, work;
    vector <int> to, nxt, capa, flow;
    queue <int> que; int lim;
 
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
                if (dist[to[i]] < 0 && capa[i] - flow[i] >= lim) {
                    dist[to[i]] = dist[s] + 1; que.push(to[i]);
                }
        }
        return dist[t] >= 0;
    }
 
    int DFS(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (dist[to[i]] == dist[s] + 1 && capa[i] - flow[i] >= lim) {
                int d = DFS(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }
 
    int maxFlow(int s, int t) {
        int tot = 0, aug;
        for (lim = 1 << 30; lim > 0; lim >>= 1)
            while (BFS(s, t)) {
                copy(head.begin(), head.end(), work.begin());
                while ((aug = DFS(s, t, INT_MAX)) > 0) tot += aug;
            }
        return tot;
    }
};
