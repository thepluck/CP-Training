#include <bits/stdc++.h>

using namespace std;

struct edge {int u, v, w;};

struct foo {int d, l, r;};

class segTree {
private:
    vector <int> val, cnt, tag;
    int n, lo, hi, res;

    void build(int i, int l, int r) {
        cnt[i] = r - l + 1;
        if (l != r) {
            int m = (l + r) / 2;
            build(i * 2, l, m);
            build(i * 2 + 1, m + 1, r);
        }
    }

    void pushTag(int i, int v) {
        val[i] += v; tag[i] += v;
    }

    void pushDown(int i) {
        pushTag(i * 2, tag[i]);
        pushTag(i * 2 + 1, tag[i]);
        tag[i] = 0;
    }

    void add(int i, int l, int r, int v) {
        if (l >= lo && r <= hi)
            return pushTag(i, v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) add(i * 2, l, m, v);
        if (m < hi) add(i * 2 + 1, m + 1, r, v);
        val[i] = min(val[i * 2], val[i * 2 + 1]);
        if (val[i] == val[i * 2])
            cnt[i] = cnt[i * 2];
        else cnt[i] = 0;
        if (val[i] == val[i * 2 + 1])
            cnt[i] += cnt[i * 2 + 1];
    }

    void get(int i, int l, int r) {
        if (l >= lo && r <= hi) {
            if (val[i] == 0) res += cnt[i];
            return;
        }
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) get(i * 2, l, m);
        if (m < hi) get(i * 2 + 1, m + 1, r);
    }

public:
    segTree(int n): n(n), val(n * 4),
    cnt(n * 4), tag(n * 4) {
        build(1, 1, n);
    };
    
    void add(int l, int r, int v) {
        lo = l; hi = r; add(1, 1, n, v);
    }

    int get(int l, int r) {
        lo = l; hi = r; res = 0;
        get(1, 1, n); return res;
    }
};

void solve() {
    int n, timer = 0; cin >> n;
    vector <edge> lst(n - 1);
    for (auto &e : lst)
        cin >> e.u >> e.v >> e.w;
    sort(lst.begin(), lst.end(),
    [](const edge &p, const edge &q) {
        return p.w < q.w;
    });
    vector <int> par(n + 5);
    vector <int> rnk(n + 5), val(n + 5);
    vector <int> tin(n + 5), tout(n + 5);
    vector <vector <int>> adj(n + 5);
    auto Find = [&](int u) {
        while (par[u]) u = par[u]; return u;
    };
    auto Unite = [&](int u, int v, int w) {
        u = Find(u); v = Find(v);
        if (rnk[u] == rnk[v]) rnk[u]++;
        if (rnk[u] < rnk[v]) swap(u, v);
        par[v] = u; val[v] = w;
        adj[u].push_back(v);
    };
    function <void (int)> DFS = [&](int u) {
        tin[u] = ++timer;
        for (int v : adj[u]) DFS(v);
        tout[u] = timer;
    };
    auto getRange = [&](int u, int l) {
        while (par[u] && val[u] <= l)
            u = par[u];
        int lo = 0, hi = adj[u].size() - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (val[adj[u][mi]] <= l) lo = mi;
            else hi = mi - 1;
        }
        if (adj[u].empty() || val[adj[u][0]] > l)
            return make_pair(tin[u], tin[u]);
        return make_pair(tin[u], tout[adj[u][lo]]);
    };
    for (const auto &e : lst)
        Unite(e.u, e.v, e.w);
    for (int i = 1; i <= n; i++)
        if (!par[i]) DFS(i);
    segTree ST(n); queue <foo> dec;
    int q, x; cin >> q >> x;
    while (q--) {
        int d, u, l, lo, hi;
        cin >> d >> u >> l;
        tie(lo, hi) = getRange(u, l);
        while (dec.size()) {
            auto p = dec.front();
            if (p.d <= d) {
                ST.add(p.l, p.r, -1); dec.pop();
            }
            else break;
        }
        cout << ST.get(lo, hi) << '\n';
        dec.push({d + x, lo, hi});
        ST.add(lo, hi, 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}