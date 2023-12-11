#include <bits/stdc++.h>
#include "nice_lines.h"

using namespace std;

using ld = long double;

const ld EPS = 1e-6;

vector <int> Y; int X;

bool eq(ld x, ld y) {
    return abs(x - y) < EPS;
}

void solve(ld l, ld r, ld fl, ld fr) {
    if (int(ceil(r - l)) == 1)
        return Y.push_back(floor(r));
    ld m = (l + r) / 2;
    ld fm = query(X, m);
    if (eq(fm * 2, fl + fr)) return;
    solve(l, m, fl, fm);
    solve(m, r, fm, fr);
}

void solve(int subtask_id, int N) {
    
}
