#include <bits/stdc++.h>

using namespace std;

struct project {
    int t, l, r, c;
};

struct path {
    int x; long long d;

    path(int x, long long d): x(x), d(d) {}

    bool operator < (const path &o) const {
        return d > o.d;
    }
};

const int N = 100005;

vector <int> tr1[N * 4], tr2[N * 4];
project prj[N]; long long dis[N];
priority_queue <path> pq;

bool cmp1(int x, int y) {
    return prj[x].r + prj[x].t >= prj[y].l + prj[y].t;
};

bool cmp2(int x, int y) {
    return prj[x].r - prj[x].t >= prj[y].l - prj[y].t;
};

void build(int i, int l, int r) {
    if (l == r) {
        tr1[i] = tr2[i] = {l}; return;
    }
    int m = (l + r) / 2;
    build(i * 2, l, m); build(i * 2 + 1, m + 1, r);
    merge(tr1[i * 2].begin(), tr1[i * 2].end(),
    tr1[i * 2 + 1].begin(), tr1[i * 2 + 1].end(),
    back_inserter(tr1[i]), [&](int x, int y) {
        return prj[x].l + prj[x].t >= prj[y].l + prj[y].t;
    });
    merge(tr2[i * 2].begin(), tr2[i * 2].end(),
    tr2[i * 2 + 1].begin(), tr2[i * 2 + 1].end(),
    back_inserter(tr2[i]), [&](int x, int y) {
        return prj[x].l - prj[x].t >= prj[y].l - prj[y].t;
    });
}

void trav1(int i, int l, int r, int lim, int x) {
    if (r < lim) return;
    if (l >= lim) {
        while (tr1[i].size()) {
            int y = tr1[i].back();
            if (cmp1(x, y)) {
                if (dis[y] < 0) {
                    dis[y] = dis[x] + prj[y].c;
                    pq.emplace(y, dis[y]);
                }
                tr1[i].pop_back();
            }
            else break;
        }
        return;
    }
    int m = (l + r) / 2;
    trav1(i * 2, l, m, lim, x);
    trav1(i * 2 + 1, m + 1, r, lim, x);
}

void trav2(int i, int l, int r, int lim, int x) {
    if (l > lim) return;
    if (r <= lim) {
        while (tr2[i].size()) {
            int y = tr2[i].back();
            if (cmp2(x, y)) {
                if (dis[y] < 0) {
                    dis[y] = dis[x] + prj[y].c;
                    pq.emplace(y, dis[y]);
                }
                tr2[i].pop_back();
            }
            else break;
        }
        return;
    }
    int m = (l + r) / 2;
    trav2(i * 2, l, m, lim, x);
    trav2(i * 2 + 1, m + 1, r, lim, x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> prj[i].t >> prj[i].l >> prj[i].r >> prj[i].c;
    sort(prj + 1, prj + n + 1, [](project a, project b) {
        return a.t < b.t;
    });
    memset(dis, -1, sizeof dis); build(1, 1, n);
    for (int i = 1; i <= n; i++)
        if (--prj[i].l == 0)
            pq.emplace(i, dis[i] = prj[i].c);
    while (pq.size()) {
        path t = pq.top(); pq.pop();
        if (prj[t.x].r == m) {
            cout << t.d << '\n'; return 0;
        }
        int lim = lower_bound(prj + 1, prj + n + 1, prj[t.x],
        [](project a, project b) {return a.t < b.t;}) - prj;
        trav1(1, 1, n, lim, t.x);
        lim = upper_bound(prj + 1, prj + n + 1, prj[t.x],
        [](project a, project b) {return a.t < b.t;}) - prj;
        trav2(1, 1, n, lim - 1, t.x);
    }
    cout << "-1\n";
}