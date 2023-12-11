#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 105;

int h[N], mx[N][N], dp[N][N][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, x, y, u, v;
    cin >> n >> x >> y >> u >> v;
    memset(mx, 0xc0, sizeof mx);
    memset(dp, 0x3f, sizeof dp);
    dp[n][n][1] = 0;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            mx[i][j] = max(mx[i][j - 1], h[j]);
    for (int i = n; i > 0; i--)
        for (int j = n; j > 0; j--)
            for (int t = i == j; t <= (i <= j); t++) {
                for (int k = min(i, j) - 1; k > 0; k--) {
                    if (h[j] - t - 1 > (i >= j ? mx[k][j - 1]
                    : max(mx[k][i - 1], h[i] - 1)))
                        cmin(dp[i][k][0], dp[i][j][t] + (j - k) * v);
                    if (h[k] - 1 > mx[k + 1][i] &&
                    (k == j - 1 || h[k] < h[j] - t))
                        cmin(dp[k][j][t], dp[i][j][t] + (i - k) * y);
                }
                if (i < j && h[j] - t > h[i])
                    cmin(dp[i][i][1], dp[i][j][t] + (j - i) * v);
                if (j - 1 <= i)
                    cmin(dp[i][j - 1][i == j - 1], dp[i][j][t] + u *
                    max(h[j - 1] - (i == j - 1) - h[j] + 1 + t, 0));
                if (i - 1 < j && (i == j || h[i - 1] < h[j] - t))
                    cmin(dp[i - 1][j][t], dp[i][j][t] +
                    max(h[i] - h[i - 1] + 1, 0) * x);
            }
    cout << dp[1][1][1] << '\n';
}