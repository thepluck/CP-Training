#include <bits/stdc++.h>

using namespace std;

#define il i * 2
#define ir i * 2 + 1

using ll = long long;

const int N = 250005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct query {
    int a, c = -1, d = -1; ll b;
} que[N];

vector<pair<int, int>> event[N];
pair<ll, ll> seg[N * 4], res; ll cur[N];

void add(int i, int l, int r, int p, int v) {
    if (l == r) {
        seg[i].second += v;
        seg[i].first = max(seg[i].second, 0ll);
        return;
    }
    int m = (l + r) / 2;
    if (m >= p) add(il, l, m, p, v);
    else add(ir, m + 1, r, p, v);
    seg[i].first = max(seg[ir].first, 
    seg[il].first + seg[ir].second);
    seg[i].second = seg[il].second + seg[ir].second;
}

int find(int i, int l, int r, ll v) {
    if (l == r) return l;
    int m = (l + r) / 2;
    if (v <= seg[il].second)
        return find(il, l, m, v);
    return find(ir, m + 1, r, v - seg[il].second);
}

void get(int i, int l, int r, int p) {
    if (r <= p) {
        res.first = max(seg[i].first,
        res.first + seg[i].second);
        res.second += seg[i].second;
        return;
    }
    int m = (l + r) / 2;
    get(il, l, m, p);
    if (m < p) get(ir, m + 1, r, p);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 1, cmd; i <= q; i++) {
        cin >> cmd >> que[i].a >> que[i].b;
        if (cmd == 1) {
            cin >> que[i].c >> que[i].d;
            event[que[i].a].emplace_back(i, que[i].d);
            event[que[i].b + 1].emplace_back(i, -que[i].d);
        } else if (cmd == 2) {
            cin >> que[i].d;
            event[que[i].a].emplace_back(i, -que[i].d);
            event[que[i].b + 1].emplace_back(i, que[i].d);
        } else event[que[i].a].emplace_back(-i, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (auto e : event[i])
            if (e.first > 0) 
                add(1, 1, q, e.first, e.second);
        for (auto e : event[i])
            if (e.first < 0) {
                res.first = res.second = 0;
                get(1, 1, q, -e.first);
                cur[-e.first] = res.first;
            }
    }
    for (int i = 0; i < 4 * N; i++)
        seg[i].first = seg[i].second = 0;
    for (int i = 1; i <= n; i++) {
        for (auto e : event[i])
            if (e.first > 0 && que[e.first].c >= 0)
                add(1, 1, q, e.first, e.second);
        for (auto e : event[i])
            if (e.first < 0) {
                if (cur[-e.first] < que[-e.first].b) {
                    cur[-e.first] = 0; continue;
                }
                res.first = res.second = 0;
                get(1, 1, q, -e.first);
                cur[-e.first] -= res.second + que[-e.first].b;
                cur[-e.first] = que[find(1, 1, q, -cur[-e.first])].c;
            }
    }
    for (int i = 1; i <= q; i++)
        if (que[i].d < 0) cout << cur[i] << '\n';    
}