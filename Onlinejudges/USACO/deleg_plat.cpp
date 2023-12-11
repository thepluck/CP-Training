
// Problem : Problem 1. Delegation
// Contest : USACO - USACO 2020 February Contest, Platinum
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=1020
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1e5 + 5;

vector <int> g[N]; int k;

bool ok(const vector <int> &v, int x) {
    int l = 0, r = v.size() - 1;
    for (int i = 0; i < v.size() / 2; i++) {
        if (l == x) l++; if (r == x) r--;
        if (v[l] + v[r] < k) return 0;
        l++; r--;
    }
    return 1;
}

int dfs(int u, int p) {
    vector <int> x, y;
    for (int v : g[u]) {
        if (v == p) continue;
        int d = dfs(v, u) + 1;
        if (!d) return -1;
        x.eb(min(d, k));
    }
    sort(x.begin(), x.end());
    y = x;
    if (!(y.size() & 1))
        y.insert(y.begin(), 0);
    int lo = -1, hi = y.size() - 1;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (ok(y, mi)) lo = mi;
        else hi = mi - 1;
    }
    if (u > 1 && ~lo) return y[lo];
    y = x;
    if (y.size() & 1)
        y.insert(y.begin(), 0);
    if (ok(y, -1)) return 0;
    return -1;
}

int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);
    cin.tie()->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    int lo = 1, hi = n - 1;
    while (lo < hi) {
        k = (lo + hi + 1) / 2;
        if (~dfs(1, 0)) lo = k;
        else hi = k - 1;
    }
    cout << lo << '\n';
}