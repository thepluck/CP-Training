#include <bits/stdc++.h>
using namespace std;


const int inf = 2e9;

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

int dp[1005][205][205];
int a[1005], cost[205][205];

int main(){
    freopen("SERV.inp", "r", stdin);
    freopen("SERV.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> cost[i][j];
    for (int i = 1; i <= m; i++) cin >> a[i];
    dp[1][1][2] = dp[1][2][1] = cost[3][a[1]];
    dp[1][1][3] = dp[1][3][1] = cost[2][a[1]];
    dp[1][2][3] = dp[1][3][2] =  cost[1][a[1]];
    for (int i = 1; i < m; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++){
                if (a[i] == j || a[i] == k || j == k) continue;
                if (a[i + 1] != j && a[i + 1] != k){
                    chkmin(dp[i + 1][j][k], dp[i][j][k] + cost[a[i]][a[i + 1]]);
                    chkmin(dp[i + 1][j][k], dp[i][k][j] + cost[a[i]][a[i + 1]]);
                }
                if (a[i + 1] != a[i] && a[i + 1] != k){
                    chkmin(dp[i + 1][a[i]][k], dp[i][j][k] + cost[j][a[i + 1]]);
                    chkmin(dp[i + 1][k][a[i]], dp[i][j][k] + cost[j][a[i + 1]]);
                }
                if (a[i + 1] != a[i] && a[i + 1] != j){
                    chkmin(dp[i + 1][a[i]][j], dp[i][j][k] + cost[k][a[i + 1]]);
                    chkmin(dp[i + 1][j][a[i]], dp[i][j][k] + cost[k][a[i + 1]]);
                }
            }
    int res = inf;
    for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++){
                if (a[m] == j || a[m] == k || j == k) continue;
                chkmin(res, dp[m][j][k]);
            }
    cout << res << '\n';
}