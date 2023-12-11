#include "doll.h"
#include <bits/stdc++.h>

using namespace std;

int construct(const vector <int> &A,
int &S, vector <int> &X, vector <int> &Y) {
    int N = A.size();
    if (N == 0) return 0;
    else if (N == 1) return A[0];
    int k = 0;
    while ((1 << k) < N) k++;
    int M = 1 << k;
    vector <int> rev(M), mat(M);
    int root = --S;
    for (int l = 0; l + 1 < k; l++)
        for (int i = 0; i < (1 << l); i++)
            if ((i << (k - l)) +
            (1 << (k - l)) > (M - N)) {
                if ((i << (k - l)) +
                (1 << (k - l - 1)) <= M - N) {
                    X.push_back(root);
                    Y.push_back(--S);
                } else {
                    X.push_back(--S);
                    Y.push_back(--S);
                }
            }
    for (int i = 0, j = 0; i < M; i++) {
        rev[i] = (rev[i >> 1] >> 1)
        | ((i & 1) << (k - 1));
        if (rev[i] >= (M - N))
            mat[rev[i]] = A[j++];
    }
    for (int i = 0; i < (M >> 1); i++)
        if ((i << 1) + 2 > M - N) {
            if ((i << 1) + 1 <= M - N) {
                X.push_back(root);
                Y.push_back(mat[(i << 1) + 1]);
            } else {
                X.push_back(mat[i << 1]);
                Y.push_back(mat[(i << 1) + 1]);
            }
        }
    return root;
}
void create_circuit(int M, vector <int> A) {
    int S = 0; vector <int> X, Y;
    A.push_back(0);
    int root = construct(A, S, X, Y);
    answer(vector <int> (M + 1, root), X, Y);
}
