#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int mod = 1e9 + 7;
int dp[N][105][2], n, k, a[N];

int main(){
    freopen("ndigits2.inp", "r", stdin);
    freopen("ndigits2.out", "w", stdout);
    cin >> n >> k; dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++){
        char x; cin >> x; a[i] = x - '0';
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            for (int l = 0; l <= 1; l++){
                int lim = l ? a[i] : 9;
                for (int dgt = (i == 1); dgt <= lim; dgt++){
                    int _j = (j + dgt) % k;
                    int _l = l && dgt == a[i];
                    dp[i][_j][_l] = (dp[i][_j][_l] + dp[i - 1][j][l]) % mod;
                }
            }
    cout << (dp[n][0][0] + dp[n][0][1]) % mod << '\n';
}