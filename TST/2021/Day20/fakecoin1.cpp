#include "fakecoinlib1.h"
#include <bits/stdc++.h>

using namespace std;

// int C[100], cnt;

// int get_T() {
//     int T; cin >> T; return T;
// }

// int get_n() {
//     memset(C, 0, sizeof C);
//     int n; cin >> n; cnt = 0;
//     for (int i = 1; i <= n; i++) cin >> C[i];
//     return n;
// }

// int compare(int *A, int l) {
//     int s1 = 0, s2 = 0; cnt++;
//     for (int i = 1; i <= l; i++)
//         s1 += C[A[i]];
//     for (int i = l + 1; i <= 2 * l; i++)
//         s2 += C[A[i]];
//     if (s1 == s2) return 0;
//     return s1 < s2 ? -1 : 1;
// }

// void answer(int res, int r) {
//     cout << (C[res] == r && cnt <= 4 ? "Correct\n" : "Wrong\n");
// }

void calc2(int res, int l, int r, int *A) {
    if (l == r) return answer(l, res);
    if (l + 1 == r) {
        A[1] = l; A[2] = r;
        if (compare(A, 1) == res)
            answer(l, res);
        else answer(r, res);
        return;
    }
    int len = (r - l) / 3 + 1;
    for (int i = l; i < l + len * 2; i++)
        A[i - l + 1] = i;
    int tmp = compare(A, len);
    if (tmp == 0) calc2(res, l + len * 2, r, A);
    else {
        if (tmp == res)
            calc2(res, l, l + len - 1, A);
        else calc2(res, l + len, l + len * 2 - 1, A);
    }
}

void calc1(int n, int l, int r, int *A) {
    if (l == r) {
        A[1] = l; A[2] = n + 1;
        return answer(l, compare(A, 1));
    }
    if (l + 1 == r) {
        A[1] = l; A[2] = r;
        A[3] = n + 1; A[4] = n + 2;
        int res;
        if (compare(A, 2) < 0) res = -1;
        else res = 1;
        calc2(res, l, r, A); return;
    }
    int len = (2 * (r - l + 1) + 2) / 3;
    for (int i = l; i < l + len; i++)
        A[i - l + 1] = i;
    for (int i = 1; i <= len; i++)
        A[i + len] = n + i;
    int res = compare(A, len);
    if (res == 0) calc1(n, l + len, r, A);
    else calc2(res, l, l + len - 1, A);
}

void solve() {
    int n = get_n(); int A[100];
    calc1(n, 1, n, A);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = get_T();
    while (T--) solve();
}