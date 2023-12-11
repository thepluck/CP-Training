#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int n = 100000, k = 10000, q = 100000;
    cout << n << ' ' << k << ' ' << q << '\n';
    while (n--) {
        int l = rnd.next(1, 500);
        int b = rnd.next(l + 1, 1000000000);
        int a = rnd.next(1, b - l);
        cout << a << ' ' << b << '\n';
    }
    while (q--) {
        int b = rnd.next(2, 1000000000);
        int a = rnd.next(1, b - 1);
        cout << a << ' ' << b << '\n';
    }
}
