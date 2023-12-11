#include <bits/stdc++.h>

using namespace std;

const int V = 300005;
const int N = 100005;

using ll = long long;

struct line {
    ll a, b;

    line(ll a = 0, ll b = -1): a(a), b(b) {}

    ll operator () (int x) const {
        return a * x + b;
    }
};

struct lichao {
    line d; int l, r;
};

lichao seg1[10000005];
int cnt = 0, seg2[N * 4];

void insert1(int i, int l, int r, line d) {
    if (l == r) {
        if (d(l) > seg1[i].d(l))
            seg1[i].d = d;
        return;
    }
    int m = (l + r) / 2;
    if (seg1[i].d.a > d.a)
        swap(seg1[i].d, d);
    if (seg1[i].d(m) < d(m)) {
        if (!seg1[i].l)
            seg1[i].l = ++cnt;
        swap(seg1[i].d, d);
        insert1(seg1[i].l, l, m, d);
    } else {
        if (!seg1[i].r)
            seg1[i].r = ++cnt;
        insert1(seg1[i].r, m + 1, r, d);
    }
}

ll get1(int i, int l, int r, int x) {
    if (!i || l == r) return seg1[i].d(x);
    int m = (l + r) / 2;
    if (m >= x) return max(seg1[i].d(x),
            get1(seg1[i].l, l, m, x));
    return max(seg1[i].d(x),
    get1(seg1[i].r, m + 1, r, x));
}

void build(int i, int l, int r) {
    seg2[i] = ++cnt;
    if (l != r) {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void insert2(int i, int l, int r, int p, line d) {
    insert1(seg2[i], 0, V, d);
    if (l != r) {
        int m = (l + r) / 2;
        if (m >= p) insert2(i * 2, l, m, p, d);
        else insert2(i * 2 + 1, m + 1, r, p, d);
    }
}

int get2(int i, int l, int r, line d) {
    if (get1(seg2[i], 0, V, d.a) < d.b) return 0;
    if (l == r) return l;
    int m = (l + r) / 2;
    int p = get2(i * 2 + 1, m + 1, r, d);
    if (!p) p = get2(i * 2, l, m, d);
    return p;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= cnt; i++) {
        seg1[i].d = line();
        seg1[i].l = seg1[i].r = 0;
    }
    cnt = 0; build(1, 1, n);
    while (n--) {
        int a, x; ll b, y;
        cin >> a >> b >> x >> y;
        insert2(1, 1, n, get2(1, 1, n,
        line(b, y)), line(a, x));
    }
    cout << get2(1, 1, n, line(0, 0)) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}