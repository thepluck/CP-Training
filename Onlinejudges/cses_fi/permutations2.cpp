#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

long long dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    dp[0] = dp[1] = 1;
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] * (i + 1) % MOD;
        (dp[i] -= dp[i - 2] * (i - 2)) %= MOD;
        (dp[i] -= dp[i - 3] * (i - 5)) %= MOD;
        (dp[i] += dp[i - 4] * (i - 3)) %= MOD;
    }
    if (dp[n] < 0) dp[n] += MOD;
    cout << dp[n] << '\n';
}