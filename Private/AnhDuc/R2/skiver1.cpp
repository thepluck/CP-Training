#include <bits/stdc++.h>

using namespace std;

struct MaxFLow {
    vector <int> head, dist, work;
    vector <int> to, nxt, flow, capa;
    queue <int> que;

    void init(int n) {
        head.assign(n + 5, -1);
        dist.assign(n + 5, 0);
        work.assign(n + 5, 0);
        to.clear(); nxt.clear();
        flow.clear(); capa.clear();
    }

    void addEdge(int u, int v, int c, bool r = 0) {
        to.push_back(v); nxt.push_back(head[u]);
        flow.push_back(0); capa.push_back(c);
        head[u] = to.size() - 1;
        to.push_back(u); nxt.push_back(head[v]);
        flow.push_back(0); capa.push_back(c * r);
        head[v] = to.size() - 1;
    }

    bool BFS(int s, int t) {
        fill(dist.begin(), dist.end(), -1);
        dist[s] = 0; que.push(s);
        while (que.size()) {
            s = que.front(); que.pop();
            for (int i = head[s]; i >= 0; i = nxt[i])
                if (capa[i] > flow[i] && dist[to[i]] < 0) {
                    dist[to[i]] = dist[s] + 1; que.push(to[i]);
                }
        }
        return dist[t] >= 0;
    }

    int DFS(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = nxt[i])
            if (capa[i] > flow[i] && dist[to[i]] == dist[s] + 1) {
                int d = DFS(to[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d; flow[i ^ 1] -= d; return d;
                }
            }
        return 0;
    }

    int maxFlow(int s, int t) {
        int res = 0, aug = 0;
        while (BFS(s, t)) {
            copy(head.begin(), head.end(), work.begin());
            while ((aug = DFS(s, t, INT_MAX)) > 0) res += aug;
        }
        return res;
    }

    int Find(int u, int v) {
        for (int i = head[u]; i >= 0; i = nxt[i])
            if (to[i] == v) return flow[i];
    }
};

struct BoundedFLow {
    MaxFLow MF; int n, sum = 0;

    void init(int n, int s, int t) {
        MF.init(this->n = n);
        MF.addEdge(t, s, INT_MAX);
        sum = 0;
    }

    void addEdge(int u, int v, int c, int d) {
        MF.addEdge(n + 1, v, c);
        MF.addEdge(u, n + 2, c);
        MF.addEdge(u, v, d - c);
        sum += c;
    }

    bool solve() {
        return sum == MF.maxFlow(n + 1, n + 2);
    }
};

const int N = 5005;

vector <int> adj[N], rev[N], ord;
int cmp[N];

void DFS1(int u) {
    cmp[u] = 0;
    for (int v : adj[u])
        if (cmp[v] < 0) DFS1(v);
    ord.push_back(u);
}

void DFS2(int u, int num) {
    cmp[u] = num;
    for (int v : rev[u])
        if (cmp[v] == 0) DFS2(v, num);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    BoundedFLow MF;
    for (int i = 1; i < n; i++) {
        int k; cin >> k;
        while (k--) {
            int j; cin >> j;
            adj[i].push_back(j);
            rev[j].push_back(i);
        }
    }
    memset(cmp, -1, sizeof cmp);
    for (int u = 1; u <= n; u++)
        if (cmp[u] < 0) DFS1(u);
    reverse(ord.begin(), ord.end());
    int num = 0;
    for (int u : ord) 
        if (cmp[u] == 0) DFS2(u, ++num);
    for (int i = 1; i <= num; i++)
        rev[i].clear();
    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
            if (cmp[u] != cmp[v])
                rev[cmp[u]].push_back(cmp[v]);
    MF.init(n + 2, 0, n + 1);
    MF.addEdge(0, 1, 0, n * n);
    MF.addEdge(n, n + 1, 0, n * n);
    for (int i = 1; i <= num; i++)
        for (int j : rev[i])
            MF.addEdge(i, j, 1, n * n);
    MF.solve(); 
    cout << MF.MF.Find(0, 1);
}