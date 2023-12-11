#include <bits/stdc++.h>
using namespace std;

struct event {
    int x, t;
};

const int Q = 1e5 + 5;

event ev[Q * 2];

int main() {
    freopen("dlight.inp", "r", stdin);
    freopen("dlight.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        ev[i] = {l, 1};
        ev[i + q] = {r + 1, -1};
    }
    sort(ev, ev + q * 2,
    [](event a, event b) {
        if (a.x == b.x)
            return a.t < b.t;
        return a.x < b.x;
    });
    int cur = 0, lst = 0, res = n;
    for (int i = 0; i < 2 * q; ) {
        if (cur % 3)
            res -= ev[i].x - lst;
        lst = ev[i].x;
        cur += ev[i++].t;
    }
    cout << res << '\n';
}