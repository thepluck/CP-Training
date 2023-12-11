#include <bits/stdc++.h>

using namespace std;

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

    int Find(int u) {
        for (int i = head[u]; i >= 0; i = nxt[i])
            if (flow[i]) return to[i];
    }
};

struct edge {
    int u, v, a, b;
};

const int N = 10005;

vector <int> circut; bool vis[N];
vector <pair <int, int>> adj[N];
int deg[N], n, m;
edge ed[N]; DinicFlow dinic;

bool check(int lim) {
    dinic.init(n + m + 2);
    for (int i = 1; i <= m; i++) {
        dinic.addEdge(0, i, 1);
        if (ed[i].a <= lim)
            dinic.addEdge(i, ed[i].u + m, 1);
        if (ed[i].b <= lim)
            dinic.addEdge(i, ed[i].v + m, 1);
    }
    for (int u = 1; u <= n; u++)
        dinic.addEdge(u + m, n + m + 1, deg[u] / 2);
    return dinic.maxFlow(0, n + m + 1) == m;
}

void DFS(int u, int i) {
    for (auto e : adj[u])
        if (!vis[e.second]) {
            vis[e.second] = 1;
            DFS(e.first, e.second);
        }
    if (i) circut.push_back(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    int lo = 0, hi = 0, ans = -1;
    for (int i = 1; i <= m; i++) {
        cin >> ed[i].u >> ed[i].v;
        cin >> ed[i].a >> ed[i].b;
        lo = max(lo, min(ed[i].a, ed[i].b));
        hi = max(hi, max(ed[i].a, ed[i].b));
        deg[ed[i].u]++; deg[ed[i].v]++;
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] & 1) {
            cout << "-1\n"; return 0;
        }
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (check(mi)) {
            ans = mi; hi = mi - 1;
        }
        else lo = mi + 1;
    }
    cout << ans << '\n';
    if (ans <= 0) return 0;
    assert(check(ans));
    for (int i = 1; i <= m; i++)
        if (dinic.Find(i) - m == ed[i].u)
            adj[ed[i].u].emplace_back(ed[i].v, i);
        else adj[ed[i].v].emplace_back(ed[i].u, i);
    DFS(1, 0);
    reverse(circut.begin(), circut.end());
    for (int i : circut) cout << i << ' ';
}