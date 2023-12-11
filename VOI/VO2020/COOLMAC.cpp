#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    freopen("COOLMAC.INP", "r", stdin);
    freopen("COOLMAC.OUT", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int m; cin >> m;
    vector <pair <int, int>> a;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        a.emplace_back(l, r);
    }
    sort(a.begin(), a.end());
    int l = 100000;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        l = min(l, t);
    }
    if (l == 100000) {
        bool flag = 0;
        for (auto s : a)
            if (s.second == l)
                flag = 1;
        if (flag) cout << 1;
        else cout << -1;
        return 0;
    }
    int j = 0, res = 0;
    while (l < 100000) {
        int r = l;
        while (j < m && a[j].first <= l)
            r = max(r, a[j++].second);
        if (r == l) break;
        res++; l = r;
    }
    if (l < 100000) cout << -1;
    else cout << res << '\n';
}
