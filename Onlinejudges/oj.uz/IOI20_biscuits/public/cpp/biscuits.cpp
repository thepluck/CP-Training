#include "biscuits.h"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll count_tastiness(ll x, vector <ll> a) {
    a.resize(60);
    vector <ll> b = a, dp(61, 1);
    for (int i = 1; i < 60; i++)
        b[i] += b[i - 1] / 2;
    for (int i = 0; i < 60; i++) {
        dp[i + 1] = dp[i];
        if (b[i] < x) continue;
        ll k = max(0ll, x - a[i]) * 2;
        for (int j = i - 1; j >= 0; j--)
            if (b[j] >= k + x) {
                dp[i + 1] += dp[j];
                k = max(0ll, k + x - a[j]) * 2;
            } else k = max(0ll, k - a[j]) * 2;
        if (k == 0) dp[i + 1]++;
    }
    return dp[60];
}