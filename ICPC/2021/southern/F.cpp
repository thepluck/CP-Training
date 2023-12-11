#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int LOG = 18;
const int MOD = 1e9 + 7;

int dp[LOG][N], mu[N], cnt[N];
vector<int> pr[N];
int fac[N], inv[N];

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
    mu[1] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
        inv[i] = mul(inv[i], inv[i - 1]);
        cnt[i] = 1;
        for (int j = 2 * i; j <= n; j += i) {
            cnt[i]++; mu[j] -= mu[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        pr[i].resize(n / i + 1);
        for (int j = 1; j <= n / i; j++)
            for (int k = j; k <= n / i; k += j)
                pr[i][k] += mu[j] * (n / i / j);
    }
    for (int i = 1; i <= n; i++)
        dp[0][i] = mul(fac[n - 1], inv[n - cnt[i]]);
    for (int k = 0; k + 1 < LOG; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 2 * i; j <= n; j += i)
                dp[k + 1][i] = add(dp[k + 1][i],
                mul(dp[k][j], mul(pr[i][j / i],
                mul(fac[n - cnt[j] - 1],
                inv[n - cnt[i]]))));
    int res = 0;
    for (int k = 0; k < LOG; k++)
        res = add(res, mul(k + 1, dp[k][1]));
    cout << mul(res, inv[n]);
}