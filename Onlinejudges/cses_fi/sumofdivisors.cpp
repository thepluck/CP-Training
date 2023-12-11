/// calculate sum of i * [n / i]
/// because n have O(sqrt(n)) divisors
/// => [n / i] have O(sqrt(n)) values
#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9 + 7;
const int divi = 5e8 + 4;
 
int main(){
    using ll = long long;
    ll n, res = 0; cin >> n;
    for (ll i = 1; i <= n; i++){
        ll j = n / (n / i) % mod, k = i % mod;
        ll tmp = (j + k) * (j - k + 1 + mod) % mod * divi % mod;
        res = (res + n / i % mod * tmp % mod) % mod;
        i = n / (n / i);
    }
    cout << res << '\n';
}