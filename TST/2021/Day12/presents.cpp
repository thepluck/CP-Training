#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int par[N], val[N], cost[N][2];
vector <int> adj[N];
int vis[N], timer;
long long dp1[N][2], dp2[N][2];

void DFS(int u) {
    vis[u] = timer;
    for (int v : adj[u]) if (!vis[v]) {
        DFS(v);
        dp1[u][0] += max(dp1[v][0] + cost[u][0] *
        val[v], dp1[v][1] + cost[u][1] * val[v]);
        dp1[u][1] += max(dp1[v][0] + cost[u][1] *
        val[v], dp1[v][1] + cost[u][0] * val[v]);
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> par[i] >> val[i];
        cin >> cost[i][0] >> cost[i][1];
        adj[par[i]].push_back(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        timer++; int u = i;
        while (vis[u] != timer) {
            vis[u] = timer; u = par[u];
        }
        timer++; vector <int> path;
        while (vis[u] != timer) {
            DFS(u); vis[u] = timer;
            path.push_back(u); u = par[u];
        }
        dp2[0][0] = dp1[path[0]][0];
        dp2[0][1] = -1e18;
        int m = path.size();
        for (int i = 0; i + 1 < m; i++) {
            dp2[i + 1][0] = max(
            dp2[i][0] + cost[path[i + 1]][0] * val[path[i]],
            dp2[i][1] + cost[path[i + 1]][1] * val[path[i]]);
            dp2[i + 1][1] = max(
            dp2[i][0] + cost[path[i + 1]][1] * val[path[i]],
            dp2[i][1] + cost[path[i + 1]][0] * val[path[i]]);
            dp2[i + 1][0] += dp1[path[i + 1]][0];
            dp2[i + 1][1] += dp1[path[i + 1]][1];
        }
        long long tmp = max(
        dp2[m - 1][0] + cost[path[0]][0] * val[path[m - 1]],
        dp2[m - 1][1] + cost[path[0]][1] * val[path[m - 1]]);
        dp2[0][0] = -1e18;
        dp2[0][1] = dp1[path[0]][1];
        for (int i = 0; i + 1 < m; i++) {
            dp2[i + 1][0] = max(
            dp2[i][0] + cost[path[i + 1]][0] * val[path[i]],
            dp2[i][1] + cost[path[i + 1]][1] * val[path[i]]);
            dp2[i + 1][1] = max(
            dp2[i][0] + cost[path[i + 1]][1] * val[path[i]],
            dp2[i][1] + cost[path[i + 1]][0] * val[path[i]]);
            dp2[i + 1][0] += dp1[path[i + 1]][0];
            dp2[i + 1][1] += dp1[path[i + 1]][1];
        }
        tmp = max({tmp,
        dp2[m - 1][0] + cost[path[0]][1] * val[path[m - 1]],
        dp2[m - 1][1] + cost[path[0]][0] * val[path[m - 1]]});
        res += tmp;
    }
    cout << res << '\n';
}