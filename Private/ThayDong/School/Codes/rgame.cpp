#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

long long a[N], dp[N][2];

int main() {
    freopen("rgame.inp", "r", stdin);
    freopen("rgame.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i]; a[i] += a[i];
        }
        dp[n][1] = a[n - 1]; dp[n][0] = 0;
        for (int i = n - 1; i > 0; i--) {
            dp[i][1] = max(dp[i + 1][0]
            + (a[i + 1] + a[i - 1]) / 2,
            dp[i + 1][1] + a[i - 1]);
            dp[i][0] = max(dp[i + 1][0]
            + a[i + 1], dp[i + 1][1]);
        }
        cout << dp[1][0] / 2 << (
        dp[1][0] & 1 ? ".5\n" : ".0\n");
    }
}