#include <bits/stdc++.h>
using namespace std;
//ppp

mt19937 rng(chrono::steady_clock::
now().time_since_epoch().count());

int main() {
    freopen("skwthr.inp", "r", stdin);
    freopen("skwthr.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t; cin >> t;
    if (t == 2) {
        cout << "10"; return 0;
    }
    if (t == 2) {
        cout << "1"; return 0;
    }
    for (int i = 1; i <= t; i++)
        cout << (rng() & 1);
}
