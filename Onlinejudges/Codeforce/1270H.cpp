#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int a[N];

struct segTree1 {
    segTree1 *tl, *tr;
    int val, cnt, tag, l, r, m;

    segTree1(int l, int r):
    l(l), r(r), m((l + r) / 2),
    val(0), tag(0), cnt(r - l + 1),
    tl(NULL), tr(NULL) {
        build();
    }

    void pushTag(int v) {
        val += v; tag += v;
    }

    void pushDown() {
        tl->pushTag(tag);
        tr->pushTag(tag);
        tag = 0;
    }

    void build() {
        if (l != r) {
            tl = new segTree1(l, m);
            tr = new segTree1(m + 1, r);
        }
    }

    void add(int x, int y, int v) {
        if (l >= x && r <= y)
            return pushTag(v);
        pushDown();
        if (m >= x) tl->add(x, y, v);
        if (m < y) tr->add(x, y, v);
        val = min(tl->val, tr->val);
        if (val == tl->val)
            cnt = tl->cnt;
        else cnt = 0;
        if (val == tr->val)
            cnt += tr->cnt;
    }
} *st1;

struct segTree2 {
    segTree2 *tl, *tr;
    int l, r, m;
    int minv, maxv, ladj, radj;

    segTree2(int l, int r):
    l(l), r(r), m((l + r) / 2),
    ladj(N), radj(0),
    tl(NULL), tr(NULL) {
        build();
    }

    void build() {
        if (l == r) minv = maxv = a[l];
        else {
            tl = new segTree2(l, m);
            tr = new segTree2(m + 1, r);
            pushUp();
        }
    }

    void pushUp() {
        if (ladj < radj)
            st1->add(ladj + 1, radj, -1);
        minv = min(tl->minv, tr->minv);
        maxv = max(tl->maxv, tr->maxv);
        if (tl->minv < tr->maxv) {
            ladj = tl->findLt(tr->maxv);
            radj = tr->findGt(tl->minv);
        }
        else {
            ladj = N; radj = 0;
        }
        if (ladj < radj)
            st1->add(ladj + 1, radj, 1);
    }

    int findLt(int v) {
        if (l == r) return l;
        if (tl->minv < v)
            return tl->findLt(v);
        return tr->findLt(v);
    }
 
    int findGt(int v) {
        if (l == r) return l;
        if (tr->maxv > v)
            return tr->findGt(v);
        return tl->findGt(v);
    }
 
    void replace(int p, int v) {
        if (l == r) {
            minv = maxv = v; return;
        }
        if (m >= p) tl->replace(p, v);
        else tr->replace(p, v);
        pushUp();
    }
} *st2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    st1 = new segTree1(1, n);
    st2 = new segTree2(1, n);
    while (q--) {
        int p, v; cin >> p >> v;
        st2->replace(p, v);
        cout << st1->cnt << '\n';
    }
}