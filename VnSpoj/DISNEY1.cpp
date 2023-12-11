#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int dp[N][N], a[N][N], n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        a[n + 1][i] = a[i][n + 1] = a[1][i];
    memset(dp, 0x3f, sizeof dp);
    dp[1][1] = 0; n++;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            int k = max(i, j) + 1;
            dp[i][k] = min(dp[i][k], dp[i][j] + a[j][k]);
            dp[k][j] = min(dp[k][j], dp[i][j] + a[i][k]);
            dp[k][k] = min(dp[k][k], dp[i][j] + a[i][k] + a[j][k]);
        }
    cout << dp[n][n] << '\n';
}