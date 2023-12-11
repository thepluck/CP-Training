#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("candy.inp", "r", stdin);
    freopen("candy.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, x, r = 0;
    cin >> n >> x;
    vector <int> a(n);
    for (int &y : a) cin >> y;
    sort(a.begin(), a.end());
    for (int y : a)
        if (x >= y) {
            r++; x -= y;
        }
    if (r == n && x > 0)
        cout << n - 1 << '\n';
    else cout << r << '\n';
}