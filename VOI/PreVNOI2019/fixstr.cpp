/// Persistent Segment-tree :((((((

/*#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, LG = 15;

struct node {
    int op = 0, cl = 0, le = 0;

    node() {}

    node(char c) {
        if (c == '(') op = 1; else cl = 1;
    }

    node& operator += (const node &o) {
        int add = min(op, o.cl);
        le += o.le + add;
        op += o.op - add;
        cl += o.cl - add;
        return (*this);
    }

    node operator + (const node &o) const {
        return node(*this) += o;
    }

    void join(const node &a, const node &b) {
        int add = min(a.op, b.cl);
        le = a.le + b.le + add;
        op = a.op + b.op - add;
        cl = a.cl + b.cl - add;
    }
};

node tr[N * LG], res; int n, q;
int sz = 0, ls[N * LG], rs[N * LG];
char str[N]; int root[N];

void init(int u, int l, int r) {
    if (l == r) tr[u] = node(str[l]);
    else {
        int m = (l + r) / 2;
        init(ls[u] = ++sz, l, m);
        init(rs[u] = ++sz, m + 1, r);
        tr[u].join(tr[ls[u]], tr[rs[u]]);
    }
}

int update(int u, int l, int r, int p) {
    if (l > p || r < p) return u;
    int v = ++sz;
    if (l == r) {
        tr[v] = tr[u];
        swap(tr[v].op, tr[v].cl);
    }
    else {
        int m = (l + r) / 2;
        ls[v] = update(ls[u], l, m, p);
        rs[v] = update(rs[u], m + 1, r, p);
        tr[v].join(tr[ls[v]], tr[rs[v]]);
    }
    return v;
}

void query(int u, int l, int r, int lo, int hi) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi) {
        res += tr[u]; return;
    }
    int m = (l + r) / 2;
    query(ls[u], l, m, lo, hi);
    query(rs[u], m + 1, r, lo, hi);
}

int update(int u, int p) {
    return update(u, 1, n, p);
}

int query(int u, int l, int r) {
    res = node(); query(u, 1, n, l, r);
    return r - l + 1 - res.le * 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> (str + 1) >> q;
    n = strlen(str + 1); init(0, 1, n);
    for (int i = 1; i <= q; i++) {
        char cmd; cin >> cmd;
        if (cmd == 'C') {
            int p; cin >> p;
            root[i] = update(root[i - 1], p);
        }
        if (cmd == 'Q') {
            int l, r; cin >> l >> r;
            root[i] = root[i - 1];
            cout << query(root[i], l, r) << '\n';
        }
        if (cmd == 'U') {
            int k; cin >> k;
            root[i] = root[k - 1];
        }
    }
}*/

/// Offline-solution

#include <bits/stdc++.h>

using namespace std;

struct node {
    int op = 0, cl = 0, le = 0;

    node() {}

    node(char c) {
        if (c == '(') op = 1; else cl = 1;
    }

    node& operator += (const node &o) {
        int add = min(op, o.cl);
        le += o.le + add;
        op += o.op - add;
        cl += o.cl - add;
        return (*this);
    }

    node operator + (const node &o) const {
        return node(*this) += o;
    }
};

struct query {
    int l = 0, r = 0;
};

const int N = 1e6 + 5;

node tr[N * 4], res; query que[N];
vector <int> adj[N]; int lo, hi;
int ans[N], n, q; char str[N];

void init(int i, int l, int r) {
    if (l == r) tr[i] = node(str[l]);
    else {
        int m = (l + r) / 2;
        init(i * 2, l, m);
        init(i * 2 + 1, m + 1, r);
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    }
}

void update(int i, int l, int r) {
    if (l > lo || r < lo) return;
    if (l == r) swap(tr[i].op, tr[i].cl);
    else {
        int m = (l + r) / 2;
        update(i * 2, l, m);
        update(i * 2 + 1, m + 1, r);
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    }
}

void query(int i, int l, int r) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi) res += tr[i];
    else {
        int m = (l + r) / 2;
        query(i * 2, l, m);
        query(i * 2 + 1, m + 1, r);
    }
}

void update(int p) {
    lo = p; update(1, 1, n);
}

int query(int l, int r) {
    lo = l; hi = r; res = node();
    query(1, 1, n);
    return r - l + 1 - res.le * 2;
}

void dfs(int u, int p = -1) {
    int l = que[u].l, r = que[u].r;
    if (l > 0) {
        if (r == 0) update(l);
        else ans[u] = query(l, r);
    }
    for (int v : adj[u])
        if (v != p) dfs(v, u);
    if (l > 0 && r == 0) update(l);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> (str + 1) >> q;
    n = strlen(str + 1);
    for (int i = 1; i <= q; i++) {
        char cmd; cin >> cmd;
        if (cmd == 'Q') {
            cin >> que[i].l >> que[i].r;
            adj[i - 1].push_back(i);
        }
        if (cmd == 'C') {
            cin >> que[i].l;
            adj[i - 1].push_back(i);
        }
        if (cmd == 'U') {
            int k; cin >> k;
            adj[k - 1].push_back(i);
        }
        ans[i] = -1;
    }
    init(1, 1, n); dfs(0);
    for (int i = 1; i <= q; i++)
        if (ans[i] >= 0)
            cout << ans[i] << '\n';
}