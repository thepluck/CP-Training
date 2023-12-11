#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

struct rectangle {
    int l, b, r, t;
} rec[MAXN];

bool mark[MAXN], eras[MAXN];
vector <int> rar;
int B[MAXN], T[MAXN];

struct segTree {
    priority_queue <int> col;
    int maxc = -1, minc = 0, l, r, m;
    segTree *lef, *rig;

    segTree(int l, int r): l(l), r(r) {
        m = (l + r) / 2;
        if (l != r) {
            lef = new segTree(l, m);
            rig = new segTree(m + 1, r);
        }
    }

    void pull() {
        while (col.size() && eras[col.top()])
            col.pop();
        if (l == r) {
            if (col.size()) {
                if (mark[col.top()]) maxc = -1;
                else maxc = col.top();
                minc = col.top();
            } else {
                maxc = -1; minc = 0;
            }
            return;
        }
        if (col.size() && col.top()
        > max(lef->maxc, rig->maxc)) {
            if (mark[col.top()] || col.top()
            < min(lef->minc, rig->minc))
                maxc = -1;
            else maxc = col.top();
        } else maxc = max(lef->maxc, rig->maxc);
        minc = max(col.size() ? col.top() : 0,
        min(lef->minc, rig->minc));
    }
    
    void update(int x, int y, int c) {
        if (l >= x && r <= y) {
            if (c > 0) col.push(c);
        } else {
            if (m >= x) lef->update(x, y, c);
            if (m < y) rig->update(x, y, c);
        }
        pull();
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int l, b, r, t;
        cin >> l >> b >> r >> t;
        rec[i] = {l, b, r, t};
        rar.push_back(b);
        rar.push_back(t);
    }
    sort(rar.begin(), rar.end());
    rar.erase(unique(rar.begin(),
    rar.end()), rar.end());
    vector <pair <int, int>> seg;
    for (int i = 1; i <= N; i++) {
        B[i] = upper_bound(rar.begin(),
        rar.end(), rec[i].b) - rar.begin();
        T[i] = lower_bound(rar.begin(),
        rar.end(), rec[i].t) - rar.begin();
        seg.push_back({rec[i].l, i});
        seg.push_back({rec[i].r, -i});
    }
    sort(seg.begin(), seg.end());
    segTree ST(1, rar.size());
    for (int i = 0; i < int(seg.size()); i++) {
        int c = seg[i].second;
        if (c < 0) eras[c = -c] = 1;
        ST.update(B[c], T[c], c);
        if (i + 1 < int(seg.size()) &&
        seg[i].first == seg[i + 1].first) continue;
        while (ST.maxc > 0) {
            c = ST.maxc; mark[c] = true;
            ST.update(B[c], T[c], 0);
        }
    }
    int res = 1;
    for (int i = 1; i <= N; i++)
        res += mark[i];
    cout << res << '\n';
}