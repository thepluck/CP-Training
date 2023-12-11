
// Problem : D. Ngày 2 - bài 1: Phần thưởng (70 điểm)
// Contest : Codeforces - VOI 2018 - practice version
// URL : https://codeforces.com/group/FLVn1Sc504/contest/234046/problem/D
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 505;

ll s[N][N]; int x[5], y[5];

ll rec(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return s[x2][y2] + s[x1 - 1][y1 - 1]
        - s[x2][y1 - 1] - s[x1 - 1][y2];
}

int main() {
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, k, r, p;
    cin >> n >> k >> r >> p; r--;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
            s[i][j] += -s[i - 1][j - 1]
            + s[i][j - 1] + s[i - 1][j];
        }
    ll ans = 0;
    while (k--) {
        for (int i = 0; i < p; i++)
            cin >> x[i] >> y[i];
        ll res = 0;
        int b, x1, y1, x2, y2;
        for (int i = 1; i < (1 << p); i++) {
            b = 0; x1 = y1 = 1; x2 = y2 = n;
            for (int j = 0; j < p; j++)
                if (i >> j & 1) {
                    x1 = max(x1, x[j]);
                    x2 = min(x2, x[j] + r);
                    y1 = max(y1, y[j]);
                    y2 = min(y2, y[j] + r);
                    b ^= 1;
                }
            if (b) res += rec(x1, y1, x2, y2);
            else res -= rec(x1, y1, x2, y2);
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';
}