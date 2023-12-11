#include <bits/stdc++.h>
using namespace std;

#define popcnt __builtin_popcount

using ll = long long;

const int N = 17;

ll dp[1 << N], a[N][N];

void solve() {
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int m = 1; m < (1 << n); m++) {
        int i = popcnt(m);
        for (int j = 0; j < n; j++)
            if (m >> j & 1)
                dp[m] = min(dp[m],
                dp[m ^ (1 << j)] + a[i][j + 1]);
    }
    cout << dp[(1 << n) - 1] << '\n';
}

int main() {
    freopen("game8.inp", "r", stdin);
    freopen("game8.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}