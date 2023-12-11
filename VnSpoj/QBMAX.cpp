#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll dp[1500][1500];
int n, m; ll ans = LLONG_MIN;
int a[1500][1500];

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++){
            dp[i][j] = dp[i][j - 1];
            if (i > 1) chkmax(dp[i][j], dp[i - 1][j - 1]);
            if (i + 1 <= n) chkmax(dp[i][j], dp[i + 1][j - 1]);
            dp[i][j] += a[i][j];
        }
    for (int i = 1; i <= n; i++)
        chkmax(ans, dp[i][m]);
    cout << ans << '\n';
}