#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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
 
    ll maxFlow(int s, int t) {
        ll tot = 0, aug;
        while (BFS(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = DFS(s, t, INT_MAX)) > 0) tot += aug;
        }
        return tot;
    }
};

const int N = 3005;

int main() {
    freopen("stadium.inp", "r", stdin);
    freopen("stadium.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> n >> m;
    DinicFlow dinic;
    dinic.init(n + m + 2);
    for (int i = 1; i <= n; i++) {
        int r; cin >> r;
        dinic.addEdge(0, i, r);
    }
    for (int i = 1; i <= m; i++) {
        int c; cin >> c;
        dinic.addEdge(i + n, n + m + 1, c);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == '1')
                dinic.addEdge(i, j + n, INT_MAX);
        }
    cout << dinic.maxFlow(0, n + m + 1) << '\n';
    dinic.BFS(0, n + m + 1);
    vector <int> row, col;
    for (int i = 1; i <= n; i++)
        if (dinic.dist[i] < 0)
            row.push_back(i);
    for (int i = 1; i <= m; i++)
        if (dinic.dist[i + n] >= 0)
            col.push_back(i);
    cout << row.size() << ' ';
    for (int i : row) cout << i << ' ';
    cout << '\n' << col.size() << ' ';
    for (int i : col) cout << i << ' ';
}