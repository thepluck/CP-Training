
// Problem : C. Sky Full of Stars
// Contest : Codeforces - Codeforces Round #493 (Div. 1)
// URL : https://codeforces.com/problemset/problem/997/C
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

template <class T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T q = m / a;
        m -= q * a; swap(a, m);
        u -= q * v; swap(u, v);
    }
    return u;
}

using ll = long long;

const int MOD = 998244353;
const int N = 1000001;

int fac[N], inv[N];

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int msub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

int mneg(int x) {
    return MOD - x;
}

int mpow(int x, ll k) {
    int res = 1;
    for (; k; k >>= 1, x = mmul(x, x))
        if (k & 1) res = mmul(res, x);
    return res;
}

int C(int k, int n) {
    return mmul(fac[n],
    mmul(inv[k], inv[n - k]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int zero = 0, non = 0;
    int n; cin >> n;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mmul(fac[i - 1], i);
        inv[i] = inverse(fac[i], MOD);
        if (inv[i] < 0) inv[i] += MOD;
    }
    for (int i = 1; i <= n; i++)
        zero = madd(zero, mmul(C(i, n),
        mmul(mpow(MOD - 1, i + 1),
        mpow(3, ll(n) * (n - i) + i))));
    for (int i = 0; i < n; i++)
        non = madd(non, mmul(C(i, n),
        mmul(mpow(MOD - 1, i + 1), msub
        (mpow(madd(1, mneg(mpow(3, i))),
        n), mpow(mneg(mpow(3, i)), n)))));
    zero = mmul(zero, 2);
    non = mmul(non, 3);
    cout << madd(zero, non) << '\n';
}