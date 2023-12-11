#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; double p, r = 1.0; cin >> n >> p;
    for (; n; n >>= 1, p = p * (1 - p) * 2)
        if (n & 1) r = p * (1 - r) + r * (1 - p);
    cout << setprecision(10) << fixed << r << '\n';
}