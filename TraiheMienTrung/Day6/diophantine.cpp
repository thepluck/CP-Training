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

void solve() {
    ll a, b, c, x, y;
    cin >> a >> b >> c;
    ll g = ext_euclid(a, b, x, y);
    if (c % g != 0) {
        cout << "0\n"; return;
    }
    ll _a = a / g, _b = b / g;
    x *= c / g; y *= c / g;
    if (x < 0) {
        ll sf = (-x - 1) / _b + 1;
        x += _b * sf; y -= _a * sf;
    }
    if (y < 0) {
        ll sf = (-y - 1) / _a + 1;
        x -= _b * sf; y += _a * sf;
    }
    if (x < 0 || y < 0) {
        cout << "0\n"; return;
    }
    bool add = x > 0 && y > 0;
    int xx = max(x - 1, 0ll) / _b;
    int yy = max(y - 1, 0ll) / _a;
    cout << xx + yy + add << '\n';
}

int main() {
    freopen("diophantine.inp", "r", stdin);
    freopen("diophantine.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t; while (t--) solve();
}

