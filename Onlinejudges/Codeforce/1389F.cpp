#include <bits/stdc++.h>
using namespace std;

#define lb lower_bound
#define ub upper_bound

const int N = 4e5 + 5;

struct segment {
    int l, r, c;
};

struct seg_tree {
    int mx[N * 4], tg[N * 4];
    int lo, hi;

    int ls(int i) {
        return i * 2;
    }

    int rs(int i) {
        return i * 2 + 1;
    }

    void push_down(int i) {
        mx[ls(i)] += tg[i];
        mx[rs(i)] += tg[i];
        tg[ls(i)] += tg[i];
        tg[rs(i)] += tg[i];
        tg[i] = 0;
    }

    void set_max(int i, int l, int r, int v) {
        if (l > hi || r < lo) return;
        if (l >= lo && r <= hi) {
            mx[i] = max(mx[i], v);
            return;
        }
        push_down(i);
        int m = (l + r) / 2;
        set_max(ls(i), l, m, v);
        set_max(rs(i), m + 1, r, v);
        mx[i] = max(mx[ls(i)], mx[rs(i)]);
    }

    void add_val(int i, int l, int r, int v) {
        if (l > hi || r < lo) return;
        if (l >= lo && r <= hi) {
            mx[i] += v; tg[i] += v;
            return;
        }
        push_down(i);
        int m = (l + r) / 2;
        add_val(ls(i), l, m, v);
        add_val(rs(i), m + 1, r, v);
        mx[i] = max(mx[ls(i)], mx[rs(i)]);
    }

    int query(int i, int l, int r) {
        if (l > hi || r < lo) return 0;
        if (l >= lo && r <= hi) return mx[i];
        push_down(i);
        int m = (l + r) / 2;
        return max(query(ls(i), l, m),
                query(rs(i), m + 1, r));
    }

    void set_max(int l, int r, int v) {
        lo = l; hi = r;
        set_max(1, 0, N, v);
    }

    void add_val(int l, int r, int v) {
        lo = l; hi = r;
        add_val(1, 0, N, v);
    }

    int query(int l, int r) {
        lo = l; hi = r;
        return query(1, 0, N);
    }
} st[2];

segment a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, res = 0; cin >> n;
    vector <int> cmp;
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].c;
        a[i].c--; cmp.push_back(a[i].l);
        cmp.push_back(a[i].r);
    }
    sort(cmp.begin(), cmp.end());
    cmp.resize(distance(cmp.begin(),
    unique(cmp.begin(), cmp.end())));
    for (int i = 0; i < n; i++) {
        a[i].l = distance(cmp.begin(),
        ub(cmp.begin(), cmp.end(), a[i].l));
        a[i].r = distance(cmp.begin(),
        ub(cmp.begin(), cmp.end(), a[i].r));
    }
    sort(a, a + n,
    [](segment p, segment q) {
        if (p.r == q.r) return p.l > q.l;
        return p.r < q.r;
    });
    for (int i = 0; i < n; i++) {
        int l = a[i].l, r = a[i].r, c = a[i].c;
        int cur = st[1 - c].query(0, l - 1) + 1;
        res = max(res, cur);
        st[c].set_max(r, r, cur);
        st[1 - c].add_val(0, l - 1, 1);
    }
    cout << res << '\n';
}