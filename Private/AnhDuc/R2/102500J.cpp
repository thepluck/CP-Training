#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;

int a[N], tr[N * 4][2][2], p[N], n, c, r;

void build(int i, int l, int r) {
    if (l == r) {
        if (a[l] > 0) tr[i][0][0] = 0;
        if (a[l] < 0) tr[i][1][1] = 0;
        return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++) {
            tr[i][x][y] = min({
            tr[i * 2][x][0] + tr[i * 2 + 1][1][y],
            tr[i * 2][x][1] + tr[i * 2 + 1][0][y],
            tr[i * 2][x][y] + r - m, INF,
            tr[i * 2 + 1][x][y] + m - l + 1});
        }
}

void update(int i, int l, int r, int p) {
    if (l == r) {
        tr[i][0][0] = tr[i][1][1] = 0; return;
    }
    int m = (l + r) / 2;
    if (m >= p) update(i * 2, l, m, p);
    else update(i * 2 + 1, m + 1, r, p);
    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++) {
            tr[i][x][y] = min({
            tr[i * 2][x][0] + tr[i * 2 + 1][1][y],
            tr[i * 2][x][1] + tr[i * 2 + 1][0][y],
            tr[i * 2][x][y] + r - m, INF,
            tr[i * 2 + 1][x][y] + m - l + 1});
        }
}

int getMin() {
    return min({tr[1][0][0], tr[1][1][1], n,
                tr[1][0][1], tr[1][1][0]});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(tr, 0x3f, sizeof tr);
    cin >> n >> c >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; p[i] = i;
    }
    build(1, 1, n);
    sort(p + 1, p + n + 1, [&](int i, int j) {
        return abs(a[i]) < abs(a[j]);
    });
    long long res = 1ll * getMin() * r;
    for (int i = 1; i <= n; i++) {
        update(1, 1, n, p[i]);
        res = min(res, 1ll * getMin() * r
        + 1ll * (abs(a[p[i]]) + 1) * c);
    }
    cout << res << '\n';
}