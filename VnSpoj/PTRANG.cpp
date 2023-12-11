#include <bits/stdc++.h>
using namespace std;

int dp[6005], a[6005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i]; int s = a[i]; dp[i] = INT_MAX;
        for (int j = i - 1; j >= 0 && s <= k; s += a[j--])
            dp[i] = min(dp[i], max(dp[j], k - s));
    }
    cout << dp[n] << '\n';
}