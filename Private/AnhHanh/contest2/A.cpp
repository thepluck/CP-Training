#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("flirt.inp", "r", stdin);
    freopen("flirt.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        int last = -1;
        for (int j = 0; j < m; j++) {
            if (!a[i][j]) last = j;
            if (j - last > k) {
                cout << "NO"; return 0;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int last = -1;
        for (int i = 0; i < n; i++) {
            if (!a[i][j]) last = i;
            if (i - last > k) {
                cout << "NO"; return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (!a[i][j]) cout << "0 ";
            else cout << (i + j) % k + 1 << ' ';
        cout << '\n';
    }
}