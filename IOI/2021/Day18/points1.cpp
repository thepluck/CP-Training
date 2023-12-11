#include <bits/stdc++.h>

using namespace std;


struct point {
    int x, y;

    bool operator < (const point &o) const {
        return x < o.x;
    }
};

struct SegmentTree {
#define il i * 2
#define ir i * 2 + 1 
    
    vector <int> val, tag;
    int N, x, y, res;
    
    SegmentTree(int N):
    N(N), val(N * 4), tag(N * 4) {}

    void apply(int i, int v) {
        val[i] += v; tag[i] += v;
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
        val[i] = min(val[il], val[ir]);
    }

    void add(int l, int r, int v) {
        if (l > r) return;
        x = l; y = r; add(1, 1, N, v);
    }

    void get(int i, int l, int r) {
        if (l >= x && r <= y) {
            res = min(res, val[i]); return;
        }
        int m = (l + r) / 2; push(i);
        if (m >= x) get(il, l, m);
        if (m < y) get(ir, m + 1, r);
    }

    int get(int l, int r) {
        if (l > r) return 0;
        x = l; y = r; res = INT_MAX;
        get(1, 1, N); return res;
    }
};

const int MAXN = 700005;

point P[MAXN];
int minL[MAXN], maxL[MAXN];
int minR[MAXN], maxR[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i].x >> P[i].y;
    sort(P + 1, P + N + 1);
    minL[0] = minR[N + 1] = INT_MAX;
    maxL[0] = maxR[N + 1] = INT_MIN;
    for (int i = 1; i <= N; i++) {
        minL[i] = min(minL[i - 1], P[i].y);
        maxL[i] = max(maxL[i - 1], P[i].y);
    }
    for (int i = N; i > 0; i--) {
        minR[i] = min(minR[i + 1], P[i].y);
        maxR[i] = max(maxR[i + 1], P[i].y);
    }
    int res = INT_MAX;
    SegmentTree seg(N);
    for (int i = 2, j = N - 2, k = N - 2; i < N; i++) {
        while (j > 0 && minL[j] < minR[i + 1]) {
            seg.add(j + 1, j + 1, -minL[j]); j--;
        }
        while (k > 0 && maxL[k] > maxR[i + 1]) {
            seg.add(k + 1, k + 1, maxL[k]); k--;
        }
        seg.add(2, j + 1, -minR[i + 1]);
        seg.add(2, k + 1, maxR[i + 1]);
        seg.add(2, i - 1, P[i].x - P[i - 1].x);
        res = min(res, seg.get(2, i));
        seg.add(2, j + 1, minR[i + 1]);
        seg.add(2, k + 1, -maxR[i + 1]);
    }
    int minX = P[1].x, maxX = P[1].x;
    for (int i = 2; i <= N; i++) {
        res = min(res, maxX - minX + maxR[i] - minR[i]);
        minX = min(minX, P[i].x);
        maxX = max(maxX, P[i].x);
    }
    minX = maxX = P[N].x;
    for (int i = N - 1; i > 0; i--) {
        res = min(res, maxX - minX + maxL[i] - minL[i]);
        minX = min(minX, P[i].x);
        maxX = max(maxX, P[i].x);
    }
    cout << res << '\n';
}