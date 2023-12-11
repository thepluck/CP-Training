#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (n * m - k & 1)
        return cout << 0, 0;
    int res = n + m - 2 * (k + 1);
    while (k--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        res += x - u + y - v;
    }
    cout << res << '\n';
}