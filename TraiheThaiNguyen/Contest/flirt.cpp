#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int N = 2005;
long long dp[N], a[N]; int n, k;

bool check(long long lim){
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0; long long tmp = 0;
    for (int i = 2; i <= n; i++){
        long long lo = a[i] - lim;
        long long hi = a[i] + lim;
        for (int j = i - 1; j; j--){
            if (a[j] >= lo && a[j] <= hi)
                chkmin(dp[i], dp[j] + i - j - 1);
            lo -= lim; hi += lim;
        }
        tmp = min(tmp, dp[i - 1]) + 1;
    }
    debug(lim) << ' ';
    debug(min(tmp, dp[n])) << '\n';
    return min(tmp, dp[n]) <= k;
}

signed main(){
    freopen("flirt.inp", "r", stdin);
    freopen("flirt.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    long long mx = LLONG_MIN;
    long long mn = LLONG_MAX;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    long long lo = 0, hi = mx - mn, mi;
    long long res = 0;
    while (lo <= hi){
        mi = (lo + hi) / 2;
        if (check(mi)){
            res = mi; hi = mi - 1;
        }
        else lo = mi + 1;
    }
    cout << res << '\n';
}