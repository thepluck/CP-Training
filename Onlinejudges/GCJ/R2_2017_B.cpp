#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct MCMF {
    const int INF = 1e9;
    
    struct edge {
        int to, nxt, flow, capa, cost;
        
        edge(int to, int nxt, int flow, int capa, int cost):
        to(to), nxt(nxt), flow(flow), capa(capa), cost(cost) {}
    };
    
    struct path {
        int to; int cost;
        
        path(int to, int cost): to(to), cost(cost) {}

        bool operator < (const path &o) const {
            return cost > o.cost;
        }
    };
    
    int N; vector <edge> lst;
    vector <int> head, trace;
    vector <int> dist, phi;
    priority_queue <path> pq;
    
    void init(int N) {
        this->N = N;
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
    
    pair <int, int> maxFlow(int s, int t, int lim) {
        int maxFlow = 0; int minCost = 0;
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

struct DinicFlow {
    vector <int> head, dist, work;
    vector <int> to, nxt, capa, flow;
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
        int tot = 0, aug;
        while (BFS(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = DFS(s, t, INT_MAX)) > 0) tot += aug;
        }
        return tot;
    }
};

const int MAXC = 1005;

vector <int> adj[MAXC];

void solve() {
    int N, C, M; cin >> N >> C >> M;
    for (int i = 1; i <= C; i++)
        adj[i].clear();
    for (int i = 1; i <= M; i++) {
        int p, b; cin >> p >> b;
        adj[b].push_back(p);
    }
    DinicFlow D;
    int lo = 0, hi = M;
    for (int i = 1; i <= C; i++)
        lo = max(lo, int(adj[i].size()));
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        D.init(C + N + 5);
        for (int i = 1; i <= C; i++) {
            D.addEdge(0, i, adj[i].size());
            for (int j : adj[i])
                D.addEdge(i, j + C, 1);
        }
        for (int j = 1; j <= N; j++)
            D.addEdge(j + C, C + N + 1, mi);
        for (int j = 1; j < N; j++)
            D.addEdge(j + 1 + C, j + C, M);
        if (D.maxFlow(0, C + N + 1) < M)
            lo = mi + 1;
        else hi = mi;
    }
    cout << hi << ' '; int T = C;
    MCMF G; G.init(C + M + 2 * N + 5); 
    for (int i = 1; i <= C; i++) {
        G.addEdge(0, i, adj[i].size(), 0);
        for (int j : adj[i]) {
            G.addEdge(i, ++T, 1, 0);
            G.addEdge(T, j + C + M, 1, 0);
            if (j > 1)
                G.addEdge(T, j + C + M + N - 1, 1, 1);
        }
    }
    for (int j = 1; j <= N; j++) {
        G.addEdge(j + C + M, C + M + 2 * N + 1, hi, 0);
        G.addEdge(j + C + M + N, j + C + M, hi, 0);
    }
    for (int j = 1; j < N; j++)
        G.addEdge(j + C + M + N + 1, j + C + M + N, M, 0);
    cout << G.maxFlow(0, C + M + 2 * N + 1, M).second << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}