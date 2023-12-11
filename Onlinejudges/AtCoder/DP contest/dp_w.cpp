
// Problem : W - Intervals
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_w
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back

using ll = long long;
using ii = pair <int, int>;

const int N = 200005;
const ll ninf = -1e18;

ll tr[N * 4], tg[N * 4];
int lo, hi, n, m;
vector <ii> a[N];

void push_tag(int i, ll v) {
    tr[i] += v; tg[i] += v;
}

void push_down(int i) {
    push_tag(i * 2, tg[i]);
    push_tag(i * 2 + 1, tg[i]);
    tg[i] = 0;
}

void push_up(int i) {
    tr[i] = max(tr[i * 2], tr[i * 2 + 1]);
}

void update(int i, int l, int r, ll v) {
    if (l > hi || r < lo) return;
    if (l >= lo && r <= hi)
        return push_tag(i, v);
    push_down(i);
    int m = (l + r) / 2;
    update(i * 2, l, m, v);
    update(i * 2 + 1, m + 1, r, v);
    push_up(i);
}

ll query(int i, int l, int r) {
    if (l > hi || r < lo) return ninf;
    if (l >= lo && r <= hi) return tr[i];
    push_down(i);
    int m = (l + r) / 2;
    return max(query(i * 2, l, m),
    query(i * 2 + 1, m + 1, r));
}

void update(int l, int r, ll v) {
    lo = l; hi = r;
    update(1, 0, n, v);
}

ll query(int l, int r) {
    lo = l; hi = r;
    return query(1, 0, n);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m; ll sum = 0;
    for (int i = 0; i < m; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        a[r].eb(l, v); sum += v;
    }
    update(0, n, sum);
    for (int i = 1; i <= n; i++) {
        update(i, i, query(0, i - 1) - sum);
        for (auto q : a[i])
            update(0, q.fi - 1, -q.se);
    }
    cout << tr[1] << '\n';
}