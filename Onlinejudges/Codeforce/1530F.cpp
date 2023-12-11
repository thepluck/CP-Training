#include <bits/stdc++.h>

using namespace std;

const int MOD = 31607;
const int MAXN = 21;

int inv[MOD], prob[MAXN];
int col[MAXN][MAXN];
int win[MAXN][MAXN], N;

int madd(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int msub(int x, int y) {
    return (x -= y) < 0 ? x + MOD : x;
}

int mmul(int x, int y) {
    return x * y % MOD;
}

int mdiv(int x, int y) {
    return mmul(x, inv[y]);
}

int calc(int p) {
    if (p == N + 2) {
        int res = 1;
        for (int i = 0; i < N; i++)
            res = mmul(res, msub(1, prob[i]));
        return res;
    }
    int res = calc(p + 1), tmp = 1;
    if (p == N) {
        for (int i = 0; i < N; i++)
            if (!col[i][i]) {
                prob[i] = mdiv(prob[i], win[i][i]);
                col[i][i] = p + 1;
                tmp = mmul(tmp, win[i][i]);
            }
        res = msub(res, mmul(tmp, calc(p + 1)));
        for (int i = 0; i < N; i++)
            if (col[i][i] == p + 1) {
                prob[i] = mmul(prob[i], win[i][i]);
                col[i][i] = 0;
            }
    } else if (p == N + 1) {
        for (int i = 0; i < N; i++)
            if (!col[i][N - i - 1]) {
                prob[i] = mdiv(prob[i], win[i][N - i - 1]);
                col[i][N - i - 1] = p + 1;
                tmp = mmul(tmp, win[i][N - i - 1]);
            }
        res = msub(res, mmul(tmp, calc(p + 1)));
        for (int i = 0; i < N; i++)
            if (col[i][N - i - 1] == p + 1) {
                prob[i] = mmul(prob[i], win[i][N - i - 1]);
                col[i][N - i - 1] = 0;
            }
    } else {
        for (int i = 0; i < N; i++)
            if (!col[i][p]) {
                prob[i] = mdiv(prob[i], win[i][p]);
                col[i][p] = p + 1;
                tmp = mmul(tmp, win[i][p]);
            }
        res = msub(res, mmul(tmp, calc(p + 1)));
        for (int i = 0; i < N; i++)
            if (col[i][p] == p + 1) {
                prob[i] = mmul(prob[i], win[i][p]);
                col[i][p] = 0;
            }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    inv[1] = 1; cin >> N;
    for (int i = 2; i < MOD; i++)
        inv[i] = MOD - mmul(inv[MOD % i], MOD / i);
    for (int i = 0; i < N; i++) {
        prob[i] = 1;
        for (int j = 0; j < N; j++) {
            cin >> win[i][j];
            win[i][j] = mdiv(win[i][j], 10000);
            prob[i] = mmul(prob[i], win[i][j]);
        }
    }
    cout << msub(1, calc(0));
}