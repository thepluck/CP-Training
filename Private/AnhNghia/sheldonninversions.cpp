//https://codeforces.com/group/sd4r2IvEfL/contest/247243/problem/A

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int DIV = 5e8 + 4;
const int N = 3005;

int val[N], inv[N][N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            inv[i][j] = val[i] > val[j];
    for (int t = 1; t <= q; t++) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        inv[x][y] = inv[y][x] =
        mul(add(inv[x][y], inv[y][x]), DIV);
        for (int i = 1; i <= n; i++) {
            if (i == x || i == y) continue;
            inv[x][i] = inv[y][i] =
            mul(add(inv[x][i], inv[y][i]), DIV);
            inv[i][x] = inv[i][y] =
            mul(add(inv[i][x], inv[i][y]), DIV);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            res = add(res, inv[i][j]);
    for (int t = 1; t <= q; t++)
        res = add(res, res);
    cout << res << '\n';
}