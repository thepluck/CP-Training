#include <bits/stdc++.h>

using namespace std;

using ii = pair <int, int>;

const int MAXN = 200005;

int A[MAXN];

int getMin(int i, int j) {
    return A[i] < A[j] ? i : j;
}

int getMax(int i, int j) {
    return A[i] > A[j] ? i : j;
}

int getVal(ii i) {
    return A[i.first] - A[i.second];
}

ii getMin(ii i, ii j) {
    return getVal(i) < getVal(j) ? i : j;
}

ii getMax(ii i, ii j) {
    return getVal(i) > getVal(j) ? i : j;
}
struct segTree {
    int minv1, maxv1, minc, tagc;
    int minv2, maxv2;
    int minv3l, minv3r, maxv3l, maxv3r;
    ii maxp1, maxp2, maxp3;
    segTree *lef, *rig;

    void apply(int c) {
        minc += c; tagc += c;
    }

    void push() {
        lef->apply(tagc);
        rig->apply(tagc);
        tagc = 0;
    }

    void pull() {
        minv1 = getMin(lef->minv1, rig->minv1);
        maxv1 = getMax(lef->maxv1, rig->maxv1);
        minv2 = getMin(lef->minv2, rig->minv2);
        maxv2 = getMax(lef->maxv2, rig->maxv2);
        if (lef->minc < rig->minc) {
            minc = lef->minc;
            minv3l = lef->minv3l;
            maxv3l = lef->maxv3l;
            minv3r = getMin(lef->minv3r, rig->minv2);
            maxv3r = getMax(lef->maxv3r, rig->maxv2);
        }
    }

    segTree(int l, int r) {
        if (l == r) {

        }
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;

}
