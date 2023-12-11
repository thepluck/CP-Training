#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, m; int k;
    while (cin >> n >> m >> k) {
        long long nimSum = 0;
        while (k--) {
            long long x, y, grundy = 1;
            cin >> x >> y; x--; y--;
            for (int i = 63; i >= 0; i--) {
                bool p = x >= (1ll << i);
                bool q = y >= (1ll << i);
                if (p != q) grundy += 1ll << i;
                x %= 1ll << i; y %= 1ll << i;
            }
            nimSum ^= grundy;
        }
        cout << (nimSum ? "YES\n" : "NO\n");
    }
}