#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll cnt[16][6], pw[16];

void solve() {
    memset(cnt, 0, sizeof cnt);
    ll w, res = 0, way = 1; int c;
    cin >> w >> c;
    for (int i = c; i >= 0; i--)
        for (int j : {5, 3, 2, 1}) {
            ll x = w / (pw[i] * j);
            cnt[i][j] += x;
            w -= x * pw[i] * j;
            res += x;
        }
    if (w > 0) {
        cout << 0 << '\n'; return;
    }
    cout << res << ' ';
    for (int i = c; i >= 0; i--) {
        ll c3 = cnt[3][i];
        ll c2 = cnt[2][i];
        ll c1 = cnt[1][i];
        ll c5 = cnt[5][i];
        
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    pw[0] = 1000;
    for (int i = 1; i <= 15; i++)
        pw[i] = pw[i - 1] * 10;
    int t; cin >> t;
    while (t--) solve();
}