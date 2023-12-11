#include "trainer.h"
#include <bits/stdc++.h>

namespace {
    using namespace std;

    long long sum[400005], cost[200005];
    int K, N, M;

    void dnc(int l, int r, int optl, int optr,
    vector<int> &L, vector<int> &R,
    vector<vector<int>> &A) {
        int m = (l + r) / 2, optm;
        vector<int> P;
        cost[m] = LLONG_MAX;
        for (int j = 0; j < M; j++) {
            P.push_back(A[j][m * 2]);
            P.push_back(A[j][m * 2 + 1]);
        }
        sort(P.begin(), P.end());
        for (int i = 0; i < 2 * M; i++)
            sum[i + 1] = sum[i] + P[i];
        for (int j = optl; j <= optr; j++) {
            long long cur = 0;
            int p = lower_bound(P.begin(), P.end(), L[j]) - P.begin();
            cur += 1ll * L[j] * p - sum[p];
            p = upper_bound(P.begin(), P.end(), R[j]) - P.begin();
            cur += sum[M * 2] - sum[p] - 1ll * R[j] * (M * 2 - p);
            if (cur < cost[m]) {
                optm = j; cost[m] = cur;
            }
        }
        if (l < m) dnc(l, m - 1, optl, optm, L, R, A);
        if (m < r) dnc(m + 1, r, optm, optr, L, R, A);
    }
}

long long minimize_penalty(vector<int> L,
vector<int> R, vector<vector<int>> A) {
    K = L.size(), M = A.size();
    N = A[0].size() / 2;
    for (int i = 0; i < M; i++)
        sort(A[i].begin(), A[i].end());
    vector<pair<int, int>> T;
    for (int i = 0; i < K; i++)
        T.emplace_back(L[i], R[i]);
    sort(T.begin(), T.end(),
    [&](pair<int, int> x, pair<int, int> y) {
        return x.first > y.first;
    });
    vector<pair<int, int>> good;
    for (auto p : T) {
        while (good.size() && p.second >= good.back().second)
            good.pop_back();
        good.push_back(p);
    }
    reverse(good.begin(), good.end());
    K = good.size();
    for (int i = 0; i < K; i++)
        tie(L[i], R[i]) = good[i];
    dnc(0, N - 1, 0, K - 1, L, R, A);
    return accumulate(cost, cost + N, 0ll);
}
