#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 200005;
const ll INF = 1e18;

ll dp[N][2][2];
vector<pair<int, int>> adj[N];

void add(ll &x, ll y) {
    x = max(x + y, -INF);    
}

void dfs(int u, int p) {
    ll sum = 0;
    pair<ll, ll> best01(-INF, -INF);
    ll best10 = -INF;
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        if (v == p) continue; dfs(v, u);
        add(dp[u][0][0], max(dp[v][0][0], dp[v][1][0] + w));
        add(dp[u][0][1], max({dp[v][0][0], dp[v][1][0] + w,
                            dp[v][0][1], dp[v][1][1] + w}));
        add(sum, max(dp[v][0][0], dp[v][1][0] + w));
        ll tmp = max(dp[v][0][0], dp[v][0][1])
        + w - max(dp[v][0][0], dp[v][1][0] + w);
        if (best01.first < tmp) {
            best01.second = best01.first;
            best01.first = tmp;
        } else best01.second = max(best01.second, tmp);
        best10 = max(best10, dp[v][0][0] + w
        - max(dp[v][0][0], dp[v][1][0] + w));
    }
    dp[u][1][0] = dp[u][1][1] = sum;
    add(dp[u][1][0], best10);
    add(dp[u][1][1], best01.first);
    add(sum, best01.first);
    add(sum, best01.second);
    dp[u][0][1] = max(dp[u][0][1], sum);
    cerr << u << '\n';
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            cerr << dp[u][x][y] << ' ';
    cerr << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 0); cout << max(dp[1][0][0], dp[1][0][1]);
}