#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[50][1][2][3][4][5][6][7][8][9];
int s[9], f[9], pmin, pmax;
int n, m, u[50], v[50];

void add(int u, int v, int x[]) {
    tie(pmin, pmax) = minmax(x[u], x[v]);
    for (int i = 0; i < 9; i++)
        if (x[i] == pmax) x[i] = pmin;
}

ll rec(int i, int x[]) {
    ll &res = dp[i][x[0]][x[1]][x[2]]
    [x[3]][x[4]][x[5]][x[6]][x[7]][x[8]];
    if (res >= 0) return res;
    if (i == m) return equal(x, x + 9, f);
    if (x[u[i]] == x[v[i]])
        return res = rec(i + 1, x) * 2;
    int y[9]; copy(x, x + 9, y);
    add(u[i], v[i], y);
    res = rec(i + 1, x) + rec(i + 1, y);
    return res;
}

int main() {
    freopen("net.inp", "r", stdin);
    freopen("net.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    iota(s, s + 9, 0); cin >> n;
    iota(f, f + 9, 0); cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        add(--u[i], --v[i], f);
    }
    memset(dp, -1, sizeof dp);
    cout << rec(0, s) << '\n';
}