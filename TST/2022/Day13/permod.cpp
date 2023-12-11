#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int MOD = 1e9 + 7;

int dp[N];
int f[1 << 18][18];

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int main() {
    int n, k; cin >> n >> k;
    if (n <= 18) {
        f[(1 << (n - 1))][n - 1] = 1;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> on, off;
            for (int i = 0; i < n; i++)
                if (mask >> i & 1) on.push_back(i);
                else off.push_back(i);
            for (int i : on)
                for (int j : off)
                    if ((i + 1) % (j + 1) <= k)
                        f[mask + (1 << j)][j] = add
                        (f[mask + (1 << j)][j], f[mask][i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            if ((i + 1) % n <= k)
                res = add(res, f[(1 << n) - 1][i]);
        cout << 1ll * res * n % MOD; return 0;
    }
    if (k == 0) {
        cout << 0; return 0;
    }
    if (k == 1) {
        cout << n; return 0;
    }
    int res = 0;
    for (int i = n; i > 2; i--) {
        dp[i] = 1;
        for (int j = i * 2; j <= n; j += i) {
            dp[i] = add(dp[i], dp[j - 1]);
            if (j + 1 <= n)
                dp[i] = add(dp[i], dp[j]);
        }
        for (int j = i; j + 2 <= n; j += i)
            dp[i] = add(dp[i], dp[j + 1]);
        res = add(res, add(dp[i], dp[i]));
    }
    cout << 1ll * res * n % MOD; return 0;
}