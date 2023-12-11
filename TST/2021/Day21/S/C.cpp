#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int cur[N], nxt[N], a[N], b[N];
int minA[N][N], minB[N][N];

int main() {
    freopen("array.inp", "r", stdin);
    freopen("array.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        minA[i][i] = i;
        for (int j = i + 1; j <= n; j++)
            minA[i][j] = a[minA[i][j - 1]]
            <= a[j] ? minA[i][j - 1] : j;
    }
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= m; i++) {
        minB[i][i] = i;
        for (int j = i + 1; j <= m; j++)
            minB[i][j] = b[minB[i][j - 1]]
            <= b[j] ? minB[i][j - 1] : j;
    }
    for (int i = 1; i <= n; i++)
        cur[i] = m + 1;
    int k; cin >> k;
    while (k--) {
        for (int i = 0; i <= n; i++)
            nxt[i] = m + 1;
        int x = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int j = cur[i], l;
            if (j > m) continue;
            l = min(n - i + m - j - k, n - i);
            if (l > 0 && (k > 0 || j > 0)) {
                int p = minA[i + 1][i + l];
                x = min(x, a[p]);
            }
            l = min(n - i + m - j - k, m - j);
            if (l > 0 && (k > 0 || i > 0)) {
                int p = minB[j + 1][j + l];
                x = min(x, b[p]);
            }
        }
        cout << x << ' ';
        for (int i = 0; i <= n; i++) {
            int j = cur[i], l;
            if (j > m) continue;
            l = min(n - i + m - j - k, n - i);
            if (l > 0 && (k > 0 || j > 0)) {
                int p = minA[i + 1][i + l];
                if (x == a[p])
                    nxt[p] = min(nxt[p], j);
            }
            l = min(n - i + m - j - k, m - j);
            if (l > 0 && (k > 0 || i > 0)) {
                int p = minB[j + 1][j + l];
                if (x == b[p])
                    nxt[i] = min(nxt[i], p);
            }
        }
        swap(nxt, cur);
    }
}