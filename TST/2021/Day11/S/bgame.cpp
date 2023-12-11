#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

using ll = long long;

int n, t, r, d, e;
int c[10], p[505][10];
ll dp[21][21][21][21][21];

void solve1() {
    memset(dp, 0xc0, sizeof dp);
    dp[0][0][0][0][0] = t;
    for (int turn = 1; turn <= r; turn++) {
        for (int s1 = c[1]; s1 >= 0; s1--)
            for (int s2 = c[2]; s2 >= 0; s2--)
                for (int s3 = c[3]; s3 >= 0; s3--)
                    for (int s4 = c[4]; s4 >= 0; s4--)
                        for (int s5 = c[5]; s5 >= 0; s5--) {
                            int tmp = dp[s1][s2][s3][s4][s5];
                            if (tmp < 0) continue;
                            if (s1) cmax(dp[s1 - 1][s2][s3][s4][s5], tmp + p[turn][1] - e);
                            if (s2) cmax(dp[s1][s2 - 1][s3][s4][s5], tmp + p[turn][2] - e);
                            if (s3) cmax(dp[s1][s2][s3 - 1][s4][s5], tmp + p[turn][3] - e);
                            if (s4) cmax(dp[s1][s2][s3][s4 - 1][s5], tmp + p[turn][4] - e);
                            if (s5) cmax(dp[s1][s2][s3][s4][s5 - 1], tmp + p[turn][5] - e);
                        }
        for (int s1 = 0; s1 <= c[1]; s1++)
            for (int s2 = 0; s2 <= c[2]; s2++)
                for (int s3 = 0; s3 <= c[3]; s3++)
                    for (int s4 = 0; s4 <= c[4]; s4++)
                        for (int s5 = 0; s5 <= c[5]; s5++) {
                            int tmp = dp[s1][s2][s3][s4][s5];
                            if (tmp < 0) continue;
                            if (s1 < c[1]) cmax(dp[s1 + 1][s2][s3][s4][s5], tmp - p[turn][1] - d);
                            if (s2 < c[2]) cmax(dp[s1][s2 + 1][s3][s4][s5], tmp - p[turn][2] - d);
                            if (s3 < c[3]) cmax(dp[s1][s2][s3 + 1][s4][s5], tmp - p[turn][3] - d);
                            if (s4 < c[4]) cmax(dp[s1][s2][s3][s4 + 1][s5], tmp - p[turn][4] - d);
                            if (s5 < c[5]) cmax(dp[s1][s2][s3][s4][s5 + 1], tmp - p[turn][5] - d);
                        }
    }
    ll res = 0;
    for (int s1 = 0; s1 <= c[1]; s1++)
        for (int s2 = 0; s2 <= c[2]; s2++)
            for (int s3 = 0; s3 <= c[3]; s3++)
                for (int s4 = 0; s4 <= c[4]; s4++)
                    for (int s5 = 0; s5 <= c[5]; s5++)
                        cmax(res, dp[s1][s2][s3][s4][s5]);
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t >> r >> d >> e;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= n; j++)
            cin >> p[i][j];
    if (d || e) solve1();
}