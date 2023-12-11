#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
const int MOD = 1e9 + 7;

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int a[N], b[N], f[N][N], g[N][N], fac[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        fac[i] = mul(fac[i - 1], i);
    }
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    f[0][0] = 1;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j < n && a[j + 1] <= b[i]) j++;
        f[i][0] = 1;
        for (int k = 1; k <= j; k++)
            f[i][k] = add(f[i - 1][k], mul
            (f[i - 1][k - 1], j - k + 1));
    }
    g[n][0] = 1;
    for (int i = n, j = n; i > 0; i--) {
        while (j > 0 && a[i] <= b[j]) j--;
        g[i - 1][0] = 1;
        for (int k = 1; k <= n - j; k++)
            g[i - 1][k] = add(g[i][k], mul
            (g[i][k - 1], n - j - k + 1));
    }
    int res = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (j < n && a[j + 1] <= b[i]) j++;
        for (int k = 0; k <= min(n - i, j); k++) {
            res = add(res, mul(f[i - 1][j - k],
            mul(g[j][n - i - k], fac[k])));
            
        }
    }
    res = add(res, f[n][n]);
    cout << res;
}