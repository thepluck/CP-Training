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
    
    int N; vector <edge> lst;
    vector <int> head, trace;
    vector <char> used;
    vector <long long> dist, phi;
    
    MCMF(int N): N(N) {
        head.assign(N + 5, -1);
        trace.assign(N + 5, 0);
        used.assign(N + 5, 0);
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
        fill(used.begin(), used.end(), INF);
        dist[s] = 0; dist[N + 1] = INF;
        while (s != N + 1) {
            used[s] = true;
            for (int i = head[s]; i >= 0; i = lst[i].nxt)
                if (lst[i].flow < lst[i].capa &&
                cmin(dist[lst[i].to], dist[s] +
                lst[i].cost + phi[s] - phi[lst[i].to]))
                    trace[lst[i].to] = i;
            s = N + 1;
            for (int u = 0; u <= N; u++)
                if (!used[u] && dist[u] < dist[s]) s = u;
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K, S, T;
    cin >> N >> M >> K >> S >> T;
    MCMF G(N);
    vector <tuple <int, int, int>> lst;
    for (int i = 0; i < M; i++) {
        int u, v, cap, cost;
        cin >> u >> v >> cost >> cap;
        lst.emplace_back(u, v,
        G.addEdge(u, v, cap, cost));
        lst.emplace_back(v, u,
        G.addEdge(v, u, cap, cost));
    }
    cout << G.maxFlow(S, T, K).second << '\n';
    for (auto edge : lst) {
        int u, v, i; tie(u, v, i) = edge;
        if (G.lst[i].flow)
            cout << u << ' ' << v << ' ' << G.lst[i].flow << '\n';
    }
    cout << "0 0 0";
}
