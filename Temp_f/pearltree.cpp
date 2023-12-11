#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1000000007;
const int N = 300005;

int dp[N][16], a[N], tmp[16];
vector <int> adj[N];

int encode(char x) {
    if (x == 'D') return 3;
    if (x == 'X') return 2;
    if (x == 'L') return 1;
    return 0;
}

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

void dfs(int u, int p = 0) {
    dp[u][1 << a[u]] = 1;
    for (int v : adj[u]) {
        if (v == p) continue; dfs(v, u);
        for (int i = 0; i < 14; i++)
            tmp[i] = 0;
        for (int i = 0; i < 14; i++) {
            for (int j = 0; j < 14; j++) {
                tmp[i] = madd(tmp[i],
                mmul(dp[u][i], dp[v][j]));
                tmp[i | j] = madd(tmp[i | j],
                mmul(dp[u][i], dp[v][j]));
            }
        }
        for (int i = 0; i < 14; i++)
            dp[u][i] = tmp[i];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        a[i] = encode(x);
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); int res = 0;
    for (int i = 0; i < 14; i++)
        res = madd(res, dp[1][i]);
    cout << res << '\n';
}