#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int n = 100000; cout << n << '\n';
    for (int i = 1; i <= n; i++)
        cout << rnd.next(0, 1000000000) << " \n"[i == n];
    for (int i = 1; i <= n; i++)
        cout << rnd.next(0, 1000000000) << " \n"[i == n];
}
