#include "strips.h"
#include <bits/stdc++.h>

using namespace std;

int getMaximumLength
(int N, vector <int> C) {
    vector <int> rar, L(N);
    for (int c : C) rar.push_back(c);
    sort(rar.begin(), rar.end());
    rar.erase(unique(rar.begin(),
    rar.end()), rar.end());
    for (int &c : C)
        c = lower_bound(rar.begin(),
        rar.end(), c) - rar.begin();
    vector <vector <int>> P(N), DP(N);
    for (int i = 0; i < N; i++)
        P[C[i]].push_back(i);
    vector <char> V(N);
    for (int i = N - 1; i >= 0; i--) {
        DP[i].resize(N);
        fill(V.begin(), V.end(), 0);
        for (int j = i; j < N; j++)
            if (!V[C[j]]) {
                DP[i][j] = j - i + 1;
                V[C[j]] = true;
            } else break;
        for (int j = i + 1; j < N; j++)
            DP[i][j] = max({DP[i][j],
            DP[i + 1][j], DP[i][j - 1]});
    }
    multiset <int> M, S;
    int res = DP[0][N - 1];
    for (int i = 0; i + 1 < N; i++) {
        fill(V.begin(), V.end(), 0);
        M.clear(); S.clear();
        M.insert(DP[i + 1][N - 1]);
        S.insert(N - 1); L[N - 1] = i + 1;
        for (int j = i; j >= 0; j--)
            if (!V[C[j]]) {
                V[C[j]] = true;
                for (int p : P[C[j]]) {
                    if (p <= i) continue;
                    int r = *S.lower_bound(p);
                    M.erase(M.find(DP[L[r]][r]));
                    S.erase(r);
                    if (p > L[r]) {
                        M.insert(DP[L[r]][p - 1]);
                        S.insert(p - 1); L[p - 1] = L[r];
                    }
                    if (p < r) {
                        M.insert(DP[p + 1][r]);
                        S.insert(r); L[r] = p + 1;
                    }
                }
                if (M.size()) res = max(res,
                i - j + 1 + *M.rbegin());
            } else break;
    }
    return res;
}
