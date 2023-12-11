#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const int N = 5005;
int c[N], d[N], sz[N];
ll dp[N][N][2];
vector <int> adj[N];

void dfs(int u) {
    dp[u][0][0] = dp[u][0][1] = 0;
    for (int v : adj[u]) {
        dfs(v);
        for (int i = sz[u]; ~i; i--)
            for (int j = sz[v]; j; j--) {
                chkmin(dp[u][i + j][0],
                dp[u][i][0] + dp[v][j][0]);
                chkmin(dp[u][i + j][1],
                dp[u][i][1] + min(dp[v][j][1],
                dp[v][j][0]));
            }
        sz[u] += sz[v];
    }
    sz[u]++;
    for (int i = sz[u]; i; i--) {
        dp[u][i][1] = dp[u][i - 1][1] + d[u];
        chkmin(dp[u][i][0], dp[u][i - 1][0] + c[u]);
    }
}

int main() {
    freopen("shopping.inp", "r", stdin);
    freopen("shopping.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, b; cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
        d[i] = c[i] - d[i];
        if (i > 1) {
            int p; cin >> p;
            adj[p].push_back(i);
        }
    }
    memset(dp, 0x3f, sizeof dp); dfs(1);
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dp[1][i][0] <= b ||
            dp[1][i][1] <= b) res = i;
    cout << res << '\n';
}
