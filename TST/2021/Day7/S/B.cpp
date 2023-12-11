#include <bits/stdc++.h>

using namespace std;

int n, k, m;

int add(int x, int y) {
    if ((x += y) >= m) x -= m;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % m;
}

void solve() {
    cin >> n >> k >> m;
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = mul(res, min(i, k + 1));
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n - k; j++) {
            int cur = 1;
            for (int x = n; x > 0; x--)
                if (x != i)
                    cur = mul(cur,
                    min(n + 1 - x, k + 1));
            res = add(res, cur);
            if (i + 1 == j) continue;
            cur = 1;
            for (int x = n; x > 0; x--)
                if (x < i || x >= j)
                    cur = mul(cur,
                    min(n + 1 - x, k + 1));
            res = add(res, cur);
        }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}