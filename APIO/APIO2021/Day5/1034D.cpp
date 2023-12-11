#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ll = long long;
using ii = pair <int, int>;

struct segment {
    int l, r, idx;

    segment(int l, int r, int idx):
    l(l), r(r), idx(idx) {}

    bool operator < (const segment &o) const {
        return l < o.l || (l == o.l && r < o.r);
    }
};

const int MAXN = 300005;

set <segment> seg; int N, K;
vector <ii> event[MAXN];
int add[MAXN];

void calc(int len, ll &cnt, ll &sum) {
    cnt = sum = 0;
    int cur = 0; ll pre = 0;
    memset(add, 0, sizeof add);
    for (int i = 0, j = -1; i < N; i++) {
        for (auto e : event[i]) {
            add[max(e.fi, j + 1)] += e.se;
            add[i + 1] -= e.se;
            if (e.fi <= j)
                pre += ll(j - e.fi + 1) * e.se;
        }
        while (j + 1 < N && cur + add[j + 1] >= len) {
            cur += add[++j]; pre += cur;
        }
        cnt += j + 1; sum += pre;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    seg.emplace(0, 0, 0);
    seg.emplace(2e9, 2e9, 0);
    for (int i = 0; i < N; i++) {
        int l, r; cin >> l >> r;
        vector <segment> ins(1, {l, r, i});
        auto it = seg.lower_bound({l, l, 0});
        if (prev(it)->r > l) it = prev(it);
        while (it->l < r) {
            if (l > it->l)
                ins.emplace_back(it->l, l, it->idx);
            if (r < it->r)
                ins.emplace_back(r, it->r, it->idx);
            event[i].emplace_back(it->idx,
            min(r, it->r) - max(l, it->l));
            it = seg.erase(it);
        }
        for (auto s : ins) seg.insert(s);
    }
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        ll cnt, sum; calc(mi, cnt, sum);
        if (cnt >= K) lo = mi; else hi = mi - 1;
    }
    ll cnt, sum; calc(lo, cnt, sum);
    cout << sum - (cnt - K) * lo << '\n';
}
