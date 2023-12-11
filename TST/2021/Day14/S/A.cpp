#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("sumxor.inp", "r", stdin);
    freopen("sumxor.out", "w", stdout);
    long long s, x, a;
    cin >> s >> x;
    if (s < x || ((s ^ x) & 1))
        return cout << 0, 0;
    a = s - x >> 1;
    long long res = 1;
    for (int i = 0; i < 60; i++)
        if (x >> i & 1) {
            if (a >> i & 1) res = 0;
            else res <<= 1;
        }
    cout << (a ? res : res - 2);
}