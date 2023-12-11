#include <bits/stdc++.h>

long long delivery(int N, int K, int L, int P[]) {
    long long pref[N], suff[N];
    for (int i = 0; i < N; i++) {
        pref[i] = min(L, P[i] * 2);
        if (i >= K) pref[i] += pref[i - K];
    }
    for (int i = N - 1; i >= 0; i--) {
        suff[i] = min(L, (L - P[i]) * 2);
        if (i + K < N) suff[i] += suff[i + K];
    }
    long long res = min(pref[N - 1], suff[0]);
    for (int i = 0; i + 1 < N; i++)
        res = min(res, pref[i] + suff[i + 1]);
    return res;
}