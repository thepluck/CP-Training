#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 605;
const int MOD = 1e9 + 7;

int to[N], sum[N];
ll dp[N][N], g[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        to[u] = v; to[v] = u;
        sum[u]++; sum[v]++;
    }
    n *= 2; g[0] = 1;
    for (int i = 1; i <= n; i++)
        sum[i] += sum[i - 1];
    for (int i = 2; i <= n; i += 2)
        g[i] = g[i - 2] * (i - 1) % MOD;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j += 2) {
            bool flag = 0;
            for (int k = i; k <= j; k++)
                if (to[k] && (to[k] < i || to[k] > j))
                    flag = 1;
            if (flag) continue;
            dp[i][j] = g[j - i + 1 - sum[j] + sum[i - 1]];
            for (int k = i + 1; k < j; k += 2)
               (dp[i][j] -= dp[i][k] * g[j - k - sum[j] + sum[k]]) %= MOD;
        }
    m *= 2; ll res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j += 2)
            (res += dp[i][j] * g[n - j + i - 1 - m + sum[j] - sum[i - 1]]) %= MOD;
    cout << (res + MOD) % MOD << '\n';
}