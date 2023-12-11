#include <bits/stdc++.h>
using namespace std;

map <int, int> mp;

int solve(int x, int d) {
    int cnt = 0;
    while (x > 1) {
        int f = 1;
        for (int i = 1; i * i <= x; i++)
            if (x % i == 0) {
                if (i <= d) f = max(f, i);
                if (x / i <= d)
                    f = max(f, x / i);
            }
        if (f == 1) return -1;
        x /= f; cnt++;
    }
    return cnt;
}

int main() {
    freopen("trans.inp", "r", stdin);
    freopen("trans.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int a, b, d;
    cin >> a >> b >> d;
    int g = __gcd(a, b);
    int x = a / g, y = b / g;
    int res = 0, tmp;
    if ((tmp = solve(x, d)) == -1) {
        cout << "-1\n"; return 0;
    }
    res += tmp;
    if ((tmp = solve(y, d)) == -1) {
        cout << "-1\n"; return 0;
    }
    res += tmp; cout << res << '\n';
}