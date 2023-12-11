#include <bits/stdc++.h>
using namespace std;

int dp[26][26], tmp[26][26];

int main() {
    freopen("puzzles.inp", "r", stdin);
    freopen("puzzles.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; int res = 0;
    string s; cin >> n;
    memset(dp, 0xc0, sizeof dp);
    for (int i = 0; i < 26; i++) dp[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int fi = s[0] - 'a', se = s.back() - 'a';
        res = max(res, dp[se][fi] + int(s.size()));
        for (int j = 0; j < 26; j++)
            tmp[j][se] = max(dp[j][se],
            dp[j][fi] + int(s.size()));
        for (int j = 0; j < 26; j++)
            dp[j][se] = tmp[j][se];
    }
    cout << res << '\n';
}
