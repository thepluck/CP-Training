#include "art.h"
#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    int a[10005];
    vector<int> r(n), b(n);
    iota(r.begin(), r.end(), 1);
    for (int i = 1; i <= n; i++) {
        a[i] = publish(r);
        rotate(r.begin(), r.begin() + 1, r.end());
    }
    for (int i = 1; i <= n; i++) {
        int x = a[i], y = a[i % n + 1];
        b[(x - y + n - 1) / 2] = i;
    }
    answer(b);
}