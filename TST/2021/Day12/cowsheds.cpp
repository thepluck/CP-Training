#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector <int> par, rnk; int comps;

    DSU(int n): par(n, -1), rnk(n), comps(n) {}

    int find(int u) {
        return par[u] < 0 ? u : par[u] = find(par[u]);
    }

    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (rnk[u] == rnk[v]) rnk[u]++;
        if (rnk[u] > rnk[v]) par[v] = u;
        else par[u] = v;
        comps--; return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    vector <DSU> spt(20, DSU(2 * n));
    for (int i = 0; i < n; i++)
        spt[0].unite(i, 2 * n - 1 - i);
    function <void(int, int, int)> unite =
    [&](int u, int v, int i) {
        if (spt[i].unite(u, v) && i > 0) {
            int m = 1 << (i - 1);
            unite(u, v, i - 1);
            unite(u + m, v + m, i - 1);
        }
    };
    while (q--) {
        int l, r; cin >> l >> r;
        int u = l - 1, v = 2 * n - r;
        int len = (r - l + 1) / 2;
        for (int i = 0; i < 20; i++)
            if (len >> i & 1) {
                unite(u, v, i);
                u += 1 << i; v += 1 << i;
            }
        cout << spt[0].comps << '\n';
    }
}