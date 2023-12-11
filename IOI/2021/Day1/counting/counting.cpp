#include "counting.h"
#include <bits/stdc++.h>

using namespace std;

int M, C[100][100], DP[105][105];

int add(int x, int y) {
    if ((x += y) >= M) x -= M;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % M;
}

int count_valid_board(int N, int K, int M) {
    ::M = M;
    if (N == 1) return 1 % M;
    for (int i = 0; i <= N; i++)
        C[i][0] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    if (K == 1) {
        int res = 0;
        for (int i = 1; i <= N; i++) {
            DP[i][i] = 1;
            for (int j = i; j > 0; j--)
                for (int k = i )
        }
    }
    return -1;
}
