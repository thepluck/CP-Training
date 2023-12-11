#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
ll res = 1, fac = 1;

ll pow_mod(ll x, ll k) {
    ll ans = 1;
    for (; k; k >>= 1, x = x * x % MOD)
        if (k & 1) res = res * x % MOD;
    return ans;
}

int main() {
    freopen("matrix.inp", "r", stdin);
    freopen("matrix.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    for (int i = 1; i < n; i++) {
        fac = fac * i % MOD;
        res = res * fac % MOD;
        res = res * fac % MOD;
    }
    fac = fac * n % MOD;
    res = res * pow_mod(fac, m - n + 1);
    cout << res % MOD << '\n';
}