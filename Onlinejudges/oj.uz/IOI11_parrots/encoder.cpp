#include "encoder.h"
#include "encoderlib.h"
#include <bits/stdc++.h>

using namespace std;

void encode(int N, int M[]) {
    int P3[] = {0, 1, 3, 9, 27, 2, 4, 6, 10, 12,
    18, 28, 30, 36, 54, 5, 7, 11, 13, 15, 19,
    21, 29, 31, 33, 37, 39, 45, 55, 57, 63, 8,
    14, 16, 20, 22, 24, 32, 34, 38, 40, 42, 46,
    48, 56, 58, 60, 64, 66, 72, 17, 23, 25, 35,
    41, 43, 47, 49, 51, 59, 61, 65, 67, 69};

    int A[81], P2[64];

    if (N == 1) return send(M[0]);
    if (N > 43) {
        for (int i = 0; i < N; i++) {
            A[P3[i]] = M[i]; send(M[i]);
            send(M[i]); send(M[i]);
        }
        sort(P3, P3 + N, [&](int i, int j) {
            return A[i] < A[j];            
        });
        for (int i = 0; i + 1 < N; i++) {
            int x = P3[i];
            for (int j = 0; j < 4; j++) {
                int y = x % 3;
                while (y--) send(i * 4 + j);
                x /= 3;
            }
        }
    } else {
        int l = 0; while ((1 << l) < N) l++;
        iota(P2, P2 + (1 << l), 0);
        sort(P2, P2 + (1 << l), [](int i, int j) {
            return __builtin_popcount(i)
            < __builtin_popcount(j);
        });
        for (int i = 0; i < N; i++) {
            A[P2[i]] = M[i];
            send(M[i]); send(M[i]);
        }
        sort(P2, P2 + N, [&](int i, int j) {
            return A[i] < A[j];
        });
        for (int i = 0; i + 1 < N; i++) {
            int x = P2[i];
            for (int j = 0; j < l; j++) {
                if (x & 1) send(i * l + j);
                x >>= 1;
            }
        }
    }
}
