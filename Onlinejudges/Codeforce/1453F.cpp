// Problem: F. Even Harder
// Contest: Codeforces - Codeforces Round #688 (Div. 2)
// URL: https://codeforces.com/contest/1453/problem/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 3005;

int a[N], dp[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 2; i <= n; i++) {
            int cnt = 0;
            for (int j = i; j <= n; j++)
                dp[i][j] = N;
            for (int j = i - 1; j > 0; j--)
                if (j + a[j] >= i)
                    cmin(dp[i][j + a[j]],
                    dp[j][i - 1] + cnt++);
            for (int j = i; j < n; j++)
                cmin(dp[i][j + 1], dp[i][j]);
        }
        cout << dp[n][n] << '\n';
    }
}