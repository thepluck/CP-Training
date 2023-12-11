#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int dp[N][N], ans = 0;

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, 1 : 0;
}

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> dp[i][j];
            dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
            if (i >= k && j >= k)
                chkmax(ans, dp[i][j] + dp[i - k][j - k] - dp[i][j - k] - dp[i - k][j]);
        }
    cout << ans << '\n';
}