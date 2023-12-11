#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

struct event {
    int x, y, u, v; bool t;

    event(int x, int y, int u, int v, bool t):
    x(x), y(y), u(u), v(v), t(t) {}
};

struct fenwick_tree {
    vector <int> bit; int n;

    void init(int n = 0) {
        bit.resize(n + 1); this->n = n;
    }

    void update(int i, int t) {
        for (; i <= n; i += i & -i) bit[i] += t;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    map <int, int> mp; vector <event> ev;
    fenwick_tree tr[2]; vector <int> cmp[2];
    vector <int> p(n + 1), s(n + 1), b(n + 1);
    vector <int> inc(m + 1), pref(m + 1);
    vector <int> ans(m + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> inc[i];
    for (int i = 1; i <= m; i++) cin >> pref[i];
    for (int i = 1; i <= n; i++) {
        cmp[0].eb(b[i] + p[i]);
        cmp[1].eb(b[i] - p[i] + 1);
    }
    sort(cmp[0].begin(), cmp[0].end());
    sort(cmp[1].begin(), cmp[1].end());
    cmp[0].erase(unique(cmp[0].begin(),
    cmp[0].end()), cmp[0].end());
    cmp[1].erase(unique(cmp[1].begin(),
    cmp[1].end()), cmp[1].end());
    tr[0].init(cmp[0].size());
    tr[1].init(cmp[1].size());
    for (int i = 1; i <= n; i++) {
        ev.eb(p[i], b[i] + p[i], 1, 0, 0);
        ev.eb(s[i] + 1, b[i] + p[i], -1, 0, 0);
        ev.eb(p[i], b[i] - p[i] + 1, -1, 1, 0);
        ev.eb(s[i] + 1, b[i] - p[i] + 1, 1, 1, 0);
    }
    for (int i = 1; i <= m; i++) {
        ev.eb(inc[i], pref[i] + inc[i], i, 0, 1);
        ev.eb(inc[i], pref[i] - inc[i], i, 1, 1);
    }
    sort(ev.begin(), ev.end(),
    [](event p, event q) {
        return p.x != q.x ? p.x < q.x : p.t < q.t;
    });
    for (event e : ev) {
        int i = upper_bound(cmp[e.v].begin(),
        cmp[e.v].end(), e.y) - cmp[e.v].begin();
        if (e.t) ans[e.u] += tr[e.v].query(i);
        else tr[e.v].update(i, e.u);
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " \n"[i == m];
}