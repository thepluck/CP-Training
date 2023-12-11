#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}
const int N = 2005;

int dp[N][N * 2], dir[N][N * 2], m, n;
/// 0: up, 1: up-left, 2:left

void init_lcs(string s, string t) {
    memset(dp, 0, sizeof dp);
    memset(dir, 0, sizeof dp);
    m = s.size(), n = t.size(); t += t;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= 2 * n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1] && cmax
            (dp[i][j], dp[i - 1][j - 1] + 1))
                dir[i][j] = 1;
            if (cmax(dp[i][j], dp[i][j - 1]))
                dir[i][j] = 2;
        }
}

int get_lcs(int i, int j) {
    int lcs = 0;
    while (i) {
        if (dir[i][j] == 2) j--;
        else if (dir[i][j] == 1) {
            i--; j--; lcs++;
        }
        else i--;
    }
    return lcs;
}

void remove_col(int j) {
    int i = 0;
    while (j < 2 * n) {
        if (dir[i][j + 1] == 2)
            dir[i][++j] = 0;
        else {
            if (i == m) break;
            if (dir[++i][j + 1] == 1)
                dir[i][++j] = 0;
        }
    }
}

int circular_lcs(string s, string t) {
    init_lcs(s, t); int lcs = 0;
    for (int j = 0; j < n; j++) {
        cmax(lcs, get_lcs(m, j + n));
        remove_col(j);
    }
    return lcs;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    int lcs = circular_lcs(s, t);
    reverse(t.begin(), t.end());
    cout << max(lcs, circular_lcs(s, t));
}
