#include "orallib.h"
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

int main() {
    int n = get_N();
    vector<int> p;
    for (int i = 1; i < n / 2; i++) {
        p.push_back(i);
        p.push_back(i);
    }
    while (p.size() < n) p.push_back(0);
    shuffle(p.begin(), p.end(), rng);
    int cnt = 0;
    for (int x : p) cnt += guess(max(cnt, x));
}