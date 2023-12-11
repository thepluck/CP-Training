#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int dp[1 << N][10];
pair <int, int> str[10];

int main() {
    freopen("vts.inp", "r", stdin);
    freopen("vts.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int x = s[0] - '0';
        int y = s.back() - '0';
        dp[1 << i][x] = 1 << y;
        dp[1 << i][y] = 1 << x;
        str[i] = {x, y};
    }
    int res = 0;
    for (int i = 1; i < (1 << n); i++) {
        int cnt = 0, x, y;
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) {
                cnt++; continue;
            }
            tie(x, y) = str[j];
            dp[i + (1 << j)][x] |= dp[i][y];
            dp[i + (1 << j)][y] |= dp[i][x];
        }
        for (int d = 0; d < 10; d++)
            if (dp[i][d] >> d & 1)
                res = max(res, cnt);
    }
    cout << res << '\n';
}