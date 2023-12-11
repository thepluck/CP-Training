
// Problem : E. QOS - VOI 2014 - Chất Lượng Dịch Vụ
// Contest : Codeforces - VOI 2014 - practice version
// URL : https://codeforces.com/group/FLVn1Sc504/contest/272397/problem/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int v, w;
    
    edge(int v, int w): v(v), w(w) {}
};

const int N = 1e3 + 5;
const int M = 2e5 + 5;
const int K = 1e9 + 5;
const int V = 105;
const int inf = 0x3f3f3f3f;

int d[N], f[N][V], n, m, t, k, l;
vector <edge> g[N], r[N];

int rec(int u, int p) {
    if (p + d[u] > l || p < 0) return 0;
    if (u == t && p == 0) return 1;
    if (~f[u][p]) return f[u][p];
    f[u][p] = 0;
    for (edge e : g[u])
        if (d[e.v] != inf) {
            f[u][p] += rec(e.v,
            p + d[u] - d[e.v] - e.w);
            if (f[u][p] >= K)
                f[u][p] = K;
        }
    return f[u][p];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    l = inf;
    cin >> n >> m >> t >> k;
    memset(f, -1, sizeof f);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        r[v].eb(u, w);
        l = min(l, w);
    }
    for (int u = 1; u <= n; u++)
        sort(g[u].begin(), g[u].end(),
        [](edge p, edge q) {
            return p.v < q.v;
        });
    memset(d, 0x3f, sizeof d);
    d[t] = 0;
    for (int i = 1; i < n; i++)
        for (int u = 1; u <= n; u++)
            for (edge e : r[u])
                cmin(d[e.v], d[u] + e.w);
    if (d[1] == inf) {
        cout << "-1\n"; return 0;
    }
    l += d[1]; int tot = 0;
    for (int p = 0; p <= l - d[1]; p++) {
        tot += rec(1, p);
        if (tot >= K) tot = K;
    }
    if (tot < k) {
        cout << "-1\n"; return 0;
    }
    int u = 1;
    vector <int> path;
    path.eb(1);
    while (k > 0) {
        if (k == 1 && u == t) break;
        for (edge e : g[u]) {
            if (d[e.v] == inf) continue;
            int cur = 0;
            for (int p = 0;
            p <= l - e.w - d[e.v]; p++) {
                cur += rec(e.v, p);
                if (cur >= K) cur = K;
            }
            if (cur >= k) {
                u = e.v; l -= e.w; break;
            }
            else k -= cur;
        }
        path.eb(u);
    }
    cout << path.size() << '\n';
    for (int u : path)
        cout << u << ' ';
}