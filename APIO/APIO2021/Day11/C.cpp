#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ii = pair <int, int>;

const int MAXN = 300005;

ii P[MAXN];
int L[MAXN], R[MAXN], N, W, H, res;

struct segment {
    int l, r, id;

    bool operator < (const segment &o) const {
        return l < o.l;
    }
};

struct segTree {
    int l, r, m, val;
    segTree *lef = NULL, *rig = NULL;

    segTree(int l, int r): l(l), r(r) {
        m = (l + r) / 2; val = -2e8;
        if (l != r) {
            lef = new segTree(l, m);
            rig = new segTree(m + 1, r);
        }
    }

    void cmax(int p, int v) {
        val = max(val, v);
        if (l == r) return;
        if (m >= p) lef->cmax(p, v);
        else rig->cmax(p, v);
    }

    int get(int x, int y) {
        if (l >= x && r <= y) return val;
        int res = -2e8;
        if (m >= x)
            res = max(res, lef->get(x, y));
        if (m < y)
            res = max(res, rig->get(x, y));
        return res;
    }

    void reset() {
        val = -2e8;
        if (l != r) {
            lef->reset(); rig->reset();
        }
    }
};

void compute() {
    sort(P + 1, P + N + 1, [](ii x, ii y) {
        return x.se < y.se;
    });
    vector <segment> seg1, seg2;
    P[0] = {W / 2, 0}; P[N + 1] = {W / 2, H};
    P[N + 2] = {0, 0}; P[N + 3] = {W, 0};
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= N; i++)
        if (P[i].fi <= W / 2) {
            seg1.push_back({p1, i, N + 2});
            L[i] = p1; p1 = i;
            while (L[i] > 0 && P[L[i]].fi <= P[i].fi)
                L[i] = L[L[i]];
        } else {
            seg2.push_back({p2, i, N + 3});
            L[i] = p2; p2 = i;
            while (L[i] > 0 && P[L[i]] >= P[i])
                L[i] = L[L[i]];
        }
    seg1.push_back({p1, N + 1, N + 2});
    seg2.push_back({p2, N + 1, N + 3});
    p1 = N + 1; p2 = N + 1;
    for (int i = N; i > 0; i--)
        if (P[i].fi <= W / 2) {
            R[i] = p1; p1 = i;
            while (R[i] != N + 1 && P[R[i]].fi <= P[i].fi)
                R[i] = R[R[i]];
            seg1.push_back({L[i], R[i], i});
        } else {
            R[i] = p2; p2 = i;
            while (R[i] != N + 1 && P[R[i]].fi >= P[i].fi)
                R[i] = R[R[i]];
            seg2.push_back({L[i], R[i], i});
        }
    sort(seg1.begin(), seg1.end());
    sort(seg2.begin(), seg2.end());
    segTree ST1(0, N + 1), ST2(0, N + 1);
    for (int i = 0, j = 0; i < seg1.size(); i++) {
        while (j < seg2.size() && seg2[j].l <= seg1[i].l) {
            ST1.cmax(seg2[j].r, P[seg2[j].r].se + P[seg2[j].id].fi);
            ST2.cmax(seg2[j].r, P[seg2[j].id].fi); j++;
        }
        res = max(res, P[seg1[i].r].se - P[seg1[i].l].se +
        max(W / 2, ST2.get(seg1[i].r, N + 1)) - P[seg1[i].id].fi);
        res = max(res, ST1.get(seg1[i].l, seg1[i].r) -
        P[seg1[i].l].se -  P[seg1[i].id].fi);
    }
    ST1.reset(); ST2.reset();
    for (int i = 0, j = 0; i < seg2.size(); i++) {
        while (j < seg1.size() && seg1[j].l <= seg2[i].l) {
            ST1.cmax(seg1[j].r, P[seg1[j].r].se - P[seg1[j].id].fi);
            ST2.cmax(seg1[j].r, -P[seg1[j].id].fi); j++;
        }
        res = max(res, P[seg2[i].r].se - P[seg2[i].l].se +
        P[seg2[i].id].fi + max(-W / 2, ST2.get(seg2[i].r, N + 1)));
        res = max(res, ST1.get(seg2[i].l, seg2[i].r) -
        P[seg2[i].l].se + P[seg2[i].id].fi);
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> W >> H >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i].fi >> P[i].se;
    compute();
    for (int i = 1; i <= N; i++)
        swap(P[i].fi, P[i].se);
    swap(W, H); compute();
    cout << res * 2 << '\n';
}