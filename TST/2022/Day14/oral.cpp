#include "orallib.h"
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

int main() {
    int n = get_N();
    vector<int> p(1, 0);
    for (int i = 1; i <= n; i++) {
        int j = rand(0, min(3, n - int(p.size())));
        while (j--) p.push_back(i);
    }
    shuffle(p.begin(), p.end(), rng);
    int cnt = 0;
    for (int x : p) cnt += guess(max(cnt, x));
}