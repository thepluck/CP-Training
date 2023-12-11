#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

long long dp1[N][N], dp2[N][N];
int a[N][N], lef[N * 2], rig[N * 2], n, m;

int calc(int d1, int d2) {
    int x1 = min(d1 - 1, n) - rig[d1];
    int y1 = d1 - x1;
    int x2 = max(d2 - m, 1) + lef[d2];
    int y2 = d2 - x2;
    if (y1 > y2 || x1 < x2) return n * m;
    if (x1 == n && x2 == 1) return n * m;
    if (y1 == 1 && y2 == m) return n * m;
    if (x2 == 1 && y1 == 1) return n * m;
    if (x1 == n && y2 == m) return n * m;
    return (x1 - x2 + 1) * (y2 - y1 + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            dp1[i][j] = max(dp1[i - 1][j],
            dp1[i][j - 1]) + a[i][j];
        }
    for (int i = n; i > 0; i--)
        for (int j = m; j > 0; j--)
            dp2[i][j] = max(dp2[i + 1][j],
            dp2[i][j + 1]) + a[i][j];
    int res = n * m;
    for (int d = 2; d <= n + m; d++) {
        int lo = max(d - m, 1);
        int hi = min(d - 1, n);
        for (int i = lo; i <= hi; i++) {
            int j = d - i;
            if (dp1[i][j] + dp2[i][j] -
            a[i][j] != dp1[n][m]) lef[d]++;
            else break;
        }
        for (int i = hi; i >= lo; i--) {
            int j = d - i;
            if (dp1[i][j] + dp2[i][j] -
            a[i][j] != dp1[n][m]) rig[d]++;
            else break;
        }
    }
    for (int d1 = 2; d1 <= n + m; d1++)
        for (int d2 = 1; d2 <= n + m; d2++)
            res = min(res, calc(d1, d2));
    if (res == n * m) cout << "-1";
    else cout << res;
}