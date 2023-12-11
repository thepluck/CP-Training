#include <bits/stdc++.h>

using namespace std;

const int D = 100000 + 45;
const int N = 45;
const int MOD = 1e9 + 7;

int dp1[N][N * N][N][2][2], dp2[N][D], dis[N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

void doAdd(int &x, int y) {
    x = add(x, y);
}

void doMul(int &x, int y) {
    x = mul(x, y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int d, n; cin >> d >> n;
    for (int i = 1; i <= n; i++) cin >> dis[i];
    sort(dis + 1, dis + n + 1);
    int lim = min(dis[n] * (n - 1), d - 1);
    dp1[0][0][0][0][0] = 1;
    for (int i = 0; i < n - 1; i++)
        for (int sum = 0; sum <= lim; sum++)
            for (int mid = 0; mid <= i; mid++)
                for (int lef = 0; lef < 2; lef++)
                    for (int rig = 0; rig < 2; rig++) {
                        int nsum = (n - i + lef + mid + rig - 1)
                        * (dis[i + 1] - dis[i]) + sum;
                        int cur = dp1[i][sum][mid][lef][rig];
                        if (nsum > lim || cur == 0) continue;
                        doAdd(dp1[i + 1][nsum][mid][1][rig], cur);
                        doAdd(dp1[i + 1][nsum][mid][lef][1], cur);
                        doAdd(dp1[i + 1][nsum][mid + 1][lef][rig], mul(cur, mid + 1));
                        doAdd(dp1[i + 1][nsum][mid][lef][rig], mul(cur, mid * 2));
                        if (mid > 0) {
                            doAdd(dp1[i + 1][nsum][mid - 1][lef][rig], mul(cur, mid - 1));
                            doAdd(dp1[i + 1][nsum][mid - 1][1][rig], cur);
                            doAdd(dp1[i + 1][nsum][mid - 1][lef][1], cur);
                        }
                    }
    for (int sum = 0; sum <= lim; sum++)
        for (int lef = 0; lef < 2; lef++)
            for (int rig = 0; rig < 2; rig++) {
                int nsum = (lef + rig) * (dis[n] - dis[n - 1]) + sum;
                if (nsum <= lim)
                    doAdd(dp2[0][nsum], dp1[n - 1][sum][0][lef][rig]);
            }
    for (int sum = 1; sum <= d; sum++)
        doAdd(dp2[0][sum], dp2[0][sum - 1]);
    for (int i = 1; i < n; i++)
        for (int sum = 0; sum <= d; sum++) {
            doAdd(dp2[i][sum], dp2[i - 1][sum]);
            doAdd(dp2[i][sum + 1], dp2[i][sum]);
        }
    int res = mul(dp2[n - 1][0], d);
    for (int sum = 1; sum <= d; sum++)
        doAdd(res, mul(sub(dp2[n - 1][sum], dp2[n - 1][sum - 1]), d - sum));
    cout << res << '\n';
}