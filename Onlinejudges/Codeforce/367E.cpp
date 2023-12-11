#include <bits/stdc++.h>
using namespace std;

const int N = 305;
const int MOD = 1e9 + 7;

int dp[2][N][N];
/// dp[j][k] = j groups, k closed groups

void madd(int &x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, x;
    cin >> n >> m >> x;
    if (n > m) {
        cout << "0\n"; return 0; 
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= m; i++) {
        bool c = i & 1;
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= j; k++) {
                int &add = dp[!c][j][k];
                if (j < n) {
                    /// open and close
                    madd(dp[c][j + 1][k + 1], add);
                    /// just open
                    madd(dp[c][j + 1][k], add);
                }
                if (i != x) {
                    if (k < j)
                        /// close one
                        madd(dp[c][j][k + 1], add);
                    /// do nothing
                    madd(dp[c][j][k], add);
                }
                add = 0;
            }
    }
    int ans = dp[m & 1][n][n];
    for (int j = 1; j <= n; j++)
        ans = 1ll * ans * j % MOD;
    cout << ans << '\n';
}