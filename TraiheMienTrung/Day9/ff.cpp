#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ff.inp", "r", stdin);
    freopen("ff.out", "w", stdout);
    int n, k; cin >> n >> k;
    if (2 * n <= k) cout << "2\n";
    else cout << (n * 2 + k - 1) / k << '\n';
}
