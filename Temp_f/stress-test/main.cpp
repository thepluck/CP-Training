#include <bits/stdc++.h>

using namespace std;

#define il i * 2
#define ir i * 2 + 1

using ll = long long;

const int N = 1000005;

ll a[N], b[N], sa[N], sb[N], ca[N], cb[N];
vector<int> pos[N];
ll val[N * 4], tag[N * 4], res;
int lo, hi, n, m;

void apply(int i, ll v) {
    val[i] += v; tag[i] += v;
}

void push(int i) {
    apply(il, tag[i]);
    apply(ir, tag[i]);
    tag[i] = 0;
}

void add(int i, int l, int r, ll v) {
    if (l >= lo && r <= hi)
        return apply(i, v);
    int m = (l + r) / 2; push(i);
    if (m >= lo) add(il, l, m, v);
    if (m < hi) add(ir, m + 1, r, v);
    val[i] = max(val[il], val[ir]);
}

void assign(int i, int l, int r, ll v) {
    if (l == r) {
        val[i] = v; return;
    }
    int m = (l + r) / 2; push(i);
    if (m >= lo) assign(il, l, m, v);
    else assign(ir, m + 1, r, v);
    val[i] = max(val[il], val[ir]);
}

void get(int i, int l, int r) {
    if (l >= lo && r <= hi) {
        res = max(res, val[i]); return;
    }
    int m = (l + r) / 2; push(i);
    if (m >= lo) get(il, l, m);
    if (m < hi) get(ir, m + 1, r);
}

void add(int l, int r, ll v) {
    lo = l; hi = r; add(1, 0, m, v);
}

void assign(int p, ll v) {
    lo = p; assign(1, 0, m, v);
}

ll get(int l, int r) {
    lo = l; hi = r; res = 0;
    get(1, 0, m); return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> sa[i] >> ca[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i] >> sb[i] >> cb[i];
        b[i] += b[i - 1];
    }
    for (int i = 1, j = 0; i <= m; i++) {
        while (j < n && b[i] + a[j + 1] <= sb[i]) j++;
        if (b[i] + a[j] <= sb[i])
            pos[j].push_back(i);
    }
    memset(val, 0xc0, sizeof val);
    assign(0, 0);
    for (int i = 0, j = 0; i <= n; i++) {
        while (j < m && a[i] + b[j + 1] <= sa[i]) j++;
        if (a[i] + b[j] <= sa[i]) {
            add(0, j, ca[i]);
            ll v = get(0, j); assign(j, v);
        }
        for (int k : pos[i]) {
            ll v = get(0, k); assign(k, v);
        }
        for (int k : pos[i]) add(k, m, cb[k]);
    }
    cout << val[1] << '\n';
}