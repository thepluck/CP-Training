#include <bits/stdc++.h>

using namespace std;

using ld = long double;
using cd = complex <ld>;

const ld PI = acos(-1);

void fft(vector <cd> &a, bool inv) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int m = n >> 1;
        for (; j & m; m >>= 1) j ^= m;
        if (i < (j ^= m)) swap(a[i], a[j]);
    }
    for (int m = 2; m <= n; m <<= 1) {
        ld ang = 2 * PI / m * (inv ? -1 : 1);
        cd wm(cos(ang), sin(ang));
        for (int i = 0; i < n; i += m) {
            cd w(1);
            for (int j = 0; j < m / 2; j++) {
                cd u = a[i + j];
                cd v = a[i + j + m / 2] * w;
                a[i + j] = u + v;
                a[i + j + m / 2] = u - v;
                w *= wm; 
            }
        }
    }
    if (inv) for (cd &x : a) x /= n;
}

template <class T>
vector <T> convolution(
const vector <T> &a, const vector <T> &b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    vector <cd> fa(a.begin(), a.end());
    vector <cd> fb(b.begin(), b.end());
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    vector <T> res(n);
    for (int i = 0; i < n; i++)
        res[i] = round(fa[i].real());
    return res;
}

void solve() {
    int n; cin >> n;
    vector <int> a(n), b(n);
    string s; cin >> s;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] == 'V';
        b[i] = s[i] == 'K';
    }
    reverse(a.begin(), a.end());
    vector <int> c = convolution(a, b);
    vector <char> mark(n + 1, 1);
    for (int i = 0; i < c.size(); i++)
        if (c[i]) mark[abs(i + 1 - n)] = 0;
    int res = 0;
    for (int i = n; i > 0; i--) {
        for (int j = i * 2; j <= n; j += i)
            mark[i] &= mark[j];
        if (mark[i]) res++;
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++)
        if (mark[i]) cout << i << ' ';
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}
