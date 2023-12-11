#include "jumps.h"
#include <bits/stdc++.h>

using namespace std;

const int LOG = 19;
const int MAXN = 200005;

struct merge_sort_tree {
    vector <int> V[LOG]; int x, y, N;

    void init(vector <int> A) {
        N = A.size();
        for (int d = 0; d < LOG; d++)
            V[d].resize(N);
        build(0, N, 0, A);
    }

    void build(int l, int r, int d,
    const vector <int> &A) {
        if (l + 1 == r) {
            V[d][l] = A[l]; return;
        }
        int m = (l + r) / 2;
        build(l, m, d + 1, A);
        build(m, r, d + 1, A);
        merge(begin(V[d + 1]) + l, begin(V[d + 1]) + m,
        begin(V[d + 1]) + m, begin(V[d + 1]) + r,
        V[d].begin() + l);
    }

    int pos(int l, int r, int d, int v) {
        if (l >= y || r <= x || V[d][r - 1] < v)
            return x - 1;
        if (l + 1 == r) return l;
        int m = (l + r) / 2;
        int res = pos(m, r, d + 1, v);
        if (res < x) res = pos(l, m, d + 1, v);
        return res;
    }

    int low(int l, int r, int d, int v) {
        if (l >= y || r <= x || V[d][l] > v)
            return -1;
        int m = (l + r) / 2;
        if (l >= x && r <= y)
            return *prev(lower_bound(begin
            (V[d]) + l, begin(V[d]) + r, v));
        return max(low(l, m, d + 1, v),
                    low(m, r, d + 1, v));
    }

    int ext(int l, int r, int d) {
        if (l >= y || r <= x) return -1;
        if (l >= x && r <= y)  return V[d][r - 1];
        int m = (l + r) / 2;
        return max(ext(l, m, d + 1), ext(m, r, d + 1));
    }

    int pos(int l, int r, int v) {
        if (l >= r) return l - 1;
        x = l; y = r; return pos(0, N, 0, v);
    }

    int low(int l, int r, int v) {
        if (l >= r) return -1;
        x = l; y = r; return low(0, N, 0, v);
    }

    int ext(int l, int r) {
        if (l >= r) return -1;
        x = l; y = r; return ext(0, N, 0);
    }
};

int P[2][LOG][MAXN], pos[MAXN];
merge_sort_tree MST;
vector <int> H;

void init(int N, vector <int> H) {
    vector <int> L(N);
    H.push_back(N + 1); ::H = H;
    vector <int> S(1, N);
    for (int i = 0; i < N; i++) {
        while (H[S.back()] < H[i]) S.pop_back();
        L[i] = S.back(); S.push_back(i);
        pos[H[i]] = i;
    }
    S.clear(); S.push_back(N);
    for (int i = N - 1; i >= 0; i--) {
        while (H[S.back()] < H[i]) S.pop_back();
        if (S.back() < N) {
            if (L[i] < N) {
                if (H[L[i]] < H[S.back()]) {
                    P[0][0][i] = L[i];
                    P[1][0][i] = S.back();
                } else {
                    P[0][0][i] = S.back();
                    P[1][0][i] = L[i];
                }
            } else P[0][0][i] = P[1][0][i] = S.back();
        } else P[0][0][i] = P[1][0][i] = L[i];
        S.push_back(i);
    }
    P[0][0][N] = P[1][0][N] = N;
    for (int k = 1; k < LOG; k++)
        for (int i = 0; i <= N; i++) {
            P[0][k][i] = P[0][k - 1][P[0][k - 1][i]];
            P[1][k][i] = P[1][k - 1][P[1][k - 1][i]];
        }
    MST.init(H);
}

int minimum_jumps(int A, int B, int C, int D) {
    int extL = MST.ext(A, B + 1);
    int extM = MST.ext(B + 1, C);
    int extR = MST.ext(C, D + 1);
    if (extM > extR) return -1;
    int p = MST.low(MST.pos(A,
    B + 1, extR) + 1, B + 1, extR);
    if (p < 0) return -1;
    p = pos[p]; int ans = 0;
    for (int k = LOG - 1; k >= 0; k--)
        if (H[P[1][k][p]] <= extM) {
            p = P[1][k][p]; ans += 1 << k;
        }
    if (H[P[1][0][p]] > extR) {
        for (int k = LOG - 1; k >= 0; k--)
            if (H[P[0][k][p]] <= extM) {
                p = P[0][k][p]; ans += 1 << k;
            }
        return ans + 1;
    } else {
        if ((P[0][0][p] >= C && P[0][0][p] <= D)
        || H[p] == extM) return ans + 1;
        ans++; p = P[1][0][p];
        if (p >= C && p <= D) return ans;
        return ans + 1;
    }
    return 0;
}
