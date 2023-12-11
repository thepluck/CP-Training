#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
using mat = array <array <int, 2>, 2>;
using ll = long long;

const int K = 100000;
const int L = 1000000000;

int m, a, b;

int madd(int x, int y) {
    if ((x += y) >= m) x -= m;
    return x;
}

int mmul(int x, int y) {
    return ll(x) * y % m;
}

void reset(mat &a) {
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = 0;
}

mat operator * (mat a, mat b) {
    mat c; reset(c);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                c[i][j] = madd(c[i][j],
                mmul(a[i][k], b[k][j]));
    return c;
}

mat pow(mat a, int k) {
    mat res;
    res[0][0] = res[1][1] = 1;
    res[0][1] = res[1][0] = 0;
    for (; k; k >>= 1, a = a * a)
        if (k & 1) res = res * a;
    return res;
}

void solve() {
    map <ii, int> id;
    cin >> m >> a >> b;
    for (int i = 0; i < K; i++) {
        if (!id.count({a, b}))
            id[{a, b}] = i;
        int c = b - a; b = a;
        if ((a = c) < 0) a += m;
    }
    mat p, q, r;
    p[0][0] = 0; p[0][1] = 1;
    p[1][0] = 1; p[1][1] = 1;
    r[0][0] = 1; r[0][1] = 0;
    r[1][0] = 0; r[1][1] = 1;
    p = pow(p, K);
    for (int i = 0; i < L; i += K) {
        q[0][0] = 0; q[0][1] = 1;
        q[1][0] = 0; q[1][1] = 0;
        q = q * r;
        a = q[0][0]; b = q[0][1];
        if (id.count({a, b})) {
            cout << i + id[{a, b}] << '\n';
            return;
        }
        r = r * p;
    }
    cout << "-1\n";
}

int main() {
    freopen("kfib.inp", "r", stdin);
    freopen("kfib.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}