
// Problem : E. Minimal Segment Cover
// Contest : Codeforces - Educational Codeforces Round 66 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1175/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

struct segment {
    int l, r;
};

const int N = 5e5 + 5;
const int LG = 19;

int p[LG][N]; segment a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a, a + n,
    [](segment x, segment y) {
        return x.l < y.l;
    });
    for (int i = 0, j = 0,
    k = -1; i < N; i++) {
        while (j < n && a[j].l <= i)
            k = max(k, a[j++].r);
        if (k >= i) p[0][i] = k;
        else p[0][i] = -1;
    }
    for (int k = 1; k < LG; k++)
        for (int i = 0; i < N; i++)
            if (~p[k - 1][i])
                p[k][i] = p[k - 1][p[k - 1][i]];
    for (int i = 0; i < m; i++) {
        int l, r, res = 0; cin >> l >> r;
        for (int k = LG - 1; ~k; k--)
            if (~p[k][l] && p[k][l] < r) {
                res += 1 << k; l = p[k][l];
            }
        if (p[0][l] >= r)
            cout << res + 1 << '\n';
        else cout << "-1\n";
    }
}