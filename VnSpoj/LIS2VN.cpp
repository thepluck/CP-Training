#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

struct item {
    int x, y, id;

    item() {}

    item(int x, int y, int id):
    x(x), y(y), id(id) {}

    bool operator < (const item &o) const {
        return x < o.x;
    }
};

const int N = 100005;

int x[N], y[N], sz;
int dp[N], BIT[N];
item seg[N], que[N];

void update(int i, int v) {
    for (; i <= sz; i += i & -i)
        cmax(BIT[i], v);
}

int query(int i) {
    int v = 0;
    for (; i > 0; i -= i & -i)
        cmax(v, BIT[i]);
    return v;
}

void solve(int l, int r) {
    if (l + 1 == r) {
        dp[l] += 1; return;
    }
    int m = (l + r) / 2;
    solve(l, m);
    vector <int> cmp;
    for (int i = l; i < r; i++)
        cmp.push_back(y[i]);
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(),
    cmp.end()), cmp.end());
    for (int i = l; i < m; i++)
        seg[i] = {x[i], y[i], i};
    for (int i = m; i < r; i++)
        que[i] = {x[i], y[i], i};
    sort(seg + l, seg + m);
    sort(que + m, que + r);
    sz = cmp.size();
    fill_n(BIT + 1, sz, 0);
    for (int i = m, j = l; i < r; i++) {
        while (j < m && seg[j] < que[i]) {
            int y = upper_bound(cmp.begin(),
            cmp.end(), seg[j].y) - cmp.begin();
            update(y, dp[seg[j++].id]);
        }
        int y = lower_bound(cmp.begin(),
        cmp.end(), que[i].y) - cmp.begin();
        cmax(dp[que[i].id], query(y));
    }
    solve(m, r);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    solve(0, n);
    cout << *max_element(dp, dp + n);
}