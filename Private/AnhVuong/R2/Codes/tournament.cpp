#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N], rmq[17][N];
vector <int> in[N], out[N];

struct segTree {
    int tr[N * 4], lo, hi, n;
    
    void build(int i, int l, int r) {
        tr[i] = r - l + 1;
        if (l < r) {
            int m = (l + r) / 2;
            build(i * 2, l, m);
            build(i * 2 + 1, m + 1, r);
        }
    }

    void pushDown(int i) {
        if (tr[i] == 0)
            tr[i * 2] = tr[i * 2 + 1] = 0;
    }

    void update(int i, int l, int r) {
        if (l >= lo && r <= hi) {
            tr[i] = 0; return;
        }
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m);
        if (m < hi) update(i * 2 + 1, m + 1, r);
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    }

    void update(int l, int r) {
        if (l > r) return;
        lo = l; hi = r; update(1, 1, n);
    }

    int getPos(int k) {
        int l = 1, r = n, i = 1;
        while (l < r) {
            pushDown(i);
            int m = (l + r) / 2;
            if (k <= tr[i * 2]) {
                i = i * 2; r = m;
            }
            else {
                k -= tr[i * 2];
                i = i * 2 + 1; l = m + 1;
            }
        }
        return l;
    }
} ST1, ST2;

int getMax(int l, int r) {
    if (l > r) return -1;
    int k = __lg(r - l + 1);
    return max(rmq[k][l],
    rmq[k][r + 1 - (1 << k)]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i < n; i++)
        cin >> rmq[0][i];
    for (int b = 1; b < 17; b++)
        for (int i = 1; i + (1 << b) <= n; i++)
            rmq[b][i] = max(rmq[b - 1][i],
            rmq[b - 1][i + (1 << (b - 1))]);
    ST1.build(1, 1, n); ST2.build(1, 1, n);
    ST1.n = ST2.n = n;
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        l = ST1.getPos(l + 1);
        r = ST2.getPos(r + 1);
        ST1.update(l + 1, r);
        ST2.update(l, r - 1);
        in[l].push_back(r);
        out[r].push_back(l);
    }
    int res = -1, pos, cur = 0;
    for (int i = 1; i <= n; i++) {
        for (int r : in[i])
            if (k > getMax(i, r - 1)) cur++;
        if (cur > res) {
            res = cur; pos = i;
        }
        for (int l : out[i])
            if (k > getMax(l, i - 1)) cur--;
    }
    cout << pos - 1 << '\n';
}