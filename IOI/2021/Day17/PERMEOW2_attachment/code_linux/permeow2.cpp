#include "permeow2.h"
#include <bits/stdc++.h>

using namespace std;

namespace {
    const int N = 5005;
    const int MOD = 1000000007;

    int ban[N][N]; int dp[N], mn[N][N];

    void add(int &x, int y) {
        if ((x += y) >= MOD) x -= MOD;
    }
}

int count_permutation(vector<int> p) {
    int n = p.size();
    for (int i = 1; i < n; i++) {
        mn[i][i] = p[i];
        for (int j = i + 1; j < n; j++)
            mn[i][j] = min(mn[i][j - 1], p[j]);
        int k = n - 1, mx = 0;
        for (int j = i - 1; j >= 0; j--) {
            mx = max(mx, p[j]);
            while (k >= i && mn[i][k] < mx) k--;
            ban[j + 1][i + 1]++;
            ban[j + 1][k + 2]--;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ban[i][j] += ban[i][j - 1];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (!ban[j][i])
                add(dp[i], dp[j - 1]);
    return dp[n];
}
