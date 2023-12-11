#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int MOD = 1000000007;

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

int cnt[MAXN], DP[MAXN], inv[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    while (N--) {
        int x; cin >> x; cnt[x]++;
    }
    int res = 0; inv[1] = 1;
    for (int i = 2; i < MAXN; i++)
        inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
    for (int g = MAXN - 1; g > 0; g--) {
        int sum = 0;
        for (int d = g; d < MAXN; d += g) {
            DP[g] = sub(DP[g], mul(DP[d], 2));
            sum = add(sum, mul(cnt[d], d));
            DP[g] = sub(DP[g], mul(cnt[d], mul(d, d)));
        }
        DP[g] = mul(add(DP[g], mul(sum, sum)), inv[2]);
        res = add(res, mul(DP[g], inv[g]));
    }
    cout << res << '\n';
}