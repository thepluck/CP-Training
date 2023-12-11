#include <bits/stdc++.h>

using namespace std;

struct segTree {
    vector <int> val;
    int lo, hi, n, res;

    segTree(int n): n(n), val(n * 4) {}

    void update(int i, int l, int r, int v) {
        if (l == r) return void(val[i] = v);
        int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v);
        else update(i * 2 + 1, m + 1, r, v);
        val[i] = min(val[i * 2], val[i * 2 + 1]);
    }

    void query(int i, int l, int r) {
        if (l >= lo && r <= hi)
            return void(res = min(res, val[i]));
        int m = (l + r) / 2;
        if (m >= lo) query(i * 2, l, m);
        if (m < hi) query(i * 2 + 1, m + 1, r);
    }

    void update(int p, int v) {
        lo = p; update(1, 1, n, v);
    }

    int query(int l, int r) {
        lo = l; hi = r; res = n;
        query(1, 1, n); return res;
    }
};

const int N = 200005;

int arr[N]; bool mark[N];
vector <int> pos[N];
set <int> last;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    for (int i = 1; i <= k; i++)
        last.insert(pos[i].back());
    memset(mark, 0, sizeof mark);
    segTree ST(n);
    for (int i = 1; i <= n; i++)
        ST.update(i, arr[i]);
    int i = 1;
    while (k--) {
        int j = *last.begin();
        int x = ST.query(i, j);
        cout << x << ' ';
        for (int p : pos[x])
            ST.update(p, n);
        while (arr[i] != x) i++;
        i++; mark[x] = true;
        last.erase(pos[x].back());
    }
}