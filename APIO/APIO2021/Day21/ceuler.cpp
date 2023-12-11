#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct minCostmaxFlow {
    using ll = long long;

    const ll INF = 0x3f3f3f3f3f3f3f3f;

    vector <int> head, trace; vector <ll> dis;
    vector <int> to, nxt, capa, flow, cost;
    vector <char> inq; queue <int> que;

    minCostmaxFlow(int n) {
        head.assign(n + 5, -1);
        trace.assign(n + 5, 0);
        dis.assign(n + 5, 0);
        inq.assign(n + 5, 0);
    }

    int addEdge(int u, int v, int w, int c) {
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(w); cost.push_back(c);
        flow.push_back(0); head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(0); cost.push_back(-c);
        flow.push_back(0); head[v] = to.size() - 1;
        return head[u];
    }

    bool SPFA(int s, int t) {
        fill(dis.begin(), dis.end(), INF);
        fill(inq.begin(), inq.end(), false);
        dis[s] = 0; que.push(s); inq[s] = true;
        while (que.size()) {
            int u = que.front();
            que.pop(); inq[u] = false;
            for (int i = head[u]; i >= 0; i = nxt[i])
                if (capa[i] > flow[i])
                    if (cmin(dis[to[i]], dis[u] + cost[i])) {
                        trace[to[i]] = i;
                        if (!inq[to[i]]) {
                            inq[to[i]] = true; que.push(to[i]);
                        }
                    }
        }
        return dis[t] != INF;
    }

    pair <int, ll> MCMF(int s, int t, int lim = INT_MAX) {
        int totFlow = 0; ll totCost = 0;
        while (lim > totFlow && SPFA(s, t)) {
            int u = t, newFlow = lim - totFlow;
            while (u != s) {
                int e = trace[u]; u = to[e ^ 1];
                newFlow = min(newFlow, capa[e] - flow[e]);
            }
            totFlow += newFlow;
            totCost += dis[u = t] * newFlow;
            while (u != s) {
                int e = trace[u]; u = to[e ^ 1];
                flow[e] += newFlow;
                flow[e ^ 1] -= newFlow;
            }
        }
        return {totFlow, totCost};
    }
};

struct edge {
    int v, id;
};

const int MAXN = 505;

int deg[MAXN], cnt[MAXN];
vector <edge> adj[MAXN];
vector <int> circut;

void DFS(int u, int id) {
    for (auto e : adj[u])
        if (cnt[e.id]) {
            cnt[e.id]--;
            DFS(e.v, e.id + 1);
        }
    if (id) circut.push_back(id);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    minCostmaxFlow MC(N + 2); long long sum = 0;
    for (int i = 0; i < M; i++) {
        int u, v, c; cin >> u >> v >> c;
        deg[u]++; deg[v]--; sum += c;
        MC.addEdge(u, v, INT_MAX, c);
        adj[u].push_back({v, i});
    }
    for (int u = 1; u <= N; u++)
        if (deg[u] < 0)
            MC.addEdge(0, u, -deg[u], 0);
        else if (deg[u] > 0)
            MC.addEdge(u, N + 1, deg[u], 0);
    sum += MC.MCMF(0, N + 1).second;
    for (int i = 0; i < M; i++)
        cnt[i] = MC.flow[i * 2] + 1;
    DFS(1, 0);
    reverse(circut.begin(), circut.end());
    cout << sum << ' ' << circut.size() << '\n';
    for (int id : circut) cout << id << ' ';
}