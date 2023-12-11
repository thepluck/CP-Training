#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct event {
    int x, v, t;
};

const int N = 2e5 + 5;
const int V = 10005;

event a[N * 2]; int sum[V], cnt[V];

void update(int i, int v, int t) {
    for (; i < V; i += i & -i) {
        sum[i] += v * t; cnt[i] += t;
    }
}

int get_pos(int k) {
    int p = 0, s = 0;
    for (int r = 1 << 13; r; r >>= 1)
        if (p + r < V && cnt[p + r] < k) {
            k -= cnt[p += r]; s += sum[p];
        }
    s += (p + 1) * k;
    return s;
}

int main() {
    freopen("smithy.inp", "r", stdin);
    freopen("smithy.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t;
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        a[i] = {l, v, 1};
        a[i + n] = {r + 1, v, -1};
    }
    sort(a + 1, a + 2 * n + 1,
    [](event p, event q) {
        return p.x < q.x ||
        (p.x == q.x && p.t < q.t);
    });
    int cur = 0; ll num = 0, res = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int len = a[i].x - a[i - 1].x;
        num += ll(min(cur, m)) * len;
        res += ll(get_pos(min(cur, m))) * len;
        cur += a[i].t;
        update(a[i].v, a[i].v, a[i].t);
    }
    cout << num << ' ' << res << '\n';
}