#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 3e5 + 5;

ll sum[N], tot[N], dp[N], res;
int cen[N], sz[N], par[N];
vector <pair <int, int>> adj[N];

void DFS1(int u) {
    sz[u] = 1;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        DFS1(v); sz[u] += sz[v];
        dp[u] += dp[v] + ll(w) * sz[v];
    }
}

void DFS2(int u) {
    cen[u] = u;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        tot[v] = tot[u] + ll(w) * sz[v];
        sum[v] = sum[u] + w; DFS2(v);
        int c = cen[v];
        while (sz[c] * 2 <= sz[u])
            c = par[c];
        if (c != u) cen[u] = c;
    }
    int c = cen[u];
    res ^= (sum[c] - sum[u]) * sz[u]
    - (tot[c] - tot[u]) * 2 + dp[u];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int w; cin >> par[i] >> w;
        adj[par[i]].emplace_back(i, w);
    }
    DFS1(0); DFS2(0); cout << res;
}