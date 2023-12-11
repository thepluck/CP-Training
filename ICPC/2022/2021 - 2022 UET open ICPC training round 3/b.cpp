#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    double res = 1e9;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (a[i] > i + 1)
            return cout << -1, 0;
        res = min(res, 1.0 * a[i] / (i + 1));
    }
    cout << res;
}