#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll M = 1e15;

ll mul(ll x, ll y) {
    return x <= M / y ? x * y : M;
}

ll add(ll x, ll y) {
    return min(x + y, M);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll m; cin >> n >> m;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mi = (lo + hi) / 2, cnt = 0;
        for (int i = 0; i < n; i++) {
            ll t = mi / (b[i] + 1) * b[i];
            t += mi % (b[i] + 1);
            cnt = add(cnt, mul(t, a[i]));
        }
        if (cnt >= m) hi = mi;
        else lo = mi + 1;
    }
    cout << hi;
}