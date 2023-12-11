#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triprime.inp", "r", stdin);
    freopen("triprime.out", "w", stdout);
    int n, cnt = 0; cin >> n;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0) {
            cnt++; if (n / i != i) cnt++;
        }
    if (cnt == 8) {
        cnt = 0;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) {
                while (n % i == 0) {
                    cnt++; n /= i;
                }
                break;
            }
        if (cnt != 1) return cout << "NO\n", 0;
        int tt = 1; while (tt * tt * tt <= n) tt++;
        tt--;
        if (tt * tt * tt == n) return cout << "NO\n", 0;
        cout << "YES\n";
    }
    else cout << "NO\n";
}
