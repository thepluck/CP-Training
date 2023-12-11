#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 15;
const int M = 1024 * 30 + 5;

int dp[N][N][M];

int calc(int n, int m, int c) {
    if (c >= M) return M;
    if (n > m) swap(n, m);
    int &res = dp[n][m][c];
    if (res >= 0) return res;
    if (!n || !m)
        return res = c << (n + m);
    if (n == m)
        return res = calc(n - 1, m, c);
    for (int i = 0; i < c; i++)
        cmax(res, min(calc(n, m - 1, c
        + i), calc(n - 1, m, c - i)));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, c;
    memset(dp, -1, sizeof dp);
    while (cin >> n >> m >> c)
        cout << calc(n, m, c) << '\n';
}
