#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int idx[MAXN], loop[MAXN], dis[MAXN];
vector <int> adj[MAXN], ord;
vector <pair <int, int>> rev[MAXN];

void DFS1(int u) {
    idx[u] = 0;
    for (int v : adj[u])
        if (idx[v] < 0) DFS1(v);
    ord.emplace_back(u);
}

void DFS2(int u, int num) {
    idx[u] = num;
    for (auto e : rev[u]) {
        int v, w; tie(v, w) = e;
        if (!idx[v]) {
            dis[v] = dis[u] + w;
            DFS2(v, num);
        } else if (idx[u] == idx[v])
            loop[idx[u]] = __gcd
            (loop[idx[u]],
            abs(dis[u] + w - dis[v]));
    } 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, num = 0; cin >> N >> M;
    memset(idx, -1, sizeof idx);
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v);
        rev[v].emplace_back(u, w);
    }
    for (int u = 1; u <= N; u++)
        if (idx[u] < 0) DFS1(u);
    reverse(ord.begin(), ord.end());
    for (int u : ord)
        if (!idx[u]) DFS2(u, ++num);
    for (int i = 1; i <= N; i++)
        cout << (loop[idx[i]] ?
        loop[idx[i]] : -1) << '\n';
}