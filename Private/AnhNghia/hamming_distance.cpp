//https://csacademy.com/contest/round-67/task/hamming-distances/statement/
#include <bits/stdc++.h>
using namespace std;

int cnt[256][256][9];
int ans[17], bit[256];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 256; i++)
        bit[i] = __builtin_popcount(i);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < 17; j++)
            ans[j] = 0;
        int le = x >> 8, ri = x & 255;
        for (int j = 0; j < 256; j++)
            for (int k = 0; k < 9; k++)
                ans[bit[j ^ ri] + k]
                += cnt[le][j][k];
        for (int j = 0; j < 256; j++)
            cnt[j][ri][bit[j ^ le]]++;
        for (int j = 0; j <= m; j++)
            cout << ans[j] << ' ';
        cout << '\n';
    }
}