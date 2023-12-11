#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("output.txt", "w", stdout);
    ll dp[100001]; dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= 100000; i++)
        if (i & 1) dp[i] = dp[i >> 1] + dp[i - (i >> 1)];
        else dp[i] = dp[i >> 1];
    for (int i = 1; i <= 100000; i++)
        dp[i] = max(dp[i - 1], dp[i]);
    int t, n; cin >> t;
    while (t--){
        cin >> n; cout << dp[n] << '\n';
    }
}