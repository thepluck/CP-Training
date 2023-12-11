#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, u, v;
        cin >> n >> u >> v;
        vector <int> a(n);
        for (int &x : a) cin >> x;
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                int d = abs(a[i] - a[i - 1]);
                if (d > 1) res = 0;
                else res = min(res, (2 - d) * v);
                if (d > 0) res = min(res, u);
                else res = min(res, u + v);
            }
            if (i < n - 1) {
                int d = abs(a[i] - a[i + 1]);
                if (d > 1) res = 0;
                else res = min(res, (2 - d) * v);
                if (d > 0) res = min(res, u);
                else res = min(res, u + v);
            }
        }
        cout << res << '\n';
    }
}