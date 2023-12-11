// Problem: E. President's Path
// Contest: Codeforces - Codeforces Round #241 (Div. 2)
// URL: https://codeforces.com/problemset/problem/416/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int v, w;
    
    edge(int v, int w): v(v), w(w) {}
    
    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 505;

bitset <N> can[N];
vector <edge> adj[N];
priority_queue <edge> pq;
int ans[N][N], n, m, dis[N];

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof dis);
    pq.emplace(s, dis[s] = 0);
    vector <int> ord;
    while (pq.size()) {
        edge t = pq.top(); pq.pop();
        if (dis[t.v] < t.w) continue;
        ord.push_back(t.v);
        can[t.v].reset();
        for (edge e : adj[t.v])
            if (cmin(dis[e.v], t.w + e.w))
                pq.emplace(e.v, dis[e.v]);
    }
    reverse(ord.begin(), ord.end());
    for (int u : ord) {
        int cnt = 0; can[u][u] = 1;
        for (edge e : adj[u]) {
            if (dis[u] + e.w == dis[e.v])
                can[u] |= can[e.v];
            if (dis[u] == dis[e.v] + e.w)
                cnt++;
        }
        for (int v : ord)
            if (can[u][v])
                ans[s][v] += cnt;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++)
        dijkstra(i);
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cout << ans[i][j] << ' ';
}