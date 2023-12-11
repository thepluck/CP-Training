#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int dp[1 << N], cnt[N][26], n;

int rec(int mask) {
    if (~dp[mask]) return dp[mask];
    dp[mask] = INT_MAX;
    int len = 0;
    for (int c = 0; c < 26; c++) {
        int cur = INT_MAX;
        for (int i = 0; i < n; i++)
            if (mask >> i & 1)
                cur = min(cur, cnt[i][c]);
        len += cur;
    }
    if ((mask & -mask) == mask)
        return dp[mask] = len;
    for (int smask = mask & (mask - 1);
    smask > 0; smask = (smask - 1) & mask)
        dp[mask] = min(dp[mask],
        rec(smask) + rec(mask ^ smask));
    return dp[mask] -= len;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    cin >> n; string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char c : s)
            cnt[i][c - 'a']++;
    }
    cout << rec((1 << n) - 1) + 1 << '\n';
}