#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2005;
const int MOD = 1e9 + 7;

int dp[N][N];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, s, t; cin >> n >> s >> t;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++) {
            if (i == s || i == t)
                dp[i][j] = madd(dp[i - 1][j - 1], dp[i - 1][j]);
            else dp[i][j] = madd(mmul(dp[i - 1][j + 1], j),
            mmul(dp[i - 1][j - 1], j - (i > s) - (i > t)));
        }
    cout << dp[n][1] << '\n';
}