#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

int main() {
    freopen("haitumtp.inp", "r", stdin);
    freopen("haitumtp.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int r, c; cin >> r >> c;
    vector <vector <unsigned>> a(r, vector <unsigned> (c));
    vector <vector <unsigned>> dp(r, vector <unsigned> (c, UINT_MAX));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++)
        dp[i][0] = a[i][0];
    for (int j = 0; j < c - 1; j++)
        for (int i = 0; i < r; i++)
            if (dp[i][j] != UINT_MAX) {
                int k = i * i % r;
                cmin(dp[k][j + 1], dp[i][j] + a[k][j + 1]);
                k = k * i % r;
                cmin(dp[k][j + 1], dp[i][j] + a[k][j + 1]);
                k = k * i % r;
                cmin(dp[k][j + 1], dp[i][j] + a[k][j + 1]);
            }
    unsigned res = UINT_MAX;
    for (int i = 0; i < r; i++)
        cmin(res, dp[i][c - 1]);
    cout << res << '\n';
}