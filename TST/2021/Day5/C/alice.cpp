#include "alicelib.h"
#include <bits/stdc++.h>

using namespace std;

int have0[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int *a, n = get_n(a);
    for (int i = 0; i < n; i++) {
        have0[i] = a[i] == 0;
        if (i > 0)
            have0[i] |= have0[i - 1];
        if (a[i] == 1 && have0[i]) {
            guess(1); return 0;
        }
    }
    bool have1 = false;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < 0) a[i] = get_01(i);
        if (i > 0 && a[i] == 1 && have0[i - 1]) {
            guess(1); return 0;
        }
        have1 |= a[i] == 1;
        if (a[i] == 0 && have1) {
            guess(1); return 0;
        }
    }
    guess(0);
}