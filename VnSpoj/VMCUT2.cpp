
// Problem : N. VMCUT2 - Cắt cây
// Contest : Codeforces - VNOI Marathon 2015
// URL : https://codeforces.com/group/FLVn1Sc504/contest/272945/problem/N
// Memory Limit : 1024 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

using ii = pair <int, int>;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 100005;

int a[N], m;
vector <int> g[N];

ii dfs(int u, int p) {
    ii res(0, a[u]), cur;
    vector <int> rem;
    for (int v : g[u]) {
        if (v == p) continue;
        cur = dfs(v, u);
        res.fi += cur.fi;
        rem.eb(cur.se);
    }
    sort(all(rem));
    for (int w : rem)
        if (res.se + w <= m)
            res.se += w;
        else res.fi++;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int l = 0, r = 1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; cmax(l, a[i]);
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    while (l < r) {
        m = (l + r) / 2;
        if (dfs(1, 0).fi <= k) r = m;
        else l = m + 1;
    }
    cout << r << '\n';
}