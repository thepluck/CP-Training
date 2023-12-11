#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    long long temp = rnd.next(1ll,
    1ll * (100000 + 2) * (100000 + 1) / 2);
    int n = 0;
    while (1ll * (n + 2) * (n + 1) / 2 < temp) n++;
    temp -= 1ll * (n + 1) * n / 2;
    int A = temp - 1, B = n - A, C = 100000 - A - B;
    n = A + B + C;
    assert(A >= 0 && B >= 0 && C >= 0 && A + B + C == 100000);
    cout << A << ' ' << B << ' ' << C << '\n';
    for (int i = 1; i <= n; i++)
        cout << rnd.next(0, 1000000000) << " \n"[i == n];
    for (int i = 1; i <= n; i++)
        cout << rnd.next(0, 1000000000) << " \n"[i == n];
    for (int i = 1; i <= n; i++)
        cout << rnd.next(0, 1000000000) << " \n"[i == n];
}
