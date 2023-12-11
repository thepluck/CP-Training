#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 2005;

struct segment_tree {
    long long sum;
    int tag, l, r, m;
    segment_tree *lef, *rig;

    segment_tree(int l, int r):
    l(l), r(r), sum(0), tag(-1) {
        m = (l + r) / 2;
        if (l == r) return;
        lef = new segment_tree(l, m);
        rig = new segment_tree(m + 1, r);
    }

    void apply(int t) {
        if (t < 0) return;
        sum = ll(r - l + 1) * (tag = t);
    }

    void push() {
        lef->apply(tag);
        rig->apply(tag);
        tag = -1;
    }

    void pull() {
        sum = lef->sum + rig->sum;
    }

    void assign(int x, int y, int t) {
        if (l >= x && r <= y)
            return apply(t);
        push();
        if (m >= x) lef->assign(x, y, t);
        if (m < y) rig->assign(x, y, t);
        pull();
    }
};

struct point {
    int x, y, c;
} P[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K, L;
    cin >> N >> K >> L;
    vector <int> cx, cy;
    for (int i = 0; i < N; i++) {
        cin >> P[i].x >> P[i].y >> P[i].c;
        cx.push_back(P[i].x);
        cy.push_back(P[i].y);
    }
    cx.push_back(0);
    cy.push_back(0);
    cx.push_back(L + 1);
    cy.push_back(L + 1);
    sort(cx.begin(), cx.end());
    sort(cy.begin(), cy.end());
    cx.erase(unique(cx.begin(),
    cx.end()), cx.end());
    cy.erase(unique(cy.begin(),
    cy.end()), cy.end());
    
}