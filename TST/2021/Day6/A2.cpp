#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int x[N], y[N], n;
long double f[N];

long double eval(long double a) {
    for (int i = 0; i < n; i++)
        f[i] = a * x[i] - y[i];
    nth_element(f, f + n / 2, f + n);
    long double res = 0;
    for (int i = 0; i < n; i++)
        res += abs(f[i] - f[n / 2]);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    long double lo = -2e6, hi = 2e6;
    for (int i = 0; i < 100; i++) {
        long double ll = lo + (hi - lo) / 3;
        long double rr = hi - (hi - lo) / 3;
        if (eval(ll) < eval(rr)) hi = rr;
        else lo = ll;
    }
    cout << setprecision(10) << fixed << eval(lo);
}