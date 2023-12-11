
// Problem : G. Sum of Prefix Sums
// Contest : Codeforces - Educational Codeforces Round 82 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1303/problem/G
// Memory Limit : 512 MB
// Time Limit : 6000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

struct line {
    mutable ll k, m, p;
    
    line(ll k, ll m, ll p = 0): k(k), m(m), p(p) {}
    
    bool operator < (const line &o) const {
        return k < o.k;
    }
    
    bool operator < (const ll &x) const {
        return p < x;
    }
};

template <bool type>
struct cht : multiset <line, less <>> {
    const ll inf = 1e18;
    
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    
    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf; return 0;
        }
        if (x->k == y->k)
            x->p = x->m == y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    
    void push(ll k, ll m) {
        if (type) {
            k = -k; m = -m;
        }
        auto z = emplace(k, m), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    void push(line l) {
        if (type) {
            l.k = -l.k; l.m = -l.m;
        }
        auto z = insert(l), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    
    ll query(ll x) {
        if (empty()) return type ? inf : -inf;
        auto l = *lower_bound(x);
        if (type) return -l.k * x - l.m;
        return l.k * x + l.m;
    }
};

const int N = 150005;

int a[N], sz[N];
vector <int> g[N];
bool used[N]; ll res = 0;
vector <vector <line>> head, tail;
cht <0> cc;
    
void dfs_sz(int u, int p = 0) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == p || used[v]) continue;
        dfs_sz(v, u); sz[u] += sz[v];
    }
}

void dfs_head(int u, int p, int d,
ll s, ll ss, vector <line> &sink) {
    d++; s += a[u]; ss += s;
    sink.eb(d, ss);
    for (int v : g[u]) {
        if (v == p || used[v]) continue;
        dfs_head(v, u, d, s, ss, sink);
    }
}

void dfs_tail(int u, int p, int d,
ll s, ll ss, vector <line> &sink) {
    d++; s += a[u]; ss += 1ll * a[u] * d;
    sink.eb(s, ss);
    for (int v : g[u]) {
        if (v == p || used[v]) continue;
        dfs_tail(v, u, d, s, ss, sink);
    }
}

void update() {
    cc.clear();
    for (int i = 0; i < head.size(); i++) {
        for (line l : head[i])
            res = max(res, cc.query(l.k) + l.m);
        for (line l : tail[i])
            cc.push(l);
    }
}

void dfs_sol(int u) {
    dfs_sz(u); int c = u, p = 0;
    while (true) {
        bool ok = 0;
        for (int v : g[c]) {
            if (v == p || used[v]) continue;
            if (sz[v] * 2 >= sz[u]) {
                p = c; c = v; ok = 1; break;
            }
        }
        if (ok) continue;
        break;
    }
    head.clear(); tail.clear();
    used[u = c] = 1;
    for (int v : g[u]) {
        if (used[v]) continue;
        head.eb(); tail.eb();
        dfs_head(v, u, 1, a[u], a[u], head.back());
        dfs_tail(v, u, 0, 0, 0, tail.back());
    }
    head.push_back({line(1, a[u])});
    tail.push_back({line(0, 0)});
    update();
    reverse(head.begin(), head.end());
    reverse(tail.begin(), tail.end());
    update();
    for (int v : g[u])
        if (!used[v]) dfs_sol(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs_sol(1); cout << res << '\n';
}