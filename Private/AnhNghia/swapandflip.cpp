//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_d
#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int inf = 0x3f3f3f3f;

int dp[55][1 << 18];
int cnt[1 << 18], a[18], b[18];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < (1 << n); i++)
        cnt[i] = __builtin_popcount(i);
    dp[0][0] = 0;
    for (int v = 0; v <= 50; v++)
        for (int i = 0; i < (1 << n); i++) {
            if (dp[v][i] == inf) continue;
            int x = cnt[i], p;
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) continue;
                if (j - x & 1) p = b[j];
                else p = a[j];
                if (p < v) continue;
                cmin(dp[p][i | (1 << j)],
                dp[v][i] + cnt[i >> j]);
            }
        }
    int res = inf;
    for (int v = 0; v <= 50; v++)
        cmin(res, dp[v][(1 << n) - 1]);
    if (res == inf) res = -1;
    cout << res << '\n';
}