#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int K = 5005;

ll dp[K][K];

ll mpow(ll x, ll k) {
    ll res = 1;
    for (; k; k >>= 1, x = x * x % MOD)
        if (k & 1) res = res * x % MOD;
    return res;
}

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i <= min(n, k); i++)
        dp[0][i] = mpow(2, n - i);
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= min(n, k); j++) {
            dp[i][j] = dp[i - 1][j + 1] * (n - j) % MOD;
            (dp[i][j] += dp[i - 1][j] * j) %= MOD;
        }
    cout << dp[k][0] << '\n';
}