#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N], n, k, x;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> x; dp[i] = INT_MIN;
        for (int j = 1; j <= min(i, k); j++)
            dp[i] = max(dp[i], dp[i - j] + x);
    }
    cout << *max_element(dp, dp + n + 1) << '\n';
}