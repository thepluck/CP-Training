#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int N = 1005;
const int mod = 9901;
ll dp[N][N / 2], s[N][N / 2];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k; dp[1][1] = 1;
    for (int i = 1; i <= k; i++)
        s[1][i] = 1;
    for (int i = 3; i <= n; i += 2)
        for (int j = 2; j <= k; j++){
            for (int x = 1; x < i; x += 2){
                dp[i][j] += s[x][j - 1] * s[i - x - 1][j - 1]
                            - s[x][j - 2] * s[i - x - 1][j - 2];
                dp[i][j] %= mod;
            }
            s[i][j] = (s[i][j - 1] + dp[i][j]) % mod;
        }
    cout << (dp[n][k] + mod) % mod << '\n';
}