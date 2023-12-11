
// Problem : D. Rescue Nibel!
// Contest : Codeforces - Codeforces Round #672 (Div. 2)
// URL : https://codeforces.com/contest/1420/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair <int, int>;

const int MOD = 998244353;
const int N = 3e5 + 5;

int fac[N], inv[N]; ii ev[N * 2];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

int C(int k, int n) {
    if (k > n) return 0;
    return mmul(fac[n], mmul(inv[n - k], inv[k]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        ev[i] = {l, 1};
        ev[i + n] = {r + 1, -1};
    }
    sort(ev, ev + 2 * n);
    inv[1] = fac[0] = inv[0] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = MOD - mmul(MOD / i, inv[MOD % i]);
    for (int i = 1; i < N; i++) {
        fac[i] = mmul(fac[i - 1], i);
        inv[i] = mmul(inv[i - 1], inv[i]);
    }
    int cur = 0, res = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (ev[i].second == 1)
            res = madd(res, C(k - 1, cur));
        cur += ev[i].second;
    }
    cout << res << '\n';
}