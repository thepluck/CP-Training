#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int L = 1005;
const int MOD = 1000000007;

int dp[N][L][N][2][2], a[N], n, lim;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int calc(int i, int cSum, int cMid, int cLef, int cRig) {
    int &res = dp[i][cSum][cMid][cLef][cRig];
    if (res >= 0) return res; res = 0;
    int nSum = cSum + (cMid * 2 + cLef + cRig) * (a[i + 1] - a[i]);
    if (nSum > lim || cMid < 0) return res = 0;
    if (i == n - 1) return res = cMid == 0;
    res = add(res, calc(i + 1, nSum, cMid, 1, cRig));
    res = add(res, calc(i + 1, nSum, cMid, cLef, 1));
    res = add(res, mul(calc(i + 1, nSum, cMid + 1, cLef, cRig), cMid + 1));
    res = add(res, mul(calc(i + 1, nSum, cMid, cLef, cRig), cMid * 2));
    res = add(res, mul(calc(i + 1, nSum, cMid - 1, cLef, cRig), cMid - 1));
    res = add(res, calc(i + 1, nSum, cMid - 1, 1, cRig));
    res = add(res, calc(i + 1, nSum, cMid - 1, cLef, 1));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> lim;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0, 0, 0, 0) << '\n';
}