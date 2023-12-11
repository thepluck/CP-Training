#include <bits/stdc++.h>
using namespace std;

int dp[20005];

int main(){
    int s, n; cin >> s >> n;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0; int x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        for (int j = x; j < 2 * s; j++)
            dp[j] = min(dp[j], dp[j - x] + 1);
    }
    int res = INT_MAX;
    for (int i = s; i < 2 * s; i++)
        res = min(res, dp[i] + dp[i - s]);
    cout << res << '\n';
}