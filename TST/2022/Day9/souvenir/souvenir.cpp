#include "souvenir.h"
#include <vector>

namespace {
    using namespace std;
}

long long buy_souvenir(vector<int> A,
vector<int> X, vector<int> B, vector<int> Y) {
    int N = A.size();
    int M = B.size();
    long long res = 0;
    vector<int> P(N + M, -1);
    for (int i = 0; i < M; i++)
        P[B[i]] = i;
    vector<long long> SX(1), SY(1);
    for (int i = 0; i < N; i++)
        SX.push_back(SX.back() + X[i]);
    for (int i = 0; i < M; i++)
        SY.push_back(SY.back() + Y[i]);
    vector<int> L(M), R(M);
    for (int i = 0; i < N; i++) {
        long long cur = 0;
        for (int j = i; j < N; j++)
            if (P[A[j]] >= 0)
                L[P[A[j]]] = R[P[A[j]]] = -1;
        for (int j = 0; j < M; j++)
            if (L[j] >= 0) {
                int k = j;
                while (k < M && L[k] >= 0) k++;
                cur = max(cur, SY[k] - SY[j]);
                R[j] = k - 1; R[k - 1] = j; j = k;
            }
        res = max(res, cur + SX[N] - SX[i]);
        for (int j = N - 1; j >= i; j--) {
            int k = P[A[j]];
            if (k >= 0) {
                L[k] = R[k] = k;
                if (k > 0 && L[k - 1] >= 0)
                    L[k] = L[k - 1];
                if (k + 1 < M && R[k + 1] >= 0)
                    R[k] = R[k + 1];
                cur = max(cur, SY[R[k] + 1] - SY[L[k]]);
                L[R[k]] = L[k]; R[L[k]] = R[k];
                res = max(res, cur + SX[j] - SX[i]);
            }
        }
    }
    return res;
}
