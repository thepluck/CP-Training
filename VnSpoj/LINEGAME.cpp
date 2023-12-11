#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
using ll = long long;
ll dp[N][2]; int a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1][0] = a[1]; dp[1][1] = -a[1];
    for (int i = 2; i <= n; i++){
        dp[i][0] = max({dp[i - 1][0], a[i] + dp[i - 1][1],0ll + a[i]});
        dp[i][1] = max({dp[i - 1][1], dp[i - 1][0] - a[i],0ll - a[i]});
    }
    cout << max(dp[n][0], dp[n][0]) << '\n';
}