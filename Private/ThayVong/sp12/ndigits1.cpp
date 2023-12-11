#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[10005][105], n, k;

int main(){
    freopen("ndigits1.inp", "r", stdin);
    freopen("ndigits1.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k; dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < k; j++)
            for (int dgt = (i == 1); dgt <= 9; dgt++){
                int tmp = (j + dgt) % k;
                dp[i][tmp] = (dp[i][tmp] + dp[i - 1][j]) % mod;
            }
    }
    cout << dp[n][0] + (n == 1) << '\n';
}