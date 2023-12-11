#include <bits/stdc++.h>

using namespace std;

#define il i * 2
#define ir i * 2 + 1

using ll = long long;

const int N = 1005;

ll a[N], b[N], sa[N], sb[N], ca[N], cb[N];
ll dp[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> sa[i] >> ca[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i] >> sb[i] >> cb[i];
        b[i] += b[i - 1];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) continue;
            dp[i][j] = -1e18;
            if (i > 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]
                + (a[i] + b[j] <= sa[i] ? ca[i] : 0));
            if (j > 0)
                dp[i][j] = max(dp[i][j], dp[i][j - 1]
                + (a[i] + b[j] <= sb[j] ? cb[j] : 0));
        }
    cout << dp[n][m] << '\n';
    // int i = n, j = m;
    // string res;
    // while (i > 0 || j > 0) {
        // if (i > 0 && dp[i][j] == dp[i - 1][j]
        // + (a[i] + b[j] <= sa[i] ? ca[i] : 0)) {
            // if (a[i] + b[j] <= sa[i])
                // cout << ca[i] << '\n';
            // i--; res.push_back('a');
// 
        // } else {
            // if (a[i] + b[j] <= sb[j])
                // cout << cb[j] << '\n';
            // j--; res.push_back('b');
        // }
    // }
    // reverse(res.begin(), res.end());
    // cout << res;
}