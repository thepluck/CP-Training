#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back

using ii = pair <int, int>;
int dp[3005][3005], pre[3005][3005];

int main(){
    freopen("ncutcir.inp", "r", stdin);
    freopen("ncutcir.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, ma = INT_MIN, mi = INT_MAX; cin >> n;
    for (int i = 1; i <= n; i++) {
        int c, r; cin >> c >> r;
        c += 1001; pre[c - r][c + r] = 1;
        ma = max(ma, c + r);
        mi = min(mi, c - r);
    }
    for (int i = ma - 1; i >= mi; i--)
        for (int j = mi; j <= ma; j++){
            dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            for (int k = i + 1; k < j; k++)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            dp[i][j] += pre[i][j];
        }
    cout << n - dp[mi][ma];
}