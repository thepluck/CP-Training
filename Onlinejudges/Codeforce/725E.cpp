// Problem: E. Too Much Money
// Contest: Codeforces - Canada Cup 2016
// URL: https://codeforces.com/contest/725/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int LG = 18;

int a[N]; long long s[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int c, n; cin >> c >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int x = 1; x <= c; x++) {
        int p = upper_bound(a + 1, a + n + 1, x) - a;
        int y = c;
        for (int q = n; q >= p; ) {
            if (y < a[q]) break;
            int lo = p - 1, hi = q - 1;
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                if (s[q] - s[mi] <= y) hi = mi;
                else lo = mi + 1;
            }
            y -= s[q] - s[hi]; if (hi < p) break;
            q = upper_bound(a + p, a + hi, y) - a - 1;
        }
        if (y >= x) y -= x;
        if (p) p = upper_bound(a + 1, a + p, y) - a - 1;
        for (int q = p; q > 0; ) {
            if (y < a[q]) break;
            int lo = 0, hi = q - 1;
            while (lo < hi) {
                int mi = (lo + hi) / 2;
                if (s[q] - s[mi] <= y) hi = mi;
                else lo = mi + 1;
            }
            y -= s[q] - s[hi]; if (hi < 1) break;
            q = upper_bound(a + 1, a + hi, y) - a - 1;
        }
        if (y) return cout << x << '\n', 0;
    }
    cout << "Greed is good\n";
}