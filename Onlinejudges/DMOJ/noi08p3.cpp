#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

struct MCMF {
    const ll INF = 0x3f3f3f3f3f3f3f3f;

    vector <int> head, trace; vector <ll> dis;
    vector <int> to, nxt, capa, flow, cost;
    vector <char> inq; queue <int> que;

    MCMF(int n) {
        head.assign(n + 5, -1);
        trace.assign(n + 5, 0);
        dis.assign(n + 5, 0);
        inq.assign(n + 5, 0);
    }

    void addEdge(int u, int v, int w, int c) {
        to.push_back(v); nxt.push_back(head[u]);
        capa.push_back(w); cost.push_back(c);
        flow.push_back(0); head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        capa.push_back(0); cost.push_back(-c);
        flow.push_back(0); head[v] = to.size() - 1;
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

    pair <int, ll> minCostmaxFlow(int s, int t, int lim) {
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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    MCMF G(N + 2);
    G.addEdge(0, 1, INT_MAX, 0);
    G.addEdge(N + 1, N + 2, INT_MAX, 0);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        G.addEdge(i, i + 1, INT_MAX - x, 0);
    }
    while (M--) {
        int l, r, c; cin >> l >> r >> c;
        G.addEdge(l, r + 1, INT_MAX, c);
    }
    cout << G.minCostmaxFlow(0, N + 2, INT_MAX).second;
}