#include <bits/stdc++.h>

using namespace std;

long long grundy(long long x) {
    if (x & 1) return x / 2 + 1;
    if (x % 8 == 6) {
        x /= 8;
        while (x & 1) x /= 2;
        return x / 2;
    }
    if (x % 4 == 0) return x / 4;
    return x / 8;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int test = 5;
    while (test--) {
        int n; cin >> n;
        long long total = 0;
        while (n--) {
            long long x; cin >> x;
            total ^= grundy(x);
        }
        if (total) cout << "yes\n";
        else cout << "no\n";
    }
}