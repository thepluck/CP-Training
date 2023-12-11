#include <bits/stdc++.h>

#define popcnt __builtin_popcount

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 20;
const int M = 10000;

long long dp[1 << N], ans[N];
int a[N][M];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    int all = (1 << n) - 1;
    memset(dp, 0, sizeof dp);
    memset(ans, 0x3f, sizeof ans);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int j = 0; j < m; j++) {
        vector <int> id(n);
        iota(id.begin(), id.end(), 0);
        sort(id.begin(), id.end(),
        [&](int x, int y) {
            return a[x][j] < a[y][j];
        });
        int mask = 0;
        for (int i : id) {
            dp[mask ^ all] -= a[i][j];
            mask ^= 1 << i;
            dp[mask ^ all] += a[i][j];
        }
    }
    for (int j = 0; j < n; j++)
        for (int i = 0; i < all; i++)
            if (i >> j & 1)
                dp[i] += dp[i ^ (1 << j)];
    for (int i = 0; i < all; i++)
        cmin(ans[popcnt(i ^ all)], dp[i]);
    while (q--) {
        int k; cin >> k;
        cout << ans[k] << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}