#include <bits/stdc++.h>

using namespace std;

int a[10005][10005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k; k--;
        for (int i = 0; i < n; i++)
            for (int j = 0; i + j < n; j++)
                a[i][j] = 0;
        a[0][0] = k;
        for (int i = 0; i < n; i++)
            for (int j = 0; i + j < n; j++) {
                a[i + 1][j] += (a[i][j] + 1) / 2;
                a[i][j + 1] += (a[i][j]) / 2;
            }
        int x = 0, y = 0;
        while (x + y < n - 1) {
            if (a[x][y] & 1) y++; else x++;
        }
        cout << y << '\n';
    }
}