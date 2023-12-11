//https://csacademy.com/contest/archive/task/falling-balls/statement/

#include <bits/stdc++.h>
using namespace std;

struct segment {
    int l, r, c;

    segment() {}

    segment(int l, int r, int c):
    l(l), r(r), c(c) {}

    bool operator < (const segment &o) const {
        return c < o.c;
    }
};

const int N = 1e5 + 5;

set <segment> s;
vector <int> ans(N);

void add(int l, int r, int c) {
    if (l > r) return;
    auto be = s.lower_bound({0, 0, l});
    auto en = s.upper_bound({0, 0, r});
    if (be == en) return;
    int x = be->l, y = be->r;
    while (be != en) {
        x = min(x, be->l);
        y = max(y, be->r);
        be = s.erase(be);
    }
    s.emplace(x, y, c);
}

void cal() {
    for (auto p : s)
        for (int i = p.l; i <= p.r; i++)
            ans[i] = p.c;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector <segment> v(n);
    for (auto &p : v)
        cin >> p.l >> p.r >> p.c;
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < N; i++)
        s.emplace(i, i, i);
    for (auto p : v) {
        int l = p.l, r = p.r;
        int m = (l + r) / 2;
        add(l, m, l);
        add(m + 1, r, r);
    }
    cal();
    while (m--) {
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}