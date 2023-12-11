#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 3005;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}
int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int fac[N * N], ifac[N * N], dp[N][N];

int getC(int n, int k) {
    if (n < k) return 0;
    return mul(fac[n], mul(ifac[n - k], ifac[k]));
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int maxX = 0, maxY = 0;
    int minX = n + 1, minY = m + 1;
    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        minX = min(minX, x);
        minY = min(minY, y);
    }
    fac[0] = ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= n * m; i++)
        ifac[i] = MOD - mul(MOD / i, ifac[MOD % i]);
    for (int i = 1; i <= n * m; i++) {
        fac[i] = mul(fac[i - 1], i);
        ifac[i] = mul(ifac[i - 1], ifac[i]);
    }
    int wid = maxX - minX + 1;
    int hei = maxY - minY + 1;
    dp[wid][hei] = fac[wid * hei - k];
    for (int i = wid; i <= n; i++)
        for (int j = hei; j <= m; j++) {
            dp[i + 1][j] = add(dp[i + 1][j],
            mul(dp[i][j], fac[j]));
            dp[i][j + 1] = add(dp[i][j + 1],
            mul(dp[i][j], fac[i]));
        }
    cout << mul(dp[n][m], mul(getC(n - wid, minX - 1), getC(m - hei, minY - 1)));
}