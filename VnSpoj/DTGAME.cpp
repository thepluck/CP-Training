#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int dp[N][N], opt[N][N], s[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> s[i]; s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++) opt[i][i] = i;
    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++)
            for (int k = max(opt[i][j - 1], i); k <= opt[i + 1][j]; k++){
                int cost = min(s[k] - s[i - 1] + dp[i][k], s[j] - s[k] + dp[k + 1][j]);
                if (dp[i][j] < cost) dp[i][j] = cost, opt[i][j] = k;
            }
    cout << dp[1][n] << '\n';
}