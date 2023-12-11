#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int mn[N], par[N], sz[N];
int u[N], v[N], w[N];

int find_set(int u) {
    return u == par[u] ?
    u : par[u] = find_set(par[u]);
}

bool union_set(int u, int v) {
    u = find_set(u); v = find_set(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v]; par[v] = u;
    return 1;
}

bool same_set(int u, int v) {
    return find_set(u) == find_set(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> u[i] >> v[i] >> w[i];
    int cmp = n; w[0] = INT_MAX;
    long long res = 0;
    iota(par + 1, par + n + 1, 1);
    fill_n(sz + 1, n, 1);
    while (cmp > 1) {
        fill_n(mn + 1, n, 0);
        for (int i = 1; i <= m; i++) {
            if (same_set(u[i], v[i]))
                continue;
            int r = find_set(u[i]);
            if (w[mn[r]] > w[i])
                mn[r] = i;
            r = find_set(v[i]);
            if (w[mn[r]] > w[i])
                mn[r] = i;
        }
        for (int i = 1; i <= n; i++)
            if (mn[i]) {
                int e = mn[i];
                if (union_set(u[e], v[e])) {
                    res += w[e]; cmp--;
                }
            }
    }
    cout << res << '\n';
}