#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> a, f;
int n, m;

int rec(int i, int j) {
    if (~f[i][j]) return f[i][j];
    f[i][j] = 0;
    if (i + 1 < n && a[i + 1][j] < a[i][j])
        f[i][j] = max(f[i][j], rec(i + 1, j));
    if (j + 1 < m && a[i][j + 1] < a[i][j])
        f[i][j] = max(f[i][j], rec(i, j + 1));
    if (i > 0 && a[i - 1][j] < a[i][j])
        f[i][j] = max(f[i][j], rec(i - 1, j));
    if (j > 0 && a[i][j - 1] < a[i][j])
        f[i][j] = max(f[i][j], rec(i, j - 1));
    return ++f[i][j];
}

int main() {
    freopen("listab.inp", "r", stdin);
    freopen("listab.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    a.resize(n, vector <int> (m));
    f.resize(n, vector <int> (m, -1));
    for (auto &v : a)
        for (int &x : v) cin >> x;
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, rec(i, j));
    cout << res << '\n';
}