#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int sz[N], par[N], n;
vector <pair <int, int>> adj[N];
long long res = 0;

void DFS(int u) {
    sz[u] = 1;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v != par[u]) {
            par[v] = u; DFS(v);
            sz[u] += sz[v];
            res += (long long)w
            * min(sz[v], n - sz[v]);
        }
    }
}

int findCen() {
    int u = 1;
    while (1) {
        bool flag = 0;
        for (auto e : adj[u]) {
            int v; tie(v, ignore) = e;
            if (v != par[u] &&
            sz[v] * 2 >= n) {
                u = v; flag = 1; break;
            }
        }
        if (flag) continue; break;
    }
    return u;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    DFS(1); res *= 2;
    int u = findCen();
    if (sz[u] * 2 == n) {
        for (auto e : adj[u]) {
            int v, w; tie(v, w) = e;
            if (v == par[u]) res -= w;
        }
    }
    else {
        int mi = INT_MAX;
        for (auto e : adj[u]) {
            int v, w; tie(v, w) = e;
            mi = min(mi, w);
        }
        res -= mi;
    }
    cout << res << '\n';
}