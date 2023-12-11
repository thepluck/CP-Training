#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 305;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int dp[N][N][2], a[N];
bool can[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; dp[i][i][1] = 1;
        for (int j = 1; j < i; j++)
            can[j][i] = __gcd(a[j], a[i]) > 1;
    }
    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k <= j; k++) {
                if (can[i][j])
                    dp[i][j][0] = add(dp[i][j][0],
                    mul(dp[i][k - 1][1], dp[k][j][1]));
                if (can[i][k])
                    dp[i][j][1] = add(dp[i][j][1],
                    mul(dp[i][k][0], dp[k][j][1]));
            }
        }
    cout << dp[1][n][1] << '\n';
}