#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ext_euclid(ll a, ll b, ll &x, ll &y) {
    ll g = a; x = 1; y = 0;
    if (b != 0){
        g = ext_euclid(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return g;
}

ll solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    ll g = ext_euclid(a, b, x, y);
    if (c % g != 0) {
        return -1;
    }
    ll _a = a / g, _b = b / g;
    x *= c / g; y *= c / g;
    ll res = LLONG_MAX;
    if (x <= 0 || y <= 0 && _a + _b != 0) {
        ll tmp = abs(x - y), del = (_a + _b);
        ll sf = min({tmp / del, abs(x) / _b, abs(y) / _a});
        res = min(res, abs(tmp - del * sf));
        sf = min({tmp / del + 1, abs(x) / _b, abs(y) / _a});
        res = min(res, abs(tmp - del * sf));
    }
    if (x <= 0) {
        ll sf = (y - 1) / _a + 1;
        y -= sf * _a; x += sf * _b;
    }
    else  {
        ll sf = (x - 1) / _b + 1;
        y += sf * _a; x -= sf * _b;
    }
    if (x <= 0 || y <= 0 && _a + _b != 0) {
        ll tmp = abs(x - y), del = (_a + _b);
        ll sf = min({tmp / del, abs(x) / _b, abs(y) / _a});
        res = min(res, abs(tmp - del * sf));
        sf = min({tmp / del + 1, abs(x) / _b, abs(y) / _a});
        res = min(res, abs(tmp - del * sf));
    }
    if (x < 0) {
        ll sf = (-x - 1) / _b + 1;
        x += _b * sf; y -= _a * sf;
    }
    if (y < 0) {
        ll sf = (-y - 1) / _a + 1;
        x -= _b * sf; y += _a * sf;
    }
    if (x >= 0 && y >= 0 && _a - _b != 0) {
        ll tmp = abs(x + y), del = abs(_a - _b);
        ll sf = min({tmp / del, abs(x) / _b, abs(y) / _a});
        res = min(res, abs(tmp - del * sf));
        sf = min({tmp / del + 1, abs(x) / _b, abs(y) / _a});
        res = min(res, abs(tmp - del * sf));
    }
    return res;
}

int main() {
    freopen("cwater.inp", "r", stdin);
    freopen("cwater.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
