
// Problem : F. Kuroni and the Punishment
// Contest : Codeforces - Ozon Tech Challenge 2020 (Div.1 + Div.2, Rated, T-shirts + prizes!)
// URL : https://codeforces.com/contest/1305/problem/F
// Memory Limit : 256 MB
// Time Limit : 2500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

ll calc(ll x, const vector <ll> &a) {
    ll res = 0;
    for (ll y : a)
        res += y < x ? x - y :
        min(y % x, x - y % x);
    return res;
}

ll solve(ll x, const vector <ll> &a) {
    if (x == 0) return LLONG_MAX;
    ll res = LLONG_MAX;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i) continue;
        res = min(res, calc(i, a));
        while (x % i == 0) x /= i;
    }
    if (x > 1)
        res = min(res, calc(x, a));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector <ll> p(n), a(n);
    for (ll &x : a) {
        cin >> x; p.eb(x);
    }
    shuffle(p.begin(), p.end(), rng);
    while (p.size() > 20)
        p.pop_back();
    ll res = n;
    for (ll x : p) {
        res = min(res, solve(x, a));
        res = min(res, solve(x + 1, a));
        res = min(res, solve(x - 1, a));
    }
    cout << res << '\n';
}