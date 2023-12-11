#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sum.inp", "r", stdin);
    freopen("sum.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr); int t, n; cin >> t;
    while (cin >> n) {
        long long x, sum = 0;
        while (n--) {cin >> x; sum += x;}
        cout << sum << '\n';
    }
}
