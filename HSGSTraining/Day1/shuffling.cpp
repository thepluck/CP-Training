#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
const int MOD = 1e9 + 7;
int dp[N][N], cnt[2]; char s[N], t[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m >> (s + 1);
    strcpy(t + 1, s + 1); dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        sort(s + l, s + r + 1);
        sort(t + l, t + r + 1, greater <char> ());
    }
    for (int i = 1; i <= n; i++) {
        cnt[0] += s[i] == '0';
        cnt[1] += t[i] == '0';
        for (int j = cnt[1]; j <= cnt[0]; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j) dp[i][j] += dp[i - 1][j - 1];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }
    int res = 0;
    for (int j = cnt[1]; j <= cnt[0]; j++) {
        res += dp[n][j];
        if (res >= MOD) res -= MOD;
    }
    cout << res << '\n';
}