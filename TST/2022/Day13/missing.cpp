#include "missinglib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, m, a[N], b[N];

// int get_n() {
//     int x; cin >> x; return x;
// }

// int get_m() {
//     int x; cin >> x; return x;
// }

// int ask(int i, int j) {
//     return b[i] >> j & 1;
// }

// void guess(vector<int> res) {
//     for (int x : res) cout << x << ' ';
// }

int ask(int i) {
    if (a[i]) return a[i];
    for (int j = 0; (1 << j) <= n; j++)
        if (ask(i, j)) a[i] += 1 << j;
    return a[i];
}

int main() {
    n = get_n(); m = get_m();
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    a[m + 1] = n + 1;
    int ptr = 1; vector<int> res;
    while (int(res.size()) < n - m) {
        int lo = ptr, hi = m + 1;
        int d = res.size();
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (ask(mi) != mi + d)
                hi = mi;
            else lo = mi + 1;
        }
        for (int i = hi + d; i < ask(hi); i++)
            res.push_back(i);
        ptr = hi + 1;
    }
    guess(res);
}
