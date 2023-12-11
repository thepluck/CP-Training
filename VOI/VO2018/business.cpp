#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int inf = 0x3f3f3f3f;

int n, k; bool bad[N];
int dp[N], dis[N], res;
vector <int> adj[N];
queue <int> q;

void input() {
    cin >> n >> k;
    fill_n(dis + 1, n, inf);
    for (int i = 0; i < k; i++) {
        int u; cin >> u;
        q.push(u); dis[u] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs() {
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (dis[v] == inf) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
    }
}

void dfs_bad(int u, int p = 0) {
    for (int v : adj[u])
        if (v != p) {
            dfs_bad(v, u);
            bad[u] |= bad[v];
        }
}

void dfs_dp(int u, int p = 0) {
    dp[u] = 0;
    for (int v : adj[u])
        if (v != p && bad[v]) {
            dfs_dp(v, u);
            res = max(res, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
}

bool check(int d) {
    int u = res = 0;
    for (int i = 1; i <= n; i++)
        if (dis[i] > d) {
            u = i; bad[i] = 1;
        }
        else bad[i] = 0;
    if (u == 0) return 1;
    dfs_bad(u); dfs_dp(u);
    return (res + 1) / 2 <= d;
}

void process() {
    bfs(); int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (check(m)) r = m;
        else l = m + 1;
    }
    cout << r << '\n';
}

int main() {
    freopen("business.inp", "r", stdin);
    freopen("business.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    input(); process();
}