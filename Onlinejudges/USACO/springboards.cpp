
// Problem : Problem 3. Springboards
// Contest : USACO - USACO 2020 January Contest, Gold
// URL : http://www.usaco.org/index.php?page=viewproblem2&cpid=995
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second

struct smth {
    int u, v, i, t;
    
    smth(int u, int v, int i, int t):
    u(u), v(v), i(i), t(t) {}
    
    bool operator < (const smth &o) const {
        return u < o.u || (u == o.u && v < o.v);
    }
};

const int N = 1e5 + 5;

int ans[N];
map <int, int> c;

void insert(int u, int v) {
    auto it = prev(c.upper_bound(u));
    if (it->se <= v) return;
    it++;
    while (it != end(c) && it->se > v)
        c.erase(it++);
    c[u] = v;
}

int main() {
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector <smth> ev; c[0] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        ev.eb(u, v, i, 0);
        ev.eb(x, y, i, 1);
    }
    sort(ev.begin(), ev.end());
    for (auto e : ev)
        if (e.t)
            insert(e.v, ans[e.i] - e.u - e.v);
        else ans[e.i] = e.u + e.v +
        prev(c.upper_bound(e.v))->se;
    cout << c.rbegin()->se + n * 2 << '\n';
}