#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

using ll = long long;

int deg[N], cost[N], idx[N];
vector <int> adj[N];
ll sos[1 << 15]; bool vis[N];
vector <int> path;
int dp[N][2];

void DFS(int u) {
    vis[u] = 1; path.push_back(u);
    for (int v : adj[u])
        if (!vis[v]) DFS(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    int cnt = 0;
    for (int u = 1; u <= n; u++)
        if (adj[u].size() >= 3) {
            idx[u] = ++cnt; vis[u] = 1;
            for (int v : adj[u]) {
                deg[v]--;
                if (idx[v])
                    sos[(1 << (idx[u] - 1)) |
                    (1 << (idx[v] - 1))] = -0x3f3f3f3f;
            }
            sos[1 << (idx[u] - 1)] += cost[u];
        }
    for (int u = 1; u <= n; u++)
        if (!vis[u] && deg[u] < 2) {
            path.clear(); DFS(u);
            int len = path.size(), big1 = 0, big2 = 0;
            for (int i = 0; i < len; i++) {
                dp[i + 1][0] = max(dp[i][0], dp[i][1]);
                dp[i + 1][1] = dp[i][0] + cost[path[i]];
            }
            int keep = max(dp[len][0], dp[len][1]);
            sos[0] += keep; int take1 = dp[len][0];
            dp[1][1] = dp[1][0] = 0;
            for (int i = 1; i < len; i++) {
                dp[i + 1][0] = max(dp[i][0], dp[i][1]);
                dp[i + 1][1] = dp[i][0] + cost[path[i]];
            }
            int take0 = max(dp[len][0], dp[len][1]);
            int take2 = dp[len][0];
            for (int v : adj[path.front()])
                if (idx[v]) {
                    big1 = idx[v]; break;
                }
            for (int v : adj[path.back()])
                if (idx[v]) big2 = idx[v];
            if (big1) sos[1 << (big1 - 1)] += take0 - keep;
            if (big2) sos[1 << (big2 - 1)] += take1 - keep;
            if (big1 && big2)
                sos[(1 << (big1 - 1)) | (1 << (big2 - 1))]
                += take2 - take0 - take1 + keep;
        }
    for (int u = 1; u <= n; u++)
        if (!vis[u]) {
            path.clear(); DFS(u);
            int len = path.size();
            for (int i = 0; i < len; i++) {
                dp[i + 1][0] = max(dp[i][0], dp[i][1]);
                dp[i + 1][1] = dp[i][0] + cost[path[i]];
            }
            int keep = dp[len][0];
            dp[1][1] = dp[1][0] = 0;
            for (int i = 1; i < len; i++) {
                dp[i + 1][0] = max(dp[i][0], dp[i][1]);
                dp[i + 1][1] = dp[i][0] + cost[path[i]];
            }
            sos[0] += max({keep, dp[len][0], dp[len][1]});
        }
    for (int i = 0; i < cnt; i++)
        for (int mask = 0; mask < (1 << cnt); mask++)
            if (mask >> i & 1)
                sos[mask] += sos[mask ^ (1 << i)];
    ll res = 0;
    for (int mask = 0; mask < (1 << cnt); mask++)
        res = max(res, sos[mask]);
    cout << res << '\n';
}