#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int v, w, i;
    
    edge(int v, int w, int i):
    v(v), w(w), i(i) {}
};

const int N = 205;
const int INF = 0x3f3f3f3f;

int dis[N], ans[N * N];
int trace[N], root[N], wei[N * N];
vector <edge> adj[N];
bool mark[N * N], vis[N];

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        adj[i].clear();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v >> wei[i]; u++; v++;
        adj[u].emplace_back(v, wei[i], i);
        adj[v].emplace_back(u, wei[i], i);
    }
    memset(ans, 0x3f, sizeof ans);
    for (int s = 1; s <= n; s++) {
        memset(dis, 0x3f, sizeof dis);
        memset(mark, 0, sizeof mark);
        memset(vis, 0, sizeof vis);
        for (int u = s; u; ) {
            if (u != s) mark[trace[u]] = true;
            else dis[u] = 0;
            for (auto e : adj[u])
                if (cmin(dis[e.v], dis[u] + e.w)) {
                    trace[e.v] = e.i;
                    root[e.v] = u == s ? e.i : root[u];
                }
            vis[u] = true; u = 0;
            for (int v = 1; v <= n; v++)
                if (!vis[v] && dis[v] < dis[u]) u = v;
        }
        for (int u = 1; u <= n; u++) {
            if (u == s) continue;
            for (auto e : adj[u])
                if (!mark[e.i]) {
                    if (e.v == s) {
                        cmin(ans[e.i], dis[u] + e.w);
                        cmin(ans[root[u]], dis[u] + e.w);
                    }
                    else if (root[u] != root[e.v]) {
                        cmin(ans[root[u]],
                        dis[u] + dis[e.v] + e.w);
                    }
                }
        }
    }
    for (int i = 1; i <= m; i++)
        if (ans[i] == INF) printf("impossible\n");
        else printf("%d\n", ans[i] + 1 - wei[i]);
        
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int nTest; cin >> nTest;
    for (int test = 1; test <= nTest; test++) {
        printf("Case %d:\n", test); solve();
    }
}