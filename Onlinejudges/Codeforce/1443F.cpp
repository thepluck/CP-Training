#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

long long s[N], c[N], fac[N], a[N];
bool vs[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        s[i] = s[i - 1] + i;
        if (i <= 15) fac[i] = fac[i - 1] * i;
    }
    long long k = 0;
    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 2) {
            int x; cin >> x; k += x;
            int lim = max(1, n - 15);
            for (int i = lim; i <= n; i++) vs[i] = 0;
        }
    }
}