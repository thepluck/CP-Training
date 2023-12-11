#include <bits/stdc++.h>

using namespace std;

#define popcnt __builtin_popcount

const int N = 18;
const int K = 100005;
const int L = 4000000;

int mask[L], n, k, dp[1 << N];

bool check(int d) {
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < d; i++)
        dp[mask[i]]++;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < (1 << n); i++)
            if (i >> j & 1)
                dp[i] += dp[i ^ (1 << j)];
    for (int i = 0; i < (1 << n); i++)
        if ((n - popcnt(i)) * k > d - dp[i])
            return false;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < L; j++)
            if (!((j / x) & 1))
                mask[j] |= 1 << i;
    }
    int lo = 0, hi = L;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (check(mi)) hi = mi;
        else lo = mi + 1;
    }
    cout << hi << '\n';
}