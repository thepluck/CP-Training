#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char s[N][N]; int d[4][N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> (s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            if (s[i][j] == '1')
                d[0][i][j] = d[0][i][j - 1] + 1;
        for (int j = m; j > 0; j--)
            if (s[i][j] == '1')
                d[1][i][j] = d[1][i][j + 1] + 1;
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            if (s[i][j] == '1')
                d[2][i][j] = d[2][i - 1][j] + 1;
        for (int i = n; i > 0; i--)
            if (s[i][j] == '1')
                d[3][i][j] = d[3][i + 1][j] + 1;
    }
    int res = 0, u, v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int cur = min({d[0][i][j],
            d[1][i][j], d[2][i][j], d[3][i][j]});
            if (res < cur) {
                res = cur; u = i; v = j;
            }
        }
    if (res == 0) cout << -1;
    else cout << 4 * res - 3 << '\n' << u << ' ' << v << '\n';
}