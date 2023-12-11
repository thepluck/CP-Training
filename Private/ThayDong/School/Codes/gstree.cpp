#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100005;

int p[N]; bool c[N];

int fin(int u) {
    return u == p[u] ?
    u : p[u] = fin(p[u]);
}

bool mer(int u, int v) {
    u = fin(u); v = fin(v);
    if (u == v) return 0;
    p[v] = u; return 1;
}

int main() {
    freopen("gstree.inp", "r", stdin);
    freopen("gstree.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long long res = 123456ll * (n - 1);
    while (n--) {
        int x; cin >> x;
        if (c[x]) res -= x; c[x] = 1;
    }
    for (int i = 0; i < N; i++) p[i] = i;
    for (int i = N - 1; i > 0; i--) {
        int u = 0;
        for (int j = i; j < N; j += i)
            if (c[j]) {
                if (!u) u = j;
                else if (mer(u, j)) res -= i;
            }
    }
    cout << res << '\n';
}