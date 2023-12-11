#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

string s, t;
vector <int> optl, optr;
int n, res = 0;
vector <vector <int>> dp, tr;

void solve(int l, int r) {
    vector <int> lef(n + 1), rig(n + 1);
    int m = (l + r) / 2;
    for (int i = 0; i <= n; i++) {
        for (int j = max(optl[i], m - 1);
        j <= min(optr[i], m + n - 1); j++) {
            if (i == 0 && j == m - 1) {
                dp[i][j] = 0; continue;
            }
            if (i > 0 && j >= m && s[i] == t[j]
            && dp[i - 1][j - 1] >= 0) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                tr[i][j] = 3;
            }
            if (i > 0 && dp[i][j] < dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                tr[i][j] = 1;
            }
            if (j >= m && dp[i][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                tr[i][j] = 2;
            }
        }
    }
    res = max(res, dp[n][m + n - 1]);
    int x = n, y = m + n - 1;
    vector <int> tmp = optr;
    while (true) {
        lef[x] = max(lef[x], y); rig[x] = y;
        if (x == 0 && y == m - 1) break;
        int cc = tr[x][y];
        x -= cc >> 0 & 1; y -= cc >> 1 & 1;
    }
    for (int i = 0; i <= n; i++)
        for (int j = max(optl[i], m - 1);
        j <= min(optr[i], m + n - 1); j++)
            dp[i][j] = -1;
    optr = lef;
    if (l < m) solve(l, m - 1);
    optr = tmp; tmp = optl; optl = rig;
    if (m < r) solve(m + 1, r);
    optl = tmp;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t; n = s.size();
    s = " " + s; t = " " + t + t;
    optl.assign(n + 1, 0);
    optr.assign(n + 1, 2 * n);
    dp.resize(n + 5, vector <int> (2 * n + 5, -1));
    tr.resize(n + 5, vector <int> (2 * n + 5));
    solve(1, n + 1); cout << res;
}
/*
asfsas
asdsds
*/