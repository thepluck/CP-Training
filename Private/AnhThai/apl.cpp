#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int fac[N], inv[N];

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int sub(int x, int y) {
    return (x -= y) < 0 ? x + MOD : x;
}

int bin(int n, int k) {
    if (n < 0 || n < k || k < 0) return 0;
    return mul(fac[n], mul(inv[k], inv[n - k]));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, y, n;
    cin >> x >> y >> n;
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = MOD - mul(inv[MOD % i], MOD / i);
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
        inv[i] = mul(inv[i], inv[i - 1]);
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        int j = i + x - y;
        if (j >= 0 && i + j <= n)
            res = add(res, mul(bin(n, n - i - j), bin(i + j, i)));
        j = i + x + y + 2;
        if (j >= 0 && i + j <= n)
            res = sub(res, mul(bin(n, n - i - j), bin(i + j, i)));
    }
    cout << res;
}