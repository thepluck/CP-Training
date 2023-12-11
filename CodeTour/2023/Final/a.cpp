#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

template <class X, class Y> bool cmin(X& a, const Y& b) {
  return a > b ? a = b, 1 : 0;
}

template <class X, class Y> bool cmax(X& a, const Y& b) {
  return a < b ? a = b, 1 : 0;
}

using ll = long long;

struct MCMF {
    using ll = long long;

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
  int n, m, c1, c2, p;
  cin >> n >> m >> c1 >> c2 >> p;
  MCMF vu(n * m + p + 2);
  for (int x = n * m + 1; x <= n * m + p; x++) {
    int u, v; char c;
    cin >> c; u = c - '0';
    cin >> c; u = u * 10 + c;
    cin >> c; v = c - '0';
    cin >> c; v = v * 10 + c;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        vu.addEdge(x, (i - 1) * m + j, 1, -(i == u ? c1 : 0) - (j == v ? c2 : 0) - 1);
    vu.addEdge(0, x, 1, 0);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      vu.addEdge((i - 1) * m + j, n * m + p + 2, 1, 0);
  cout << -vu.minCostmaxFlow(0, n * m + p + 2, p).second << '\n';
  return 0;
}