#include <bits/stdc++.h>

using namespace std;

#define popcnt __builtin_popcountll

const int N = 100005;
const int MOD = 1e9 + 7;

int cnt[N], C[100][100];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, sum = 0, res = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        sum ^= cnt[i] = popcnt(x);
    }
    for (int i = 0; i < 100; i++) C[i][0] = 1;
    for (int i = 1; i < 100; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    for (int i = 1; i <= n; i++)
        if ((sum ^ cnt[i]) < cnt[i])
            res = add(res, mul(C[cnt[i]][sum ^ cnt[i]],
            (1ll << (63 - cnt[i])) % MOD));
    cout << res;
}