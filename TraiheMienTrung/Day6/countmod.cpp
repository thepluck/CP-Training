#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ext_euclid(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0) {
        g = ext_euclid(b, a % b, y, x);
        y -= (a / b) * x;
        cout << a << ' ' << b << '\n';
    }
    return g;
}

bool linear_congruences(
const vector <ll> &a, const vector <ll> &b,
const vector <ll> &m, ll &x, ll &mod) {
    int n = a.size(); x = 0; mod = 1;
    for (int i = 0; i < n; i++) {
        ll _a = a[i] * mod, _m = m[i];
        ll _b = b[i] - a[i] * x;
        ll y, t, g = ext_euclid(_a, _m, y, t);
        if (_b % g) {
            return false;
        }
        _b /= g; _m /= g;
        x += mod * (y * _b % _m);
        mod *= _m;
    }
    x = (x + mod) % mod; return true;
}

ll solve(){
    vector <ll> a = {1, 1, 1, 1};
    vector <ll> b(4), m(4);
    for (int i = 0; i < 4; i++)
        cin >> m[i] >> b[i];
    ll x, mod;
    if (linear_congruences(a, b, m, x, mod)) {
        return x;
    }
    return -1;
}

int main() {
    freopen("countmod.inp", "r", stdin);
    freopen("countmod.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
