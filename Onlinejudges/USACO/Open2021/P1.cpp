#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
#define il i * 2
#define ir i * 2 + 1
    vector<int> sum1, lazy;
    vector<long long> sum2;
    int N, x, y; long long res = 0;

    void apply(int i, int v) {
        lazy[i] += v;
        sum2[i] += sum1[i] * v;
    }

    void push(int i) {
        apply(il, lazy[i]);
        apply(ir, lazy[i]);
        lazy[i] = 0;
    }

    void pull(int i) {
        sum1[i] = sum1[il] + sum1[ir];
        sum2[i] = sum2[il] + sum2[ir];
    }

    void add(int i, int l, int r, int v) {
        if (l >= x && r <= y)
            return apply(i, v);
        int m = (l + r) / 2; push(i);
        if (m >= x) add(il, l, m, v);
        if (m < y) add(ir, m + 1, r, v);
        pull(i);
    }

    void chk(int i, int l, int r, bool d) {
        if (l == r) {
            if (d) sum1[i] = 1;
            else {
                sum2[i] -= lazy[i];
                sum1[i] = 0;
            }
            return;
        }
        int m = (l + r) / 2; push(i);
        if (m >= x) chk(il, l, m, d);
        else chk(ir, m + 1, r, d);
        pull(i);
    }

    void get(int i, int l, int r) {
        if (l >= x && r <= y) {
            res += sum2[i]; return;
        }
        int m = (l + r) / 2; push(i);
        if (m >= x) get(il, l, m);
        if (m < y) get(ir, m + 1, r);
    }

    void add(int l, int r, int v) {
        if (l <= r) {
            x = l; y = r;
            add(1, 0, N - 1, v);
        }
    }

    void chk(int p, bool d) {
        x = p; chk(1, 0, N - 1, d);
    }

    long long get(int l, int r) {
        if (l > r) return 0;
        x = l; y = r; res = 0;
        get(1, 0, N - 1); return res;
    }

    segment_tree(int N): sum1(N * 4),
    sum2(N * 4), lazy(N * 4), N(N) {}
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    segment_tree seg(N);
    vector<int> last(N, -1), prv(N);
    long long res = 0;
    for (int i = 0, x; i < N; i++) {
        cin >> x; prv[i] = last[x];
        last[x] = i;
        if (prv[i] >= 0) {
            seg.chk(prv[i], 0);
            seg.add(prv[prv[i]] + 1,
            prv[i] - 1, -1);
        }
        res += seg.get(prv[i] + 1, i - 1);
        seg.add(prv[i] + 1, i - 1, 1);
        seg.chk(i, 1);
    }
    cout << res << '\n';
}