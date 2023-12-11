
// Problem : Product on the segment by modulo 
// Contest : CodeChef - Practice(Medium)
// URL : https://www.codechef.com/problems/SEGPROD
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1050000;
const int LG = 20;

int t[LG][N], lg[N], a[N], b[N];

void solve() {
    int n, p, q; cin >> n >> p >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = (1 << lg[n]) == n ? n : 1 << lg[n] + 1;
    for (int h = 0; (1 << h) < m; h++)
        for (int i = 1 << h; i < m; i += 1 << h + 1) {
            t[h][i - 1] = a[i - 1];
            for (int j = i - 2; j >= i - (1 << h); j--)
                t[h][j] = ll(t[h][j + 1]) * a[j] % p;
            t[h][i] = a[i];
            for (int j = i + 1; j < i + (1 << h); j++)
                t[h][j] = ll(t[h][j - 1]) * a[j] % p;
        }
    int res = 0, l, r;
    for (int i = 0; i < (q >> 6) + 2; i++) cin >> b[i];
    for (int i = 0; i < q; i++) {
        if ((i & 63) == 0) {
            l = (b[i >> 6] + res) % n;
            r = (b[(i >> 6) + 1] + res) % n;
        }
        else {
            l = (l + res) % n;
            r = (r + res) % n;
        }
        if (l > r) swap(l, r);
        if (l == r) res = a[l];
        else {
            int h = lg[l ^ r];
            res = ll(t[h][l]) * t[h][r] % p;
        }
        res = (res + 1) % p;
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 2; i < N; i++)
        lg[i] = lg[i / 2] + 1;
    int t; cin >> t;
    while (t--) solve();
}