#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N]; int c[N], a[N];

int main() {
    freopen("bitstr.inp", "r", stdin);
    freopen("bitstr.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> (s + 1) >> m;
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - '0';
    int zero = 0, one = 0;
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
        if (a[i] ^ (c[i] & 1)) {
            if (i <= n - m + 1) {
                c[i]++; c[i + m]--;
                zero++;
            }
            else {
                zero = 1e9; break;
            }
        }
    }
    memset(c, 0, sizeof c);
    for (int i = 1; i <= n; i++) {
        c[i] += c[i - 1];
        if (!(a[i] ^ (c[i] & 1))) {
            if (i <= n - m + 1) {
                c[i]++; c[i + m]--;
                one++;
            }
            else {
                one = 1e9; break;
            }
        }
    }
    if (min(zero, one) == 1e9)
        cout << "-1\n";
    else cout << min(zero, one) << '\n';
}