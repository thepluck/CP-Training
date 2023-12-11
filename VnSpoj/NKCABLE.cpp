#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <int> dp(n), cost(n);
    for (int i = 1; i < n; i++) cin >> cost[i];
    dp[0] = 0; dp[1] = cost[1]; dp[2] = cost[1] + cost[2];
    for (int i = 3; i < n; i++)
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    cout << dp[n - 1] << '\n';
}