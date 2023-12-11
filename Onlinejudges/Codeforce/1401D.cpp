
// Problem : D. Maximum Distributed Tree
// Contest : Codeforces - Codeforces Round #665 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1401/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll a[N], b[N]; int sz[N];
vector <int> g[N];

void dfs(int u, int p = 0) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs(v, u); sz[u] += sz[v];
    }
    g[u].clear();
    g[u].shrink_to_fit();
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    dfs(1); ll res = 0;
    int m; cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        b[i - 1] = ll(sz[i]) * (n - sz[i]);
    sort(a + 1, a + m + 1);
    sort(b + 1, b + n);
    for (int i = 1; i < n; i++)
        b[i] %= MOD;
    if (m >= n - 1) {
        for (int i = n; i <= m; i++)
            (a[n - 1] *= a[i]) %= MOD;
        for (int i = 1; i < n; i++)
            (res += a[i] * b[i]) %= MOD;
    }
    else {
        for (int i = 1; i <= m; i++)
            (res += a[i] * b[i - m + n - 1]) %= MOD;
        for (int i = 1; i <= n - 1 - m; i++)
            (res += b[i]) %= MOD;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);    
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}