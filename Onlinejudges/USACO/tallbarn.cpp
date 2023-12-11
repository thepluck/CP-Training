#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    freopen("tallbarn.in", "r", stdin);
    freopen("tallbarn.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    vector <ll> a(n);
    for (ll &x : a) cin >> x;
    double lo = 0, hi = 1e18;
    for (int i = 0; i < 200; i++) {
        double mi = (lo + hi) / 2;
        ll cnt = 0;
        for (ll x : a)
            cnt += ll((sqrt(1 + x * 4 / mi) - 1) / 2) + 1;
        if (cnt >= k) lo = mi; else hi = mi;
    }
    double res = 0; ll cnt = 0;
    for (ll x : a) {
        ll c = ll((sqrt((lo + x * 4) / lo) - 1) / 2) + 1;
        res += 1.0 * x / c; cnt += c;
    }
    cout << ll(round(res - lo * (k - cnt))) << '\n';
}