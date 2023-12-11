#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 998244353;

ll pow_mod(ll x, ll k) {
    ll res = 1;
    for (; k; k >>= 1, x = x * x % MOD)
        if (k & 1) res = res * x % MOD;
    return res;
}

int main() {
    freopen("camax.inp", "r", stdin);
    freopen("camax.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k, cn = 0;
    cin >> n >> n >> k;
    vector <int> a(n); ll res = 0;
    for (int &x : a) cin >> x;
    for (int i = 0, j = 0; i < n; i++) {
        j = max(j, i);
        while (j < n && a[j] <= k) j++;
        res += j - i; cn += a[i] <= k;
    }
    cout << (res % MOD) << ' ';
    res = pow_mod(2, cn) - 1;
    if (res < 0) res += MOD;
    cout << res << '\n';
}
