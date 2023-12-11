#include <bits/stdc++.h>
using namespace std;

set <int> spell[3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int q; cin >> q;
    long long res = 0;
    int light = 0, fire = 0;
    while (q--) {
        int t, d; cin >> t >> d;
        if (d < 0) {
            res += d; light -= t;
            spell[0].erase(-d);
            if (spell[1].erase(-d)) res += d;
            if (!t) spell[2].erase(-d);
        }
        else {
            res += d; light += t;
            spell[0].insert(d);
            if (!spell[1].empty() && d > *spell[1].begin()) {
                res += -*spell[1].begin() + d;
                spell[1].erase(spell[1].begin());
                spell[1].insert(d);
            }
            if (!t) spell[2].insert(d);
        }
        while (spell[1].size() < light) {
            if (spell[1].empty()) {
                if (!spell[0].empty()) {
                    spell[1].insert(*spell[0].rbegin());
                    res += *spell[0].rbegin();
                }
                else break;
            }
            else {
                auto it = spell[0].lower_bound(*spell[1].begin());
                if (it != spell[0].begin()) {
                    spell[1].insert(*(--it)); res += *it;
                }
                else break;
            }
        }
        while (spell[1].size() > light) {
            res -= *spell[1].begin();
            spell[1].erase(spell[1].begin());
        }
        if (spell[1].empty()) cout << res << '\n';
        else {
            if (spell[2].empty()) {
                cout << res - *spell[1].begin() << '\n';
            }
            else {
                if (spell[1].count(*spell[2].rbegin()))
                    cout << res << '\n';
                else cout << res - *spell[1].begin() + *spell[2].rbegin() << '\n';
            }
        }
    }
}
