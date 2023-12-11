//https://hackmd.io/d5_qU4A7Q9OXSd1o3D0gLQ
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int K = 1e6 + 5;
const int MOD = 1e9 + 7;
ll f[K], l[K], r[K], inv[K];
int n, k;

ll mpow(ll x, ll k) {
    ll res = 1;
    for (; k; k >>= 1, x = x * x % MOD)
        if (k & 1) res = res * x % MOD;
    return res;
}

ll inverse(ll x) {
    return mpow(x, MOD - 2);
}

void solve() {
    ll res = 0;
    l[0] = r[k + 3] = inv[0] = 1;
    for (int i = 1; i <= k + 2; i++) {
        f[i] = (f[i - 1] + mpow(i, k)) % MOD;
        l[i] = l[i - 1] * (n - i) % MOD;
        inv[i] = inv[i - 1] * inverse(i) % MOD;
    }
    if (n <= k + 2) {
        cout << f[n] << '\n'; return;
    }
    for (int i = k + 2; i > 0; i--)
        r[i] = r[i + 1] * (n - i) % MOD;
    for (int i = 1; i <= k + 2; i++) {
        ll tmp = l[i - 1] * r[i + 1] % MOD;
        tmp = tmp * inv[i - 1] % MOD;
        tmp = tmp * inv[k + 2 - i] % MOD;
        tmp = tmp * f[i] % MOD;
        if (k + 2 - i & 1)
            res = (res - tmp) % MOD;
        else res = (res + tmp) % MOD;
    }
    if (res < 0) res += MOD;
    cout << res << '\n';   
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    while (cin >> n >> k) solve();
}