#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int L = 1005;
const int N = 105;
const int MOD = 1e9 + 7;

int madd(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % MOD;
}

int n, l, dp[N][L][N][2][2], a[N];

int rec(int i, int tot,
int seg, int kl, int kr) {
    int nxt = tot + (seg * 2 + kl
    + kr) * abs(a[i + 1] - a[i]);
    if (nxt > l || seg < 0) return 0;
    if (i == n - 1) return seg == 0;
    int &res = dp[i][tot][seg][kl][kr];
    if (~res) return res;
    res = madd(rec(i + 1, nxt, seg, 1,
    kr), rec(i + 1, nxt, seg, kl, 1));
    res = madd(res, mmul(rec(i + 1,
    nxt, seg - 1, 1, kr), seg));
    res = madd(res, mmul(rec(i + 1,
    nxt, seg - 1, kl, 1), seg));
    res = madd(res, rec(i + 1,
    nxt, seg + 1, kl, kr));
    res = madd(res, mmul(rec(i + 1,
    nxt, seg, kl, kr), seg * 2));
    res = madd(res, mmul(rec(i + 1, nxt,
    seg - 1, kl, kr), seg * (seg - 1)));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(dp, -1, sizeof dp);
    a[0] = a[1];
    cout << rec(0, 0, 0, 0, 0) << '\n';
}