// Problem: E. Vowels
// Contest: Codeforces - Codeforces Round #225 (Div. 1)
// URL: https://codeforces.com/problemset/problem/383/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int AL = 24;

int dp[1 << AL];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        s.erase(unique(s.begin(),
        s.end()), s.end());
        if (s.size() == 1)
            dp[1 << (s[0] - 'a')]++;
        else if (s.size() == 2) {
            dp[1 << (s[0] - 'a')]++;
            dp[1 << (s[1] - 'a')]++;
            dp[(1 << (s[0] - 'a')) +
            (1 << (s[1] - 'a'))]--;
        }
        else {
            dp[1 << (s[0] - 'a')]++;
            dp[1 << (s[1] - 'a')]++;
            dp[1 << (s[2] - 'a')]++;
            dp[(1 << (s[0] - 'a')) +
            (1 << (s[1] - 'a'))]--;
            dp[(1 << (s[1] - 'a')) +
            (1 << (s[2] - 'a'))]--;
            dp[(1 << (s[0] - 'a')) +
            (1 << (s[2] - 'a'))]--;
            dp[(1 << (s[0] - 'a')) +
            (1 << (s[1] - 'a')) +
            (1 << (s[2] - 'a'))]++;
        }
    }
    for (int i = 0; i < 24; i++)
        for (int j = 0; j < (1 << AL); j++)
            if (j >> i & 1)
                dp[j] += dp[j ^ (1 << i)];
    int res = 0;
    for (int j = 0; j < (1 << AL); j++)
        res ^= dp[j] * dp[j];
    cout << res << '\n';
}