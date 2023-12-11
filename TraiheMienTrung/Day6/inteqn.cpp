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

int main() {
    freopen("inteqn.inp", "r", stdin);
    freopen("inteqn.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        ll a, b, c, x, y;
        cin >> a >> b >> c;
        ll g = ext_euclid(a, b, x, y);
        if (c % g != 0) {
            cout << "0\n";
        }
        else {
            x *= c / g; y *= c / g;
            cout << x << ' ' << y << '\n';
        }
    }
}
