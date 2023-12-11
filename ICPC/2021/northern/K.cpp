#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    auto b = a, c = a; vector<int> p(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j]; a[i][j]--;
        }
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < m; j++)
            p[a[k][j]] = j;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                c[i][m - j - 1] = a[i][p[j]];
        sort(c.rbegin(), c.rend());
        b = max(b, c);
    }
    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        cout << b[x - 1][y - 1] + 1 << '\n';
    }
}