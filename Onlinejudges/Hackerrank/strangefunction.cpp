#include <bits/stdc++.h>

using namespace std;

#define il i * 2
#define ir i * 2 + 1

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

struct segment_tree {
    vector<long long> seg, tag;
    int n, x, y; long long res;

    segment_tree(int n): n(n),
    seg(n * 4), tag(n * 4) {}

    void apply(int i, long long v) {
        seg[i] += v; tag[i] += v;
    }

    void push(int i) {
        apply(il, tag[i]);
        apply(ir, tag[i]);
        tag[i] = 0;
    }

    void add(int i, int l, int r, int v) {
        if (l >= x && r <= y)
            return apply(i, v);
        int m = (l + r) / 2; push(i);
        if (m >= x) add(il, l, m, v);
        if (m < y) add(ir, m + 1, r, v);
        seg[i] = max(seg[il], seg[ir]);
    }

    void get(int i, int l, int r) {
        if (l >= x && r <= y) {
            cmax(res, seg[i]); return;
        }
        int m = (l + r) / 2; push(i);
        if (m >= x) get(il, l, m);
        if (m < y) get(ir, m + 1, r);
    }

    void add(int l, int r, int v) {
        x = l; y = r; add(1, 0, n - 1, v);
    }

    long long get(int l, int r) {
        x = l; y = r; res = 0;
        get(1, 0, n - 1); return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    segment_tree seg(n);
    vector<pair<int, int>> gcds;
    stack<int> stk; stk.push(-1);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        while (stk.size() > 1 && a[stk.top()] < a[i]) {
            int r = stk.top(); stk.pop();
            seg.add(stk.top() + 1, r, a[r] - a[i]);
        }
        stk.push(i);
        for (auto &p : gcds)
            p.second = __gcd(p.second, abs(a[i]));
        gcds.emplace_back(i, abs(a[i]));
        int cur = i;
        vector<pair<int, int>> tmps;
        for (int j = gcds.size() - 1; j >= 0; j--) {
            int k = j;
            while (k > 0 && gcds[k - 1].second == gcds[j].second) k--;
            res = max(res, seg.get(gcds[k].first, cur) * gcds[j].second);
            tmps.push_back(gcds[k]);
        }
        reverse(tmps.begin(), tmps.end()); swap(gcds, tmps);
        seg.add(0, i, a[i]);
    }
    cout << res;
}