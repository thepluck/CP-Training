//https://codeforces.com/problemset/problem/919/E
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ext_euclid(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) {
        g = ext_euclid(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return g;
}

bool linear_congruences(
const vector <ll> &a, const vector <ll> &b,
const vector <ll> &m, ll &x, ll &mod) {
    int n = a.size(); x = 0; mod = 1;
    for (int i = 0; i < n; i++) {
        ll _a = a[i] * mod, _m = m[i];
        ll _b = b[i] - a[i] * x, y, t;
        ll g = ext_euclid(_a, _m, y, t);
        if (_b % g) return false;
        _b /= g; _m /= g;
        x += mod * (y * _b % _m);
        mod *= _m;
    }
    if (x < 0) x += mod;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    ll a, b, p, x;
    cin >> a >> b >> p >> x;
    ll y, z, pw = 1, res = 0;
    for (int d = 0; d < p - 1; d++) {
        ll g = ext_euclid(pw, p, y, z);
        if (b % g == 0) {
            ll u, v; y *= b / g;
            if (linear_congruences({1, 1},
            {d, y}, {p - 1, p}, u, v)) {
                if (x >= u)
                    res += (x - u) / v + 1;
            }
        }
        pw = pw * a % p;
    }
    cout << res << '\n';
}