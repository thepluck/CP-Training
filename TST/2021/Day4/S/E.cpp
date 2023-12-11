#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("social-distancing.inp", "r", stdin);
    freopen("social-distancing.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int d, n; cin >> d >> n;
    vector <pair <int, int>> a(n);
    vector <int> cnt(d);
    for (auto &p : a) {
        cin >> p.first >> p.second;
        p.first = (p.first % d + d) % d;
        p.second = (p.second % d + d) % d;
    }
    int res = n;
    for (int dx = 0; dx < d; dx++) {
        fill(cnt.begin(), cnt.end(), 0);
        int cur = 0;
        for (auto p : a)
            if (p.first == dx) cur++;
            else cnt[p.second]++;
        res = min(res, *min_element
        (cnt.begin(), cnt.end()) + cur);
    }
    cout << res << '\n';
}