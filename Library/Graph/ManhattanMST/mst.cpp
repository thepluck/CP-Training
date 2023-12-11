#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct point {
    int x, y;
};

const int N = 200005;

point pt[N];
int n, par[N];
pair<int, int> bit[N];

void update(int i, int v, int id) {
    auto val = make_pair(v, id);
    for (; i <= n; i += i & -i)
        bit[i] = max(bit[i], val);
}

pair<int, int> query(int i) {
    pair<int, int> res(INT_MIN, -1);
    for (; i > 0; i -= i & -i)
        res = max(res, bit[i]);
    return res;
}

int find(int u) {
    return u == par[u] ? u : par[u] = find(par[u]);
}

bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    par[v] = u; return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> pt[i].x >> pt[i].y;
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    vector<tuple<ll, int, int>> edges;
    for (int qt = 0; qt < 4; qt++) {
        sort(id.begin(), id.end(), [&](int i, int j) {
            return make_pair(pt[i].y - pt[i].x, pt[i].x) < make_pair(pt[j].y - pt[j].x, pt[j].x);
        });
        vector<int> cmp;
        for (int i = 1; i <= n; i++)
            bit[i] = {INT_MIN, -1};
        for (int i = 0; i < n; i++)
            cmp.push_back(pt[i].x);
        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
        for (int i : id) {
            int curx = upper_bound(cmp.begin(), cmp.end(), pt[i].x) - cmp.begin();
            auto tmp = query(curx);
            if (tmp.second >= 0)
                edges.emplace_back(ll(pt[i].x) + pt[i].y - tmp.first, i, tmp.second);
            update(curx, pt[i].x + pt[i].y, i);
        }
        sort(id.begin(), id.end(), [&](int i, int j) {
            return make_pair(pt[i].x - pt[i].y, pt[i].y) < make_pair(pt[j].x - pt[j].y, pt[j].y);
        });
        cmp.clear();
        for (int i = 1; i <= n; i++)
            bit[i] = {INT_MIN, -1};
        for (int i = 0; i < n; i++)
            cmp.push_back(pt[i].y);
        sort(cmp.begin(), cmp.end());
        cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
        for (int i : id) {
            int cury = upper_bound(cmp.begin(), cmp.end(), pt[i].y) - cmp.begin();
            auto tmp = query(cury);
            if (tmp.second >= 0)
                edges.emplace_back(ll(pt[i].x) + pt[i].y - tmp.first, i, tmp.second);
            update(cury, pt[i].x + pt[i].y, i);
        }
        for (int i = 0; i < n; i++) {
            swap(pt[i].x, pt[i].y);
            pt[i].y = -pt[i].y;
        }
    }
    sort(edges.begin(), edges.end());
    iota(par, par + n, 0);
    ll res = 0;
    vector<pair<int, int>> mst;
    for (auto edge : edges) {
        int u, v; ll w;
        tie(w, u, v) = edge;
        if (unite(u, v)) {
            mst.emplace_back(u, v);
            res += w;
        }
    }
    cout << res << '\n';
    for (auto edge : mst)
        cout << edge.first << ' ' << edge.second << '\n';
}