#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using ci = pair <char, ll>;

const int N = 100010;
const int M = 55;
const ll mod = 1e9 + 7;
ll dp[N][M], inv[M]; ci s[N]; string t;

ll mexp(ll a, ll k){
    ll res = 1;
    for (; k > 0; k >>= 1, a = a * a % mod)
        if (k & 1) res = res * a % mod;
    return res;
}


signed main(){
    freopen("password.inp", "r", stdin);
    freopen("password.out", "w", stdout);
    int n, m; cin >> n >> m >> t; n = 0;
    for (int i = 0; t[i];){
        s[++n].fi = t[i++]; s[n].se = 0;
        while (t[i] >= '0' && t[i] <= '9') s[n].se = s[n].se * 10 + t[i++] - '0';
    }
    cin >> t; dp[0][0] = 1; t = ' ' + t;
    for (int i = 1; i <= m; i++) inv[i] = mexp(i, mod - 2);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++) if (dp[i][j]){
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod; ll c = 1;
            for (int k = 1; k <= m - j; k++){
                if (s[i + 1].fi != t[j + k] || s[i + 1].se < k) break;
                c = c * (s[i + 1].se - k + 1) % mod * inv[k] % mod;
                dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j] * c % mod) % mod;
            }
        }
    cout << dp[n][m] << '\n';
}