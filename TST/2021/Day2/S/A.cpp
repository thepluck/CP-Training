#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 305;
const int INV2 = 500000004;

int ifac[N], fac[N], n, m;
int dp[N][N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void doAdd(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void doMul(int &x, int y) {
    x = (long long)x * y % MOD;
}

int getC(int n, int k) {
    return mul(fac[n], mul(ifac[k], ifac[n - k]));
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int calc(int l) {
    memset(dp, 0, sizeof dp); dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            doAdd(dp[i + 1][j], dp[i][j]);
            for (int k = 2; k + i <= n && j + k - 1 <= m && k <= l; k++)
                doAdd(dp[i + k][j + k - 1], mul(dp[i][j], mul
                (getC(n - i - 1, k - 1), mul(fac[k], INV2))));
            if (l >= 2) doAdd(dp[i + 2][j + 2], mul(n - i - 1, dp[i][j]));
            for (int k = 3; k + i <= n && j + k <= m && k <= l; k++)
                doAdd(dp[i + k][j + k], mul(dp[i][j], mul
                (getC(n - i - 1, k - 1), mul(fac[k - 1], INV2))));
        }
    return dp[n][m];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k; cin >> n >> m >> k;
    fac[0] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n; i++)
        ifac[i] = MOD - mul(ifac[MOD % i], MOD / i);
    for (int i = 1; i <= n; i++) {
        fac[i] = mul(fac[i - 1], i);
        ifac[i] = mul(ifac[i], ifac[i - 1]);
    }
    cout << sub(calc(k), calc(k - 1));
}