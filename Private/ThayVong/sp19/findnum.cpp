#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("findnum.inp", "r", stdin);
    freopen("findnum.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    long long n, k, res = 1;
    cin >> n >> k;
    for (long long i = 2; 1ll * i * i <= k; i++)
        if (k % i == 0) {
            int cnt = 0;
            while (k % i == 0) {
                cnt++; k /= i;
                if (cnt == n) {
                    res *= i; cnt = 0;
                }
            }
        }
    if (k > 1 && n == 1) res *= k;
    cout << res << '\n';
}