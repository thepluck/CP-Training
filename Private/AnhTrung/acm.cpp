#include <bits/stdc++.h>
using namespace std;

#define ctz __builtin_ctz

const int M = 1 << 11; 

int mx[M], cc[M], a[11];

int main() {
    freopen("acm.inp", "r", stdin);
    freopen("acm.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, res = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) cin >> a[j];
        for (int j = 1; j < M; j++) {
            cc[j] = cc[j - (j & -j)] + a[ctz(j)];
            mx[j] = max(mx[j], cc[j]);
        }
    }
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            if (!(i & j))
                res = max(res, mx[i] + mx[j]
                + mx[M - i - j - 1]);
    cout << res << '\n';
}