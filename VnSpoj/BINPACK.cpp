#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
using ii = pair <int, int>;
const int N = 10005;
const int L = 5005;
const int inf = 0x3f3f3f3f;
ii dp[N][L]; int a[N], l, n, cnt[N];
 
template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}
 
template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}
 
void solve(){
    cin >> l >> n; int ans = INT_MAX;
    for (int i = 1; i <= n; cin >> a[i++]);
    if (l == 100){
        cout << (accumulate(a + 1, a + n + 1, 0) + 99) / 100 << '\n';
        return;
    }
    if (n <= 20){
        int ans = INT_MAX;
        for (int mask = 0; mask < (1 << n); mask++){
            int cnt1 = 0, cnt2 = 0;
            for (int i = 1; i <= n; i++)
                if (mask >> (i - 1) & 1) cnt1 += a[i];
                else cnt2 += a[i];
            ans = min(ans, (cnt1 + l - 1) / l + (cnt2 + l - 1) / l);
        }
        cout << ans << '\n'; return;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= l; j++)
            dp[i][j] = {inf, 0};
    dp[0][0] = {0, 0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= l; j++){
            int nj = j, ncnt = dp[i][j].fi;
            if (nj == 0) ncnt++; nj += a[i + 1];
            if (nj > l) nj = a[i + 1], ncnt++;
            chkmin(dp[i + 1][nj], ii(ncnt, dp[i][j].se));
            nj = dp[i][j].se; ncnt = dp[i][j].fi;
            if (nj == 0) ncnt++; nj += a[i + 1];
            if (nj > l) nj = a[i + 1], ncnt++;
            chkmin(dp[i + 1][j], ii(ncnt, nj));
        }
    for (int j = 0; j <= l; j++)
        ans = min(ans, dp[n][j].fi);
    cout << ans << '\n';
}
 
int main(){
    solve();
}