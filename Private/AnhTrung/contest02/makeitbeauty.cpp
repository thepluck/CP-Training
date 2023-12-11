#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 5;

ll s[N], f[N], g[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
        f[i] = max(f[i - 1], -s[i]);
    }
    for (int i = 1; i <= n; i++)
        g[i] = max(g[i - 1], f[i] + s[i] * (1 - x));
    swap(f, g);
    for (int i = 1; i <= n; i++)
        g[i] = max(g[i - 1], f[i] + s[i] * (x - 1));
    swap(f, g);
    for (int i = 1; i <= n; i++)
        g[i] = max(g[i - 1], f[i] + s[i]);
    cout << g[n] << '\n';
}
