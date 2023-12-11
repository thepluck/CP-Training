#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int MOD = 998244353;

int f[N][11], g[N][N][11];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

void madd(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

void mmul(int &x, int y) {
    x = (long long)x * y % MOD;
}

void solve() {
    int n, m = 0, odd = 0; cin >> n;
    vector <int> num[2];
    for (int i = 0; i < n; i++) {
        string s; cin >> s; int d = 0;
        for (int j = 0; j < int(s.size()); j++)
            if (j & 1) d -= s[j] - '0';
            else d += s[j] - '0';
        d = (d % 11 + 11) % 11;
        num[s.size() & 1].push_back(d);
        if (s.size() & 1) {
            odd = (odd + d) % 11; m++;
        }
    }
    for (int i = 0; i <= m; i++)
        for (int j = 0; j < 11; j++)
            f[i][j] = 0;
    f[0][0] = 1;
    for (int x : num[1])
        for (int j = (m + 1) / 2; j > 0; j--)
            for (int k = 0; k < 11; k++)
                madd(f[j][(k + x) % 11], f[j - 1][k]);
    int fact = 1;
    for (int i = 1; i <= m / 2; i++)
        mmul(fact, i);
    for (int i = 1; i <= (m + 1) / 2; i++)
        mmul(fact, i);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n + 1; j++)
            for (int k = 0; k < 11; k++)
                g[i][j][k] = 0;
    for (int k = 0; k < 11; k++) {
        int nk = (k * 2 - odd + 11) % 11;
        madd(g[0][m / 2 + 1][nk],
        mul(f[(m + 1) / 2][k], fact));
    }
    for (int i = 0; i < n - m; i++)
        for (int j = 0; j <= i + m + 1; j++)
            for (int k = 0; k < 11; k++) {
                if (!g[i][j][k]) continue;
                int nk = (k + num[0][i]) % 11;
                madd(g[i + 1][j + 1][nk],
                mul(g[i][j][k], j));
                nk = (k - num[0][i] + 11) % 11;
                madd(g[i + 1][j][nk],
                mul(g[i][j][k], i + m + 1 - j));
                
            }
    int res = 0;
    for (int j = 0; j <= n + 1; j++)
        madd(res, g[n - m][j][0]);
    cout << res << '\n';
}

int main() {
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}