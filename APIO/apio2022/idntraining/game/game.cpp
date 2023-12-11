#include "game.h"
#include <bits/stdc++.h>

namespace {
    #define il i * 2
    using namespace std;
    #define ir i * 2 + 1

    using namespace std;

    vector<int> a, s;
    int n, x, y, res;

    void build(int i, int l, int r) {
        if (l == r) {
            s[i] = a[l]; return;
        }
        int m = (l + r) / 2;
        build(il, l, m);
        build(ir, m + 1, r);
        s[i] = __gcd(s[il], s[ir]);
    }

    void update(int i, int l, int r, int p) {
        if (l == r) {
            s[i] = a[l]; return;
        }
        int m = (l + r) / 2;
        if (m >= p) update(il, l, m, p);
        else update(ir, m + 1, r, p);
        s[i] = __gcd(s[il], s[ir]);
    }

    void get(int i, int l, int r) {
        if (l >= x && r <= y) {
            res = __gcd(res, s[i]); return;
        }
        int m = (l + r) / 2;
        if (m >= x) get(il, l, m);
        if (m < y) get(ir, m + 1, r);
    }

    void update(int p, int v) {
        a[p] = v; update(1, 0, n - 1, p);
    }
    
    int get(int l, int r) {
        if (l > r) return 0;
        x = l; y = r; res = 0;
        get(1, 0, n - 1); return res;
    }

    int find1(int i, int l, int r) {
        if (s[i] % y == 0 || r < x) return n;
        if (l == r) return l;
        int m = (l + r) / 2;
        res = find1(il, l, m);
        if (res == n) res = find1(ir, m + 1, r);
        return res;
    }

    int find2(int i, int l, int r) {
        if (s[i] % y == 0 || l > x) return 0;
        if (l == r) return l;
        int m = (l + r) / 2;
        res = find2(ir, m + 1, r);
        if (res == 0) res = find2(il, l, m);
        return res;
    }

    int find1(int l, int g) {
        x = l; y = g;
        return find1(1, 0, n - 1);
    }

    int find2(int r, int g) {
        x = r; y = g;
        return find2(1, 0, n - 1);
    }
}

void init(vector<int> b) {
    n = b.size();
    a = b; s.resize(4 * n);
    build(1, 0, n - 1);

}

long long modify(int i, int x) {
    update(i, x);
    int l = -1, r = n - 2, g;
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (get(0, m) >= get(m + 1, n - 1))
            l = m;
        else r = m - 1;
    }
    l++; long long cost = 0;
    r = l; g = get(l + 1, n - 1);
    while (r > 0) {
        g = __gcd(g, a[r]);
        int k = find2(r, g);
        cost += 1ll * g * (r - k); r = k;
    }
    g = get(0, l - 1);
    while (l < n) {
        g = __gcd(g, a[l]);
        int k = find1(l, g);
        cost += 1ll * g * (k - l); l = k;
    }
    return cost;
}
