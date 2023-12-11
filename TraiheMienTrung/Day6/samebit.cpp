#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using mat = vector <vector <ll>>;

const int MOD = 123456789;
const int MOD6 = 740740734;

ll pow_mod(ll x, ll k, int mod){
    ll res = 1; x %= mod;
    for (; k; k >>= 1, x = x * x % mod)
        if (k & 1) res = res * x % mod;
    return res;
}

int main() {
    freopen("samebit.inp", "r", stdin);
    freopen("samebit.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t, n; cin >> t;
    while (t--){
        cin >> n;
        ll res = pow_mod(2, n + 1, MOD6);
        if (n & 1) res -= 4; else res -= 2;
        if (res < 0) res += MOD6;
        cout << res / 6 << '\n';
    }
}
