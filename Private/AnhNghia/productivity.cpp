#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

#define fi first
#define se second

const int N = 205;

int dp[N][N][N];
pair <int, int> seg[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> seg[i].fi >> seg[i].se;
    sort(seg + 1, seg + n + 1);
    memset(dp, 0xc0, sizeof dp);
    dp[1][0][1] = 0; seg[n + 1].fi = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 1; k <= i; k++) {                
                cmax(dp[i + 1][j + 1][k], dp[i][j][k] + seg[i + 1].se - seg[i + 1].fi);
                if (seg[i + 1].fi < seg[k].se)
                    cmax(dp[i + 1][j][seg[i + 1].se < seg[k].se ? i + 1 : k], dp[i][j][k]);
                cmax(dp[i + 1][j + 1][i + 1], dp[i][j][k] + seg[k].se - seg[i].fi);
            }
    cout << max(dp[n + 1][m][n + 1], dp[n + 1][m - 1][n] + seg[n].se - seg[n].fi);
}