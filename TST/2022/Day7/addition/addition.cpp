#include "addition.h"
#include <string>

namespace {
    using namespace std;

    const int MOD = 1e9 + 7;
    const int N = 200005;

    int cnt[2][2], inv[N];

    int mul(int x, int y) {
        return (long long)x * y % MOD;
    }

    int add(int x, int y) {
        return (x += y) >= MOD ? x - MOD : x;
    }

    int P(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++)
            res = mul(res, i);
        return res;
    }

    int A(int n, int k) {
        int res = 1;
        for (int i = 1; i <= k; i++)
            res = mul(res, n - i + 1);
        return res;
    }
}

int count_arrangements(string a, string b, string c) {
    inv[1] = 1;
    for (int i = 2; i < N; i++)
        inv[i] = MOD - mul(inv[MOD % i], MOD / i);
    cnt[0][0] = cnt[0][1] = cnt[1][1] = cnt[1][0] = 0;
    int lead = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] -= '0'; b[i] -= '0'; c[i] -= '0';
        if ((a[i] + b[i]) % 10 == c[i]) {
            cnt[a[i] + b[i] > 9][0]++;
            lead += a[i] + b[i] <= 9 && a[i] && b[i];
        } else if ((a[i] + b[i] + 1) % 10 == c[i]) {
            cnt[a[i] + b[i] > 8][1]++;
            lead += a[i] + b[i] <= 8 && a[i] && b[i];
        } else return 0;
    }
    if (cnt[0][1] != cnt[1][0]) return 0;
    if (cnt[1][1] && !cnt[0][1]) return 0;
    int res = mul(P(cnt[0][1]), lead);
    res = mul(res, P(cnt[0][1] + cnt[0][0] - 1));
    res = mul(res, A(cnt[0][1] + cnt[1][1] - 1, cnt[1][1]));
    return res;
}
