#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 1000005;

int H[MAXN], P[MAXN];

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
        val[i] = max(val[il], val[ir]);
    }

    void add(int l, int r, int v) {
        if (l > r) return;
        x = l; y = r; add(1, 0, N - 1, v);
    }

    void get(int i, int l, int r) {
        if (l >= x && r <= y) {
            res = max(res, val[i]); return;
        }
        int m = (l + r) / 2; push(i);
        if (m >= x) get(il, l, m);
        if (m < y) get(ir, m + 1, r);
    }

    int get(int l, int r) {
        if (l > r) return 0;
        x = l; y = r; res = 0;
        get(1, 0, N - 1); return res;
    }
};

struct FenwickTree {
    vector <int> val; int N;

    FenwickTree(int N): N(N), val(N + 1) {}

    void add(int i, int v) {
        for (; i <= N; i += i & -i)
            val[i] += v;
    }

    int get(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res += val[i];
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i]; P[H[i]] = i;
    }
    vector <int> lef, rig;
    for (int i = 1; i <= N; i++)
        if (lef.empty() || H[i] > H[lef.back()])
            lef.push_back(i);
    for (int i = N; i > 0; i--)
        if (rig.empty() || H[i] < H[rig.back()])
            rig.push_back(i);
    reverse(rig.begin(), rig.end());
    SegmentTree seg(lef.size());
    set <int> prv, cur; long long res = 0;
    for (int i = 0, j = 0, k = 1; i < rig.size(); i++) {
        while (j < lef.size() && lef[j] < rig[i]) j++;
        while (k < rig[i]) cur.insert(H[k++]);
        while (cur.size() && *cur.rbegin() > H[rig[i]]) {
            int p = P[*cur.rbegin()]; cur.erase(H[p]);
            auto it1 = upper_bound(lef.begin(), lef.end(), p);
            auto it2 = upper_bound(lef.begin(), lef.end(), p,
            [&](int x, int y) {return H[x] < H[y];});
            seg.add(it2 - lef.begin(), it1 - lef.begin() - 1, 1);
            prv.insert(H[p]);
        }
        while (prv.size() && *prv.begin() < H[rig[i]]) {
            int p = P[*prv.begin()]; prv.erase(H[p]);
            auto it1 = upper_bound(lef.begin(), lef.end(), p);
            auto it2 = upper_bound(lef.begin(), lef.end(), p,
            [&](int x, int y) {return H[x] < H[y];});
            seg.add(it2 - lef.begin(), it1 - lef.begin() - 1, -1);
        }
        res = max(res, (long long)seg.get(0, j - 1));
    }
    res = -res * 2;
    FenwickTree fen(N);
    for (int i = N; i > 0; i--) {
        res += fen.get(H[i]); fen.add(H[i], 1);
    }
    cout << res << '\n';
}