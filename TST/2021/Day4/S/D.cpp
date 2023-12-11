#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 1005;
const int INF = 0x3f3f3f3f;

using ii = pair <int, int>;

/// not exact value
int dp[N][N]; ii pt[N];

int main() {
    freopen("dp.inp", "r", stdin);
    freopen("dp.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        cin >> pt[i].fi >> pt[i].se;
    sort(pt + 1, pt + n + 1);
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = -INF;
    for (int i = 1; i <= n; i++) {
        int k = i;
        while (k < n && pt[k + 1].fi - pt[i].fi <= 2 * t) k++;
        for (int j = 0; j <= n; j++) {
            if (max(dp[i - 1][j], pt[i].fi - t - 1) + pt[i].se <= pt[i].fi + t)
                cmin(dp[i][j], max(dp[i - 1][j], pt[i].fi - t - 1) + pt[i].se);
            cmin(dp[k][j + 1], dp[i - 1][j]);
        }
    }
    for (int j = 0; j <= n; j++)
        if (dp[n][j] != INF) {
            cout << j << '\n'; return 0;
        }
}