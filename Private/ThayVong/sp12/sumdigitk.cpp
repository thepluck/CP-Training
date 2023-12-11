#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
const int mod = 1e9 + 7;
int dp[N][105][2], n, k, a[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("sumdigitk.inp", "r", stdin);
    freopen("sumdigitk.out", "w", stdout);
    string s; cin >> s >> k; n = s.size(); dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            for (int l = 0; l <= 1; l++){
                int lim = l ? a[i] : 9;
                for (int dgt = 0; dgt <= lim; dgt++){
                    int _j = (j + dgt) % k;
                    int _l = l && dgt == a[i];
                    dp[i][_j][_l] = (dp[i][_j][_l] + dp[i - 1][j][l]) % mod;
                }
            }
    int res = (dp[n][0][0] + dp[n][0][1] - 1) % mod;
    if (res < 0) res += mod; cout << res << '\n';
}