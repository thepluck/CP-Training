#include "matching.h"
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void mul(int &x, int y) {
    x = (long long)x * y % MOD;
}

vector <char> canA, canB;
vector <int> minB, maxB, len;
int N, A, B;

void compute_row(int a, int dp[]) {
    for (int b = minB[a]; b <= maxB[a]; b++)
        for (int mask = 0; mask < (1 << len[a]); mask++)
            if (canB[a * A + b * B] && !(mask >> (b - minB[a] - 1) & 3))
                add(dp[mask ^ (3 << (b - minB[a] - 1))], dp[mask]);
}

void zeta_transform(int a, int dp[]) {
    for (int i = 0; i < len[a]; i++)
        for (int mask = 0; mask < (1 << len[a]); mask++)
            if (mask >> i & 1)
                add(dp[mask], dp[mask ^ (1 << i)]);
}

int compute_table() {
    static int f[1 << 10], g[1 << 10], h[1 << 10];

    int D = B / __gcd(A, B), res = 0;
    minB.assign(D + 1, N);
    maxB.assign(D + 1, -N);
    len.assign(D + 1, 0);
    for (int a = 0; a <= D; a++) {
        for (int b = -N; b <= N; b++)
            if (0 <= a * A + b * B && a * A + b * B < N) {
                minB[a] = min(minB[a], b);
                maxB[a] = max(maxB[a], b);
            }
        len[a] = maxB[a] - minB[a] + 1;
    }
    memset(f, 0, sizeof f);
    f[0] = 1; compute_row(0, f);
    for (int mask1 = 0; mask1 < (1 << len[0]); mask1++) {
        for (int a = 1; a < D; a++) {
            for (int mask2 = 0; mask2 < (1 << len[a]); mask2++)
                h[mask2] = 0;
            if (a == 1) {
                for (int mask2 = 0; mask2 < (1 << len[a]); mask2++)
                    if ((mask2 & (mask1 << (minB[0] - minB[1]))) == mask2)
                        h[mask2] = f[mask1 ^ (mask2 >> (minB[0] - minB[1]))];
            } else {
                for (int mask2 = 0; mask2 < (1 << len[a - 1]); mask2++)
                    add(h[mask2 << (minB[a - 1] - minB[a]) & ((1 << len[a]) - 1)], g[mask2]);
                zeta_transform(a, h);
                for (int mask2 = 0; mask2 < (1 << len[a]); mask2++)
                    if (mask2 < (mask2 ^ ((1 << len[a]) - 1)))
                        swap(h[mask2], h[mask2 ^ ((1 << len[a]) - 1)]);
            }
            for (int mask2 = 0; mask2 < (1 << len[a]); mask2++)
                for (int b = minB[a]; b <= maxB[a]; b++)
                    if ((mask2 >> (b - minB[a]) & 1) && !canA[a * A + b * B])
                        h[mask2] = 0;
            compute_row(a, h); swap(g, h);
        }
        for (int mask2 = 0; mask2 < (1 << len[D - 1]); mask2++) {
            int cur = g[mask2], mask = mask1;
            mask |= mask2 << (minB[D - 1] - minB[D]) & ((1 << len[D]) - 1);
            for (int b = minB[D]; b <= maxB[D]; b++)
                if (!(mask >> (b - minB[D]) & 1) && canA[D * A + b * B])
                    add(cur, cur);
            add(res, cur);
        }
    }
    return res;
}

int dp[2][1 << 20], dif[205][2];

int count_matching(int N, int M, int A, int B, vector <int> U, vector <int> V) {
    int res = 0; ::N = N; ::A = A; ::B = B;
    if (B <= 20) {
        dp[0][0] = 1;
        for (int mask = 1; mask < (1 << B); mask++)
            dp[0][mask] = 0;
        memset(dif, -1, sizeof dif);
        for (int i = 0; i < M; i++)
            dif[V[i]][dif[V[i]][0] >= 0] = V[i] - U[i] - 1;
        for (int i = 1; i <= N; i++) {
            memset(dp[i & 1], 0, sizeof dp[i & 1]);
            for (int mask = 0; mask < (1 << B); mask++) {
                add(dp[i & 1][mask << 1 & ((1 << B) - 1)], dp[~i & 1][mask]);
                if (dif[i][0] >= 0) {
                    if (!(mask >> dif[i][0] & 1)) {
                        add(dp[i & 1][((mask ^ (1 << dif[i][0])) << 1 ^ 1) & ((1 << B) - 1)], dp[~i & 1][mask]);
                    }
                    if (dif[i][1] >= 0 && !(mask >> dif[i][1] & 1))
                        add(dp[i & 1][((mask ^ (1 << dif[i][1])) << 1 ^ 1) & ((1 << B) - 1)], dp[~i & 1][mask]);
                }
            }
        }
        for (int mask = 0; mask < (1 << B); mask++)
            add(res, dp[N & 1][mask]);
    } else {
        canA.assign(N, 0); canB.assign(N, 0);
        for (int i = 0; i < M; i++)
            if (V[i] - U[i] == A)
                canA[V[i] - 1] = true;
            else canB[V[i] - 1] = true;
        res = 1;
        int G = __gcd(A, B);
        for (int R = 0; R < G; R++, ::N--) {
            mul(res, compute_table());
            canA.erase(canA.begin());
            canB.erase(canB.begin());
        }
    }
    return res;
}
