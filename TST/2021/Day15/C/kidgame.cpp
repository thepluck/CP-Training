#include "kidgamelib.h"
#include <bits/stdc++.h>

using namespace std;

int D[505], askCount, _n, _m, askCount2;
int A[505][505];

// int get_T() {
//     int T; cin >> T; return T;
// }

// void get_nm(int &n, int &m) {
//     cin >> n >> m;
//     askCount = 0; _n = n; _m = m;
//     for (int i = 1; i <= n + m + 1; i++)
//         cin >> D[i];
// }

// int ask(int a, int b, int d) {
//     askCount++;
//     if (D[a] == 0) return D[b] == d;
//     if (D[a] == 1) return D[b] != d;
//     if (askCount & 1) return D[b] != d;
//     return D[b] == d;
// }

// void answer(int *C) {
//     for (int i = 1; i <= _n + _m + 1; i++)
//         if (C[i] != D[i]) {
//             cout << "Wrong\n"; exit(0);
//         }
//     cout << "Correct\n";
// }

int ask2(int *C, int a, int b, int d) {
    askCount2++;
    if (C[a] == 0) return C[b] == d;
    if (C[a] == 1) return C[b] != d;
    if (askCount2 & 1) return C[b] != d;
    return C[b] == d;
}

void solve() {
    int n, m, C[505]; get_nm(n, m);
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            if (i != j) A[i][j] = ask(i, j, 0);
    int referee = 0;
    if (A[2][3] ^ (A[1][2] == A[1][3])) {
        C[1] = 2; C[2] = A[2][1]; C[3] = A[3][1];
        bool flag = true; askCount2 = 0;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (i != j && ask2(C, i, j, 0) != A[i][j])
                    flag = false;
        if (flag) referee = 1;

    }
    if (A[1][3] ^ (A[2][1] == A[2][3])) {
        C[2] = 2; C[1] = A[1][2]; C[3] = A[3][2];
        bool flag = true; askCount2 = 0;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (i != j && ask2(C, i, j, 0) != A[i][j])
                    flag = false;
        if (flag) referee = 2;
    }
    if (A[1][2] ^ (A[3][1] == A[3][2])) {
        C[3] = 2; C[1] = A[1][3]; C[2] = A[2][3];
        bool flag = true; askCount2 = 0;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
                if (i != j && ask2(C, i, j, 0) != A[i][j])
                    flag = false;
        if (flag) referee = 3;
    }
    if (referee == 0) {
        for (int i = 4; i <= n + m + 1; i++) {
            A[i][1] = ask(i, 1, 0);
            A[i][i - 1] = ask(i, i - 1, 0);
            if (A[i - 1][1] ^ (A[i][i - 1] == A[i][1])) {
                referee = i; break;
            }
        }
    }
    for (int i = max(referee + 1, 4); i <= n + m + 1; i++)
        A[i][1] = ask(i, 1, 0);
    C[referee] = 2;
    if (referee == 1) {
        for (int i = 2; i <= n + m + 1; i++)
            C[i] = A[i][1];
    }
    else {
        C[1] = A[referee][1] ? 1 : 0;
        for (int i = 2; i <= n + m + 1; i++)
            if (i != referee)
                C[i] = A[i][1] ? C[1] : C[1] ^ 1;
        }
    answer(C);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = get_T();
    while (T--) solve();
}