#include <bits/stdc++.h>

using namespace std;

const int N = 1505;

int a[N][N], l[N], r[N], b[N][N], p[N];
priority_queue <pair <int, int>> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; long long res = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
        for (int j = 1; j <= k; j++)
            res -= a[i][j];
        l[i] = k; r[i] = m;
        pq.emplace(a[i][k] + a[i][m], i);
    }
    int cntr = 0;
    for (int i = 1; i <= n; i++) p[i] = i;
    while (cntr < n / 2 * k) {
        int v, i; tie(v, i) = pq.top(); pq.pop();
        res += v; l[i]--; r[i]--; cntr++;
        if (l[i] > 0)
            pq.emplace(a[i][l[i]] + a[i][r[i]], i);
    }
    cout << res << '\n';
    while (k--) {
        sort(p + 1, p + n + 1,
        [](int i, int j) {return l[i] > l[j];});
        for (int i = 1; i <= n / 2; i++) {
            b[p[i]][l[p[i]]] = k + 1; l[p[i]]--;
        }
        for (int i = n / 2 + 1; i <= n; i++) {
            r[p[i]]++; b[p[i]][r[p[i]]] = k + 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << b[i][j] << " \n"[j == m];
}