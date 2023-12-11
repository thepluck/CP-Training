#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 5005;
const int inf = 0x3f3f3f3f;

int dp[N][N], a[N], sz[N];
vector <int> adj[N];

void dfs(int u, int p) {
    bool leaf = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u); sz[u] += sz[v];
        if (leaf) {
            for (int i = 0; i <= sz[v]; i++)
                dp[u][i] = dp[v][i];
            leaf = 0; continue;
        }
        for (int i = sz[u]; ~i; i--) {
            int tmp = inf;
            for (int j = min(sz[v], i); ~j; j--)
                cmin(tmp, dp[u][i - j] + dp[v][j]);
            dp[u][i] = tmp;
        }
    }
    if (leaf) {
        sz[u] = 1; dp[u][0] = dp[u][1] = 0;
    }
    for (int i = 0; i <= sz[u]; i++)
        dp[u][i] += abs(a[u] - i);
}

int main() {
    freopen("stree.inp", "r", stdin);
    freopen("stree.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(dp, 0x3f, sizeof dp);
    dfs(1, 0); int res = inf;
    for (int i = 0; i <= sz[1]; i++)
        cmin(res, dp[1][i]);
    cout << res << '\n';
}