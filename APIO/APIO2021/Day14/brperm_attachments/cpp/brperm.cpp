#include "brperm.h"
#include <bits/stdc++.h>

using namespace std;

const int BASE = 461;
const int MAXN = 500005;
const int LOG = 18;

using ull = unsigned long long;

ull F[MAXN][LOG + 1]; int N;
ull G[MAXN][LOG + 1], P[MAXN];
char S[MAXN];

void init(int N, const char S[]) {
    P[0] = 1; ::N = N; strcpy(::S, S);
    for (int i = 1; i <= (1 << LOG); i++)
        P[i] = P[i - 1] * BASE;
    for (int i = 0; i < N; i++)
        F[i][0] = G[i][0] = S[i];
    for (int k = 1; k <= LOG && (1 << k) <= N; k++) {
        for (int i = 0; i + (1 << k) <= N; i++)
            F[i][k] = F[i][k - 1] + F[i + (1 << (k - 1))][k - 1] * P[1 << (LOG - k)];
        for (int i = N - 1; i > N - (1 << k); i--)
            G[i][k] = G[i + 1][k] * P[1 << (LOG - k)] + S[i];
        for (int i = N - (1 << k); i >= 0; i--)
            G[i][k] = G[i + 1][k] * P[1 << (LOG - k)] + S[i] - S[i + (1 << k)] * P[1 << LOG];
    }
}

int query(int i, int k) {
    if (i + (1 << k) > N) return 0;
    return F[i][k] == G[i][k];
}
