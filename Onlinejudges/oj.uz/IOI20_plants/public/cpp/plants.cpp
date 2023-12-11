#include "plants.h"
#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int l, r, m, v, t;
    segment_tree *c[2];

    segment_tree(int l, int r,
    const vector <int> &a):
    l(l), r(r), m((l + r) / 2), t(0) {
        if (l + 1 == r) {
            v = a[l]; return;
        }
        c[0] = new segment_tree(l, m, a);
        c[1] = new segment_tree(m, r, a);
        pull();
    }

    void apply(int x) {
        v -= x; t += x;
    }

    void pull() {
        v = min(c[0]->v, c[1]->v);
    }

    void push() {
        c[0]->apply(t);
        c[1]->apply(t); t = 0;
    }

    void dec(int x, int y) {
        if (x == y) return;
        if (l >= x && r <= y)
            return	apply(1);
        push();
        if (m > x) c[0]->dec(x, y);
        if (m < y) c[1]->dec(x, y);
        pull();
    }

    void del(int p) {
        if (l + 1 == r) v = 1e9;
        else {
            push();
            if (m > p) c[0]->del(p);
            else c[1]->del(p);
            pull();
        }
    }

    int zero() {
        if (l + 1 == r) return l;
        push();
        if (!c[0]->v)
            return c[0]->zero();
        return c[1]->zero();
    }
};

void build(int k, vector <int> r,
vector <int> &idx, vector <int> &ptr) {
    int n = r.size();
    ptr.resize(n + 1);
    idx.resize(n + 1);
    vector <int> que(n + 1);
    que[0] = n; idx[n] = -1;
    int first = 1, last = 1;
    segment_tree seg(0, n, r);
    for (int i = 0, p; i < n; i++) {
        while (seg.v) {
            p = que[first++];
            seg.dec(p - k + n + 1, n);
        }
        p = seg.zero(); idx[p] = i;
        seg.del(p);
        if (p < k - 1)
            seg.dec(0, que[last++] = p);
        else seg.dec(p - k + 1, p);
        ptr[p] = idx[que[first - 1]];
    }
}

vector <int> idxg, idxl;
vector <int> ptrg, ptrl;

void init(int k, vector <int> r) {
    build(k, r, idxg, ptrg);
    for (int &x : r) x = k - 1 - x;
    build(k, r, idxl, ptrl);
}

int compare_plants(int x, int y) {
    if (x > y)
        return -compare_plants(y, x);
    if (idxg[x] > idxg[y] ||
    ptrl[y] >= idxl[x]) return -1;
    if (idxl[x] > idxl[y] ||
    ptrg[y] >= idxg[x]) return 1;
    return 0;
}
