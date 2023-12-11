#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int MAXN = 1005;

int dis[MAXN];
bool vis[MAXN], imp[MAXN];
vector <int> adj[MAXN];

void DFS(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) DFS(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector <pair <int, int>> org;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        org.emplace_back(u, v);
        adj[u].push_back(v);
    }
    DFS(1); swap(vis, imp);
    for (int i = 1; i <= N; i++)
        adj[i].clear();
    for (auto e : org) {
        int u, v; tie(u, v) = e;
        adj[v].push_back(u);
    }
    DFS(N);
    for (int i = 1; i <= N; i++)
        if (!vis[i]) imp[i] = 0;
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 1; i < N; i++) {
        for (auto e : org) {
            int u, v; tie(u, v) = e;
            if (imp[u] && imp[v]) {
                cmin(dis[v], dis[u] + 2);
                cmin(dis[u], dis[v] - 1);
            }
        }
    }
    for (auto e : org) {
        int u, v; tie(u, v) = e;
        if (imp[u] && imp[v]) {
            if (cmin(dis[v], dis[u] + 2))
                return cout << "No\n", 0;
            if (cmin(dis[u], dis[v] - 1))
                return cout << "No\n", 0;
        }
    }
    cout << "Yes\n";
    for (auto e : org) {
        int u, v; tie(u, v) = e;
        if (imp[u] && imp[v])
            cout << dis[v] - dis[u] << '\n';
        else cout << 1 << '\n';
    }
}
