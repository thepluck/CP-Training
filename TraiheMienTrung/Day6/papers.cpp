#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

ll pow_mod(ll x, ll k){
    ll res = 1; x %= MOD;
    for (; k; k >>= 1, x = x * x % MOD)
        if (k & 1) res = res * x % MOD;
    return res;
}

ll inverse(ll x){
    return pow_mod(x, MOD - 2);
}

ll comb(int k, ll n){
    if (k > n) return 0; ll res = 1;
    for (int i = 1; i <= k; i++){
        res = res * (n - k + i) % MOD;
        res = res * inverse(i) % MOD;
    }
    return res;
}

int main(){
    freopen("papers.inp", "r", stdin);
    freopen("papers.out", "w", stdout);
    ll m; int n; cin >> m >> n;
    for (int i = 1, x; i <= n; i++){
        cin >> x; m -= x;
    }
    cout << comb(n - 1, m + n - 1) << '\n';
}
