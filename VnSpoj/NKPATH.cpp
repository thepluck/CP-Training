#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9;
const int N = 150; int res;
int dp[N][N], a[N][N], n, m;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < m; j++){
            for (int p = 1; p <= i; p++)
                for (int q = 1; q < j; q++)
                    if (__gcd(a[i][j], a[p][q]) > 1)
                        dp[i][j] = (dp[i][j] + dp[p][q]) % mod;
            for (int p = 1; p < i; p++)
                if (__gcd(a[i][j], a[p][j]) > 1)
                    dp[i][j] = (dp[i][j] + dp[p][j]) % mod;
        }
    for (int i = 1; i <= n; i++)
        for (int p = 1; p <= i; p++)
            for (int q = 1; q < m; q++)
                if (__gcd(a[i][m], a[p][q]) > 1)
                    dp[i][m] = (dp[i][m] + dp[p][q]) % mod;
    for (int i = 1; i <= n; i++)
        res = (res + dp[i][m]) % mod;
    cout << res << '\n';
}