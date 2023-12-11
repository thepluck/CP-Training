#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int mul(int x, int y) {
    return (long long) x * y % MOD;
}

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    vector <int> h(n), dp(n);
    for (int &x : h) {
        cin >> x; res = add(res, x - 1);
    }
    for (int i = 0; i + 1 < n; i++) {
        if (i > 0) {
            dp[i] = mul(dp[i - 1], min
            ({h[i - 1], h[i], h[i + 1]}) - 1);
            res = add(res, mul(dp[i - 1],
            min(h[i], h[i - 1]) - 1));
        }
        dp[i] = add(dp[i],
        min(h[i], h[i + 1]) - 1);   
    }
    if (n >= 2)
        res = add(res, mul(dp[n - 2],
        min(h[n - 1], h[n - 2]) - 1));
    cout << res << '\n';
}