#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int val[N * 4], tag[N * 4];
int lo, hi, n, a[N], pos[N * 4];
int cval, cpos, fi[N], se[N];

void build(int i, int l, int r) {
    pos[i] = r;
    if (l < r) {
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
    }
}

void pushTag(int i, int v) {
    val[i] += v; tag[i] += v;
}

void pushDown(int i) {
    pushTag(i * 2, tag[i]);
    pushTag(i * 2 + 1, tag[i]);
    tag[i] = 0;
}

void update(int i, int l, int r, int v) {
    if (l >= lo && r <= hi)
        return pushTag(i, v);
    pushDown(i); int m = (l + r) / 2;
    if (m >= lo) update(i * 2, l, m, v);
    if (m < hi) update(i * 2 + 1, m + 1, r, v);
    if (val[i * 2 + 1] <= val[i * 2]) {
        val[i] = val[i * 2 + 1];
        pos[i] = pos[i * 2 + 1];
    }
    else {
        val[i] = val[i * 2];
        pos[i] = pos[i * 2];
    }
}

void query(int i, int l, int r) {
    if (l >= lo && r <= hi) {
        if (val[i] <= cval) {
            cval = val[i]; cpos = pos[i];
        }
        return;
    }
    pushDown(i); int m = (l + r) / 2;
    if (m >= lo) query(i * 2, l, m);
    if (m < hi) query(i * 2 + 1, m + 1, r);
}

void update(int l, int r, int v) {
    if (l > r) return;
    lo = l; hi = r; update(1, 1, n, v);
}

int query(int l, int r) {
    cval = 1e9; lo = l; hi = r;
    query(1, 1, n);
    return cval ? 0 : cpos;
}

void compress(int n, int a[]) {
    vector <int> val(a + 1, a + n + 1);
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(),
    val.end()), val.end());
    for (int i = 1; i <= n; i++)
        a[i] = upper_bound(val.begin(),
        val.end(), a[i]) - val.begin();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long res = 0; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    compress(n, a); build(1, 1, n);
    int lim = 0;
    for (int i = 1; i <= n; i++) {
        update(se[a[i]] + 1, fi[a[i]], -1);
        update(fi[a[i]] + 1, i, 1);
        lim = max(lim, query(1, i));
        res += i - lim;
        se[a[i]] = fi[a[i]];
        fi[a[i]] = i;
    }
    cout << res << '\n';
}