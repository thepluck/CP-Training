#include "game.h"
#include <bits/stdc++.h>

namespace {
    using namespace std;

    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

    vector<int> a;

    void solve(int i, int x, int p, int q) {
        
        if (i < 0) return a.push_back(x);
        if (p < 0) p = ask_minimum_xor(x + (1 << i));
        if (q < 0) q = ask_minimum_xor(x);
        if (~p >> i & 1) solve(i - 1, x + (1 << i), -1, p);
        if (~q >> i & 1) solve(i - 1, x, -1, q);
    }
}

vector<int> play_game(int n) {
    solve(29, 0, -1, -1);
    return a;
}
