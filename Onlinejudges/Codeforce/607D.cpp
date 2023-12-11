
// Problem : D. Miss Punyverse
// Contest : Codeforces - Codeforces Round #607 (Div. 1)
// URL : https://codeforces.com/contest/1280/problem/D
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

struct win {
    int w; ll a;
    
    win(int w = 0, ll a = 0): w(w), a(a) {}
    
    bool operator < (const win &o) const {
        return w == o.w ? a < o.a : w < o.w;
    }
};

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 3005;
const win inf = win(0, -1e18);

win dp[N][N], tmp[N];
int a[N], sz[N];
vector <int> g[N];

win operator + (const win &x, const win &y) {
    return win(x.w + y.w, x.a + y.a);
}

win close(const win &x) {
    return win(x.w + (x.a > 0), 0);
}

void dfs(int u, int p = 0) {
    dp[u][0] = win(0, a[u]); sz[u] = 0;
    for (int v : g[u]) {
        if (v == p) continue; dfs(v, u);
        for (int i = 0; i <= sz[u] + sz[v]; i++)
            tmp[i] = inf;
        for (int i = 0; i <= sz[u]; i++)
            for (int j = 0; j <= sz[v]; j++)
                cmax(tmp[i + j], dp[u][i] + dp[v][j]);
        sz[u] += sz[v];
        for (int i = 0; i <= sz[u]; i++)
            dp[u][i] = tmp[i];
    }
    dp[u][++sz[u]] = inf;
    if (!p) return;
    for (int i = sz[u] - 1; ~i; i--)
        cmax(dp[u][i + 1], close(dp[u][i]));
    
}

void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; g[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = x - a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    dfs(1);
    cout << close(dp[1][m - 1]).w << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}