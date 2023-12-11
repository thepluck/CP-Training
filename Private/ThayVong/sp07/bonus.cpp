#include <bits/stdc++.h>
using namespace std;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

using ll = long long;
ll dp[305][305][305 >> 1];
int a[305];
ll inf = -(ll)1e18;

ll calc(int l, int r, int k){
    if (k == 0) return 0;
    if (l > r) return inf;
    ll &res = dp[l][r][k];
    if (dp[l][r][k] != -1) return res;
    res = max(calc(l, r - 1, k), calc(l + 1, r, k));
    if (l < r){
        chkmax(res, abs(a[l] - a[l + 1]) + calc(l + 2, r, k - 1));
        chkmax(res, abs(a[r] - a[r - 1]) + calc(l, r - 2, k - 1));
        chkmax(res, abs(a[l] - a[r]) + calc(l + 1, r - 1, k - 1));
    }
    return res;
}

int main(){
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(ll) * 305 * 305 * (305 >> 1));
    cout << calc(1, n, k) << '\n';
}