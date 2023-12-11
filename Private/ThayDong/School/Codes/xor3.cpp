#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    if (b < 0) return 0;
    if (a < 0) return a = b, 1;
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

ll dp[60][1 << 6], a[6];

bool bit(ll msk, int i) {
    return msk >> i & 1;
}

int main() {
    freopen("xor3.inp", "r", stdin);
    freopen("xor3.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 6; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    dp[51][0] = 0; ll mn = -1;
    for (int i = 50; i >= 0; i--)
        for (int msk = 0; msk < (1 << 6); msk++) {
            if (dp[i + 1][msk] < 0) continue;
            for (int p = 0; p < 2; p++) {
                if (!bit(msk, 0) && p < bit(a[0], i))
                    continue;
                if (!bit(msk, 1) && p > bit(a[1], i))
                    continue;
                for (int q = 0; q < 2; q++) {
                    if (!bit(msk, 2) && q < bit(a[2], i))
                        continue;
                    if (!bit(msk, 3) && q > bit(a[3], i))
                        continue;
                    for (int r = 0; r < 2; r++) {
                        if (!bit(msk, 4) && r < bit(a[4], i))
                            continue;
                        if (!bit(msk, 5) && r > bit(a[5], i))
                            continue;
                        int nmsk = 0;
                        if (bit(msk, 0) || p != bit(a[0], i))
                            nmsk += 1 << 0;
                        if (bit(msk, 1) || p != bit(a[1], i))
                            nmsk += 1 << 1;
                        if (bit(msk, 2) || q != bit(a[2], i))
                            nmsk += 1 << 2;
                        if (bit(msk, 3) || q != bit(a[3], i))
                            nmsk += 1 << 3;
                        if (bit(msk, 4) || r != bit(a[4], i))
                            nmsk += 1 << 4;
                        if (bit(msk, 5) || r != bit(a[5], i))
                            nmsk += 1 << 5;
                        cmin(dp[i][nmsk], dp[i + 1][msk]
                        + (ll(p ^ q ^ r) << i));
                    }
                }
            }
        }
    for (int msk = 0; msk < (1 << 6); msk++)
        cmin(mn, dp[0][msk]);
    memset(dp, -1, sizeof dp);
    dp[51][0] = 0; ll mx = 0;
    for (int i = 50; i >= 0; i--)
        for (int msk = 0; msk < (1 << 6); msk++) {
            if (dp[i + 1][msk] < 0) continue;
            for (int p = 0; p < 2; p++) {
                if (!bit(msk, 0) && p < bit(a[0], i))
                    continue;
                if (!bit(msk, 1) && p > bit(a[1], i))
                    continue;
                for (int q = 0; q < 2; q++) {
                    if (!bit(msk, 2) && q < bit(a[2], i))
                        continue;
                    if (!bit(msk, 3) && q > bit(a[3], i))
                        continue;
                    for (int r = 0; r < 2; r++) {
                        if (!bit(msk, 4) && r < bit(a[4], i))
                            continue;
                        if (!bit(msk, 5) && r > bit(a[5], i))
                            continue;
                        int nmsk = 0;
                        if (bit(msk, 0) || p != bit(a[0], i))
                            nmsk += 1 << 0;
                        if (bit(msk, 1) || p != bit(a[1], i))
                            nmsk += 1 << 1;
                        if (bit(msk, 2) || q != bit(a[2], i))
                            nmsk += 1 << 2;
                        if (bit(msk, 3) || q != bit(a[3], i))
                            nmsk += 1 << 3;
                        if (bit(msk, 4) || r != bit(a[4], i))
                            nmsk += 1 << 4;
                        if (bit(msk, 5) || r != bit(a[5], i))
                            nmsk += 1 << 5;
                        cmax(dp[i][nmsk], dp[i + 1][msk]
                        + (ll(p ^ q ^ r) << i));
                    }
                }
            }
        }
    for (int msk = 0; msk < (1 << 6); msk++)
        cmax(mx, dp[0][msk]);
    cout << mn << '\n' << mx << '\n';
}