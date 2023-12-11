#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int MOD, ans[N], fac[N], inv[N], n;

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

void rec(long long sum, long long prod,
int len, int pre, int cnt, int bad) {
    // if (len + prod - sum > 1) {      
    //     ans[len + prod - sum] = add
    //     (ans[len + prod - sum], mul(bad,
    //     mul(inv[cnt], inv[prod - sum])));
    // }
    for (int cur = pre + 1; prod * cur
    - sum - cur + len < n; cur++)
        rec(sum + cur, prod * cur, len + 1,
        cur, 1, mul(bad, inv[cnt]));
    if (prod * pre - sum - pre + len < n)
        rec(sum + pre, prod * pre, len + 1,
        pre, cnt + 1, bad); 
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> MOD;
    inv[0] = inv[1] = fac[0] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = MOD - mul(inv[MOD % i], MOD / i);
    for (int i = 1; i < N; i++) {
        inv[i] = mul(inv[i - 1], inv[i]);
        fac[i] = mul(fac[i - 1], i);
    }
    for (int i = 2; i <= n + 1; i++)
        rec(i, i, 1, i, 1, 1);
    // for (int i = 2; i <= n; i++)
    //     cout << mul(ans[i], fac[i]) << '\n';
    bitset<100> bs;
    bs._Find
}