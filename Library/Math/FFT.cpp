#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using cd = complex <ld>;

const ld PI = acos(-1);

void FFT(vector <cd> &a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int m = n >> 1;
        for (; j & m; m >>= 1) j ^= m;
        if (i < (j ^= m)) swap(a[i], a[j]);
    }
    for (int m = 1; m * 2 <= n; m <<= 1) {
        ld ang = PI / m * (inv ? -1 : 1);
        cd wm(cos(ang), sin(ang));
        for (int i = 0; i < n; i += m * 2) {
            cd w(1);
            for (int j = 0; j < m; j++) {
                cd u = a[i + j];
                cd v = a[i + j + m] * w;
                a[i + j] = u + v;
                a[i + j + m] = u - v;
                w *= wm; 
            }
        }
    }
    if (inv) for (cd &x : a) x /= n;
}
