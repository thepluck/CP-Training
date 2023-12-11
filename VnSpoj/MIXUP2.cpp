#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, k) for (int i = (j); i < (k); ++i)
long long dp[1 << 17][17], a[17];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i]; dp[1 << i][i] = 1;
    }
    FOR(mask, 0, 1 << n) FOR(i, 0, n) if ((mask >> i) & 1) FOR(j, 0, n) 
        if (i != j && ((mask >> j) & 1) && abs(a[j] - a[i]) > k) 
            dp[mask][i] += dp[mask ^ (1 << i)][j];
    cout << accumulate(dp[(1 << n) - 1], dp[(1 << n) - 1] + n, 0ll) << '\n';
}