/// Calculate [n / 1] + [n / 2] + ... + [n / n] where n is up to 1e9
/// Lemma: Consider k = [sqrt(n)]
/// S(i) = [n / 1] + [n / 2] + ... + [n / i]
/// We have S(n) = 2 * S(k) - k ^ 2
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

ll pow_mod(ll a, ll k){
    ll res = 1;
    for (; k; k >>= 1, a = a * a % mod)
        if (k & 1) res = res * a % mod;
    return res;
}

ll H(int n){
    int t = floor(sqrt(n));
    ll res = 0;
    for (int i = 1; i <= t; i++)
        res += n / i;
    return 2 * res - t * t;
}

int main(){
    int t, n; cin >> t;
    while (t--){
        cin >> n; cout << H(n) << '\n';
    }
}