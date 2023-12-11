#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const int MOD = 1000000007;

int dp[N];

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, h, d;
    cin >> n >> h >> d;
    dp[0] = 1; int s_fact = 0;
    for (int i = 1; i <= n; i++) {
        dp[0] = mul(dp[0], i);
        s_fact = add(s_fact, dp[0]);
    }
    int s_dp = 0;
    cerr << s_fact;
    for (int i = 0; i < h; i++) {
        s_dp = add(s_dp, dp[i]);
        if (i >= d)
            s_dp = sub(s_dp, dp[i - d]);
        dp[i + 1] = mul(s_dp, s_fact);
    }
    cout << s_dp;
}