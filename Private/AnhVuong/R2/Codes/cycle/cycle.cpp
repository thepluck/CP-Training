#include "cycle.h"
#include <bits/stdc++.h>

using namespace std;

void escape(int n) {
    if (n == 2) {
        jump(1); return;
    }
    int lo, hi;
    if (jump(0)) {
        lo = (n + 1) / 2; hi = n - 1;
    }
    else {
        lo = 1; hi = (n + 1) / 2 - 1;
    }
    int pre = 0, res;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (jump((pre + n - mi) % n)) {
            hi = mi - 1; res = mi;
        }
        else lo = mi + 1;
        pre = mi;
    }
    jump((pre + n - res) % n);
}