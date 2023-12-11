#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int cnt[305], cur[3][605], nxt[3][605];

int Add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int Mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    int q[3], r, s, lim = -3;
    for (int i = 0; i < 3; i++) {
        cin >> q[i]; lim += q[i];
    }
    cin >> r >> s;
    lim = min(lim, s);
    for (int i = 0; i < q[0]; i++)
        for (int j = 0; j < q[1]; j++)
            for (int k = 0; k < q[2]; k++)
                cnt[i + j + k]++;
    int res = 0;
    for (int d = 0; d <= lim; d++) {
        memset(cur, 0, sizeof cur); cur[0][0] = 1;
        for (int i = 0; i < 30; i++) {
            memset(nxt, 0, sizeof nxt);
            for (int rem1 = 0; rem1 <= 2; rem1++)
                for (int rem2 = 0; rem2 <= 600; rem2++) {
                    if (!cur[rem1][rem2]) continue;
                    int val = cur[rem1][rem2];
                    for (int mask = 0; mask < 8; mask++) {
                        int sum1 = rem1, sum2 = rem2;
                        for (int pos = 0; pos < 3; pos++)
                            if (mask >> pos & 1) {
                                sum1++; sum2 += q[pos];
                            }
                        if ((sum1 & 1) != (r >> i & 1) ||
                        (sum2 & 1) != ((s - d) >> i & 1))
                            continue;
                        nxt[sum1 >> 1][sum2 >> 1] = Add
                        (nxt[sum1 >> 1][sum2 >> 1], val);
                    }
                }
            swap(cur, nxt);
        }
        res = Add(res, Mul(cur[0][0], cnt[d]));
    }
    cout << res << '\n';
}