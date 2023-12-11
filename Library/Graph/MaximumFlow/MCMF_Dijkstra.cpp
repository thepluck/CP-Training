#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
struct MCMF {
    const long long INF = 1e18;
    
    struct edge {
        int to, nxt, flow, capa, cost;
        
        edge(int to, int nxt, int flow, int capa, int cost):
        to(to), nxt(nxt), flow(flow), capa(capa), cost(cost) {}
    };
    
    struct path {
        int to; long long cost;
        
        path(int to, long long cost): to(to), cost(cost) {}

        bool operator < (const path &o) const {
            return cost > o.cost;
        }
    };
    
    int N; vector <edge> lst;
    vector <int> head, trace;
    vector <long long> dist, phi;
    priority_queue <path> pq;
    
    MCMF(int N): N(N) {
        head.assign(N + 5, -1);
        trace.assign(N + 5, 0);
        dist.assign(N + 5, 0);
        phi.assign(N + 5, INF);
    }
    
    int addEdge(int u, int v, int cap, int cost) {
        lst.emplace_back(v, head[u], 0, cap, cost);
        head[u] = lst.size() - 1;
        lst.emplace_back(u, head[v], 0, 0, -cost);
        head[v] = lst.size() - 1;
        return head[u];
    }
    
    bool Dijkstra(int s, int t) {
        fill(dist.begin(), dist.end(), INF);
        pq.emplace(s, dist[s] = 0);
        while (pq.size()) {
            path p = pq.top(); pq.pop();
            if (dist[p.to] < p.cost) continue;
            for (int i = head[p.to]; i >= 0; i = lst[i].nxt)
                if (lst[i].flow < lst[i].capa &&
                cmin(dist[lst[i].to], dist[p.to] +
                lst[i].cost + phi[p.to] - phi[lst[i].to])) {
                    trace[lst[i].to] = i;
                    pq.emplace(lst[i].to, dist[lst[i].to]);
                }
        }
        for (s = 0; s <= N; s++)
            phi[s] = min(phi[s] + dist[s], INF);
        return dist[t] != INF;
    }
    
    pair <int, long long> maxFlow(int s, int t, int lim) {
        int maxFlow = 0; long long minCost = 0;
        while (maxFlow < lim && Dijkstra(s, t)) {
            int u = t, newFlow = lim - maxFlow;
            while (u != s) {
                int i = trace[u]; u = lst[i ^ 1].to;
                cmin(newFlow, lst[i].capa - lst[i].flow);
            }
            maxFlow += newFlow; u = t;
            while (u != s) {
                int i = trace[u]; u = lst[i ^ 1].to;
                lst[i].flow += newFlow;
                lst[i ^ 1].flow -= newFlow;
                minCost += 1ll * newFlow * lst[i].cost;
            }
        }
        return {maxFlow, minCost};
    }
};
