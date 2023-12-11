#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

ll expmod(ll a, ll b){
    ll res = 1;
    for (; b > 0; b >>= 1){
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

ll inverse(ll a){
    return expmod(a, mod - 2);
}

ll C(ll k, ll n){
    ll res = 1;
    for (ll i = 1; i <= k; i++)
        res = res * (n - k + i) % mod;
    for (ll i = 1; i <= k; i++)
        res = res * inverse(i) % mod;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; ll k, n;
    while (cin >> s){
        if (s == "[END]") return 0;
        cin >> k >> n;
        cout << C(k + 1, n + k) << '\n';
    }
}   