#include <bits/stdc++.h>

using namespace std;

int cnt[2][2];

int main() {
    freopen("ztri.in", "r", stdin);
    freopen("ztri.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long long res = 1ll * n * (n - 1) * (n - 2) / 6;
    while (n--) {
        int x, y; cin >> x >> y; cnt[x & 1][y & 1]++;
    }

    res -= 1ll * (cnt[0][0] + cnt[1][1]) * cnt[0][1] * cnt[1][0];
    res -= 1ll * (cnt[0][1] + cnt[1][0]) * cnt[0][0] * cnt[1][1];
    cout << res << '\n';
}
