#include <bits/stdc++.h>

using namespace std;

struct node {
    node *lef, *rig;
    
    node(): lef(NULL), rig(NULL) {}
};

const int MAXN = 200005;

node pool[8000005];
node *last = pool;
node *root[101]; int val[MAXN];

void normalize(node *&cur) {
    if (!cur->lef && !cur->rig) cur = NULL;
}


void insert(node *&cur, int l, int r, int p) {
    if (l > p || r < p) return;
    if (!cur) cur = last++;
    if (l != r) {
        int m = (l + r) / 2;
        insert(cur->lef, l, m, p);
        insert(cur->rig, m + 1, r, p);
    }
}

void split(node *&lef, node *&rig, int l, int r, int p) {
    if (!lef || r <= p) return;
    if (l > p) {
        rig = lef; lef = NULL;
    } else {
        int m = (l + r) / 2;
        rig = last++;
        split(lef->lef, rig->lef, l, m, p);
        split(lef->rig, rig->rig, m + 1, r, p);
        normalize(lef); normalize(rig);
    }
}

node *merge(node *lef, node *rig, int l, int r) {
    if (!lef || !rig) return lef ? lef : rig;
    int m = (l + r) / 2;
    lef->lef = merge(lef->lef, rig->lef, l, m);
    lef->rig = merge(lef->rig, rig->rig, m + 1, r);
    return lef;
}

void travel(node *cur, int l, int r, int x) {
    if (!cur) return;
    if (l == r) val[l] = x;
    else {
        int m = (l + r) / 2;
        travel(cur->lef, l, m, x);
        travel(cur->rig, m + 1, r, x);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1, x; i <= N; i++) {
        cin >> x; insert(root[x], 1, N, i);
    }
    int Q; cin >> Q;
    while (Q--) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        node *lef = NULL, *rig = NULL;
        split(root[x], rig, 1, N, r);
        split(root[x], lef, 1, N, l - 1);
        root[y] = merge(root[y], lef, 1, N);
        root[x] = merge(root[x], rig, 1, N);
    }
    for (int x = 1; x <= 100; x++)
        travel(root[x], 1, N, x);
    for (int i = 1; i <= N; i++)
        cout << val[i] << ' ';
}