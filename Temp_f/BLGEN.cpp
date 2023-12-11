#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_prime(ll x){
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

bool is_special(ll x){
    ll y = round(sqrt(x));
    ll z = round(pow(x, 1.0 / 3.0));
    return y * y == x || (z * z * z == x && is_prime(x));
}

ll a[1005], b[1005];
int dp[1005][1005], n, m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string sa, sb; 
    getline(cin, sa); getline(cin, sb);
    stringstream ssa(sa), ssb(sb);
    while (ssa >> a[++n]) n -= !is_special(a[n]);
    while (ssb >> b[++m]) m -= !is_special(b[m]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    cout << dp[n][m] << '\n';
}