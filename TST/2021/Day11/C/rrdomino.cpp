#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct MCMF {
    const int INF = 0x3f3f3f3f;

    vector <int> head, trace; vector <int> dis;
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

    pair <int, int> minCostmaxFlow(int s, int t, int lim) {
        int totFlow = 0; int totCost = 0;
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

int n, m, k, a[105][105];

int getID(int i, int j) {
    return (i - 1) * m + j;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m >> k) {
        MCMF tmp(n * m + 5);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if ((i + j) & 1) {
                    tmp.addEdge(0, getID(i, j), 1, 0);
                    if (i > 1) tmp.addEdge(getID(i, j),
                    getID(i - 1, j), 1, -a[i][j] * a[i - 1][j]);
                    if (i < n) tmp.addEdge(getID(i, j),
                    getID(i + 1, j), 1, -a[i][j] * a[i + 1][j]);
                    if (j > 1) tmp.addEdge(getID(i, j),
                    getID(i, j - 1), 1, -a[i][j] * a[i][j - 1]);
                    if (j < m) tmp.addEdge(getID(i, j),
                    getID(i, j + 1), 1, -a[i][j] * a[i][j + 1]);
                }
                else tmp.addEdge(getID(i, j), n * m + 1, 1, 0);
            }
        cout << -tmp.minCostmaxFlow(0, n * m + 1, k).second << '\n';
    }
}