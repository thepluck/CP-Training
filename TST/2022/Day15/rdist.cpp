#include <bits/stdc++.h>

#define int long long

using namespace std;

const int INF = 0x3f3f3f3f;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t, q; cin >> t >> q;
    if (t == 1) {
        int x, y, u, v;
        int mx1 = -INF, mx2 = -INF;
        int mn1 = INF, mn2 = INF;
        int res = 0;
        for (int i = 1; i <= q; i++) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                cin >> x >> y;
                mx2 = max(mx2, y);
                if (mx1 < mx2) swap(mx1, mx2);
                mn2 = min(mn2, y);
                if (mn1 > mn2) swap(mn1, mn2);
            } else {
                string s, t;
                cin >> u >> v >> s >> t;
                if (t == ">=") {
                    res += max(0ll, mx1 + mx2 - 2 * v);
                } else {
                    res += max(0ll, 2 * v - mn1 - mn2);
                }
            }
        }
        cout << res << '\n';
    }
    vector<pair<int, int>> pts;
    if (t == 2) {
        int x, y, u, v;
        int res = 0;
        set<int> cx, cy;
        for (int i = 1; i <= q; i++) {
            int cmd; cin >> cmd;
            if (cmd == 1) {
                cin >> x >> y;
                pts.emplace_back(x, y);
                cx.insert(x); cy.insert(y);
            } else {
                string s, t;
                cin >> u >> v >> s >> t;
                int cur = -1;
                for (auto p : pts) {
                    x = y = -1;
                    if (s == ">=") {
                        auto it = cx.lower_bound(p.first);
                        if (it != cx.begin()) x = *prev(it);
                    } else {
                        auto it = cx.upper_bound(p.first);
                        if (it != cx.end()) x = *it;
                    }
                    if (t == ">=") {
                        auto it = cy.lower_bound(p.first);
                        if (it != cy.begin()) y = *prev(it);
                    } else {
                        auto it = cy.upper_bound(p.first);
                        if (it != cy.end()) y = *it;
                    }
                    if (x >= 0 && y >= 0)
                        cur = max(cur, abs(p.first + x - 2 * u) + abs(p.second + y - 2 * v));
                }
                for (auto p : pts) {
                    bool flag = true;
                    auto it = cx.lower_bound(p.first);
                    if (it != cx.begin() && p.first + *prev(it) > 2 * u) flag = false;
                    it = cx.upper_bound(p.first);
                    if (it != cx.end() && p.first + *it < 2 * u) flag = false;
                    it = cy.lower_bound(p.second);
                    if (it != cy.begin() && p.second + *prev(it) > 2 * v) flag = false;
                    it = cy.upper_bound(p.second);
                    if (it != cy.end() && p.second + *it < 2 * v) flag = false;
                    if (flag) cur = max(cur, 0ll);
                }
                res += cur;
            }
        }
    }
}