#include <vector>
#include <algorithm>

using namespace std;

struct segment_tree {
#define il i * 2
#define ir i * 2 + 1
    static const long long INF = 1e18;

    vector<long long> mini, maxi, lazy;
    int n; long long total;

    segment_tree(int n): n(n), mini(n * 4),
    maxi(n * 4), lazy(n * 4), total(0) {}

    void add(int i, int l, int r, int p, int v) {
        if (l >= p) {
            mini[i] += v; maxi[i] += v;
            lazy[i] += v; return;
        }
        int m = (l + r) / 2;
        if (m >= p) add(il, l, m, p, v);
        add(ir, m + 1, r, p, v);
        mini[i] = min(mini[il], mini[ir]) + lazy[i];
        maxi[i] = max(maxi[il], maxi[ir]) + lazy[i];
    }

    void add(int p, int v) {
        total += v; add(1, 0, n - 1, p, v);
    }

    int get(int c) {
        int i = 1, l = 0, r = n - 1;
        long long mx = -INF, mn = INF, lz = 0;
        while (l < r) {
            int m = (l + r) / 2;
            lz += lazy[i];
            if (max(mx, maxi[ir] + lz) -
            min(mn, mini[ir] + lz) >= c) {
                i = ir; l = m + 1;
            }
            else {
                mx = max(mx, maxi[ir] + lz);
                mn = min(mn, mini[ir] + lz);
                i = il; r = m;
            }
        }
        if (mini[i] + lz < total)
            return c - (mx - total);
        return total - mn;
    }
#undef il
#undef ir
};

vector<int> distribute_candies(vector<int> c,
vector<int> l, vector<int> r, vector<int> v) {
    int n = c.size(), q = v.size();
    segment_tree seg(q + 2);
    vector<int> ans;
    seg.add(0, 1e9); seg.add(1, -1e9);
    vector<vector<pair<int, int>>> eve(n + 1);
    for (int i = 0; i < q; i++) {
        eve[l[i]].emplace_back(i + 2, v[i]);
        eve[r[i] + 1].emplace_back(i + 2, -v[i]);
    }
    for (int i = 0; i < n; i++) {
        for (auto p : eve[i])
            seg.add(p.first, p.second);
        ans.push_back(seg.get(c[i]));
    }
    return ans;
}
