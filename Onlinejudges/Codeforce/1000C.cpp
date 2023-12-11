#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct event {
    ll x; int t;
};

const int N = 2e5 + 5;

event ev[N * 2]; ll ans[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        ll l, r; cin >> l >> r;
        ev[i] = {l, 1};
        ev[i + n] = {r + 1, -1};
    }
    sort(ev + 1, ev + 2 * n + 1,
    [&](event a, event b) {
        if (a.x == b.x)
            return a.t < b.t;
        return a.x < b.x;
    });
    int cur = 0; ll lst = 0;
    for (int i = 1; i <= 2 * n; ) {
        ans[cur] += ev[i].x  - lst;
        lst = ev[i].x;
        cur += ev[i++].t;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}