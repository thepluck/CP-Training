#include <bits/stdc++.h>
using namespace std;

int dp[100005][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int x, y; string s;
        cin >> x >> y >> s;
        int n = s.size();
        for (int i = 0; i <= n; i++)
            dp[i][0] = dp[i][1] = 0x3f3f3f3f;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            if (s[i - 1] == '0') {
                dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]) + y;
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            }
            else dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
}