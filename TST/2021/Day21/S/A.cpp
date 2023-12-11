#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("graph.inp", "r", stdin);
    // freopen("graph.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int d, k, n = 0; cin >> d >> k;
    vector <pair <int, int>> edge;
    if (d == 2) {
        while (k > 0) {
            int t = 0, s = 0;
            while (s + t <= k) {
                s += t; t++;
            }
            int x = ++n;
            while (t--)
                edge.emplace_back(x, ++n);
            k -= s;
        }
    }
    else {
        while (k > 0) {
            int t = sqrt(k);
            int x = ++n;
            for (int i = 0; i < t; i++)
                edge.emplace_back(x, ++n);
            for (int i = 0; i < d - 2; i++) {
                edge.emplace_back(x, ++n); x = n;
            }
            int y = n;
            for (int i = 0; i < t; i++)
                edge.emplace_back(y, ++n);
            k -= t * t;
        }
    }
    cout << n << ' ' << edge.size() << '\n';
    for (auto e : edge)
        cout << e.first << ' ' << e.second << '\n';
}