#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

int main() {
    freopen("river.inp", "r", stdin);
    freopen("river.out", "w", stdout); 
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector <ii> s, t;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        if (l > r) s.emplace_back(r, l);
    }
    sort(s.begin(), s.end(),
    [](ii p, ii q) {
        return p.se < q.se;
    });
    for (ii p : s) {
        int l, r; tie(l, r) = p;
        while (!t.empty() && t.back().se >= l) {
            l = min(l, t.back().fi); t.pop_back();
        }
        t.emplace_back(l, r);
    }
    long long res = 0;
    for (auto p : t) res += p.se - p.fi;
    res += res + m;
    cout << res << '\n';
}