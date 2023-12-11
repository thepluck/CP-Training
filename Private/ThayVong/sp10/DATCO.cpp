#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5e5 + 5;
int a[N], dp[N][2]; ll s[N];

int main(){
    freopen("DATCO.inp", "r", stdin);
    freopen("DATCO.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; cin >> a[i++]);
    dp[1][0] = 0; dp[1][1] = a[1] + a[2];
    dp[2][0] = max(0, dp[1][1]);
    dp[2][1] = a[1] + a[2] + a[3];
    for (int i = 3; i <= n; i++){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 2][0] + a[i - 1] + a[i] + a[i + 1];
        dp[i][1] = max(dp[i][1], dp[i - 2][1] + a[i] + a[i + 1]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i + 1]);
    }
    cout << max(dp[n][0], dp[n][1]) << '\n';
}