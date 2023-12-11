#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 205;
const int K = 1005;
const int MOD = 1e9 + 7;

int dp[2][N][K]; int a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            for (int k = 0; k <= m; k++) {
                ll add = dp[0][j][k];
                int bal = k + j * (a[i + 1] - a[i]);
                if (bal <= m) {
                    dp[1][j][bal] += add * (j + 1) % MOD;
                    if (dp[1][j][bal] > MOD)
                        dp[1][j][bal] -= MOD;
                    dp[1][j + 1][bal] += add;
                    if (dp[1][j + 1][bal] > MOD)
                        dp[1][j + 1][bal] -= MOD;
                    if (j) {
                        dp[1][j - 1][bal] += add * j % MOD;
                        if (dp[1][j - 1][bal] > MOD)
                            dp[1][j - 1][bal] -= MOD;
                    }
                }
            }
        for (int j = 0; j <= i + 1; j++)
            for (int k = 0; k <= m; k++) {
                dp[0][j][k] = dp[1][j][k];
                dp[1][j][k] = 0;
            }
    }
    int ans = 0;
    for (int k = 0; k <= m; k++) {
        ans += dp[0][0][k];
        if (ans > MOD) ans -= MOD;
    }
    cout << ans << '\n';
}