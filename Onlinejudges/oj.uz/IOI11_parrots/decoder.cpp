#include "decoder.h"
#include "decoderlib.h"
#include <bits/stdc++.h>

using namespace std;

void decode(int N, int L, int X[]) {
    int P3[] = {0, 1, 3, 9, 27, 2, 4, 6, 10, 12,
    18, 28, 30, 36, 54, 5, 7, 11, 13, 15, 19,
    21, 29, 31, 33, 37, 39, 45, 55, 57, 63, 8,
    14, 16, 20, 22, 24, 32, 34, 38, 40, 42, 46,
    48, 56, 58, 60, 64, 66, 72, 17, 23, 25, 35,
    41, 43, 47, 49, 51, 59, 61, 65, 67, 69};

    int A[81], C[256], M[64], P2[64];

    memset(A, -1, sizeof A);
    memset(C, 0, sizeof C);

    if (N == 1) return output(X[0]);
    for (int i = 0; i < L; i++) C[X[i]]++;
    if (N > 43) {
        for (int i = 0, j = 0; i < 256; i++) {
            int x = C[i] / 3;
            while (x--) M[j++] = i;
        }
        for (int i = 0; i + 1 < N; i++) {
            int x = 0;
            for (int j = 3; j >= 0; j--)
                x = x * 3 + C[i * 4 + j] % 3;
            A[x] = M[i];
        }
        for (int i = 0; i < N; i++)
            if (A[P3[i]] >= 0)
                output(A[P3[i]]);
            else output(M[N - 1]);
    } else {
        int l = 0; while ((1 << l) < N) l++;
        iota(P2, P2 + (1 << l), 0);
        sort(P2, P2 + (1 << l), [](int i, int j) {
            return __builtin_popcount(i)
            < __builtin_popcount(j);
        });
        for (int i = 0, j = 0; i < 256; i++) {
            int x = C[i] >> 1;
            while (x--) M[j++] = i;
        }
        for (int i = 0; i + 1 < N; i++) {
            int x = 0;
            for (int j = l - 1; j >= 0; j--)
                x = (x << 1) + (C[i * l + j] & 1);
            A[x] = M[i];
        }
        for (int i = 0; i < N; i++)
            if (A[P2[i]] >= 0)
                output(A[P2[i]]);
            else output(M[N - 1]);
    }
}
