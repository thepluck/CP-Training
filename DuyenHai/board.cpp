#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ll n, m, a = 2; cin >> n >> m;
    ll t = (m - 1) * (n - 1);
    ll res = 1; int mod = 1e9 + 7;
    for (; t > 0; t >>= 1){
        if (t & 1) res = res * a % mod;
        a = a * a % mod;
    }
    cout << res << '\n';
}