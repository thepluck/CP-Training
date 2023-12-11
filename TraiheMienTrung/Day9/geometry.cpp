#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("geometry.inp", "r", stdin);
    freopen("geometry.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        long long x, y, sum = 0;
        while (n--) {
            cin >> x >> y;
            sum += x * y;
        }
        cout << sum << '\n';
    }
}
