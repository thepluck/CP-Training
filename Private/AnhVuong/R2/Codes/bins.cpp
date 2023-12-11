#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = N * N;
const int MOD = 1e9 + 9;

int dp[2][N][M * 2 + 5];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    dp[0][0][M] = 1;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        memcpy(dp[i & 1], dp[~i & 1], sizeof dp[i & 1]);
        for (int j = 0; j <= n; j++) {
            for (int k = x; k <= M * 2; k++)
                dp[i & 1][j][k] = add(dp[i & 1][j][k],
                mul(dp[~i & 1][j + 1][k - x],
                (j + 1) * (j + 1)));
            for (int k = 0; k <= M * 2; k++) {
                dp[i & 1][j][k] = add(dp[i & 1][j][k],
                mul(mul(dp[~i & 1][j][k], j), 2));
            }
            for (int k = 0; k <= M * 2 - x; k++)
                dp[i & 1][j + 1][k] = add(dp[i & 1][j + 1][k],
                dp[~i & 1][j][k + x]);
        }
    }
    cout << dp[n & 1][0][m + M] << '\n';
}
