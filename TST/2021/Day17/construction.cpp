#include <bits/stdc++.h>

using namespace std;

using ii = pair <int, int>;

struct segTree {
    vector <int> val; int n, lo, hi;
    
    void reset() {
        val.assign(n * 4, 0);
    }
    
    segTree(int n): n(n) {
        val.assign(n * 4, 0);
    }
    
    void pushDown(int i) {
        if (val[i] >= 0) {
            val[i * 2] = val[i * 2 + 1] = val[i];
            val[i] = -1;
        }
    }
    
    void setVal(int i, int l, int r, int v) {
        assert(l <= r);
        if (l >= lo && r <= hi)
            return void(val[i] = v);
        pushDown(i); int m = (l + r) / 2;
        if (m >= lo) setVal(i * 2, l, m, v);
        if (m < hi) setVal(i * 2 + 1, m + 1, r, v);
    }
    
    int getVal(int i, int l, int r, int p) {
        assert(l <= r);
        if (val[i] >= 0) return val[i];
        pushDown(i); int m = (l + r) / 2;
        if (m >= p) return getVal(i * 2, l, m, p);
        return getVal(i * 2 + 1, m + 1, r, p);
    }
    
    void setVal(int l, int r, int v) {
        lo = l; hi = r; setVal(1, 1, n, v);
    }
    
    int getVal(int p) {
        return getVal(1, 1, n, p);
    }
};

using ll = long long;

struct point {
    int x, y, id;
};

struct rect {
    int l, b, r, t;
};

struct edge {
    int u, v, w;
};

const int N = 200005;

point A[N]; rect B[N];
map <ii, int> idx;
vector <edge> Edge;
vector <int> MST;
vector <ll> Sum;
int Par[N];

int Find(int u) {
    return Par[u] < 0 ? u : Par[u] = Find(Par[u]);
}

bool Unite(int u, int v) {
    u = Find(u); v = Find(v);
    return u != v ? Par[v] = u, true : false;
}

void compress(vector <int> &cmp) {
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(),
    cmp.end()), cmp.end());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    vector <int> cmpx, cmpy;
    segTree ST(n + 2 * m);
    for (int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
        A[i].x++; A[i].y++;
        cmpx.push_back(A[i].x);
        cmpy.push_back(A[i].y);
        A[i].id = i;
        idx[ii(A[i].x, A[i].y)] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i].l >> B[i].b;
        cin >> B[i].r >> B[i].t;
        B[i].l++; B[i].b++;
        B[i].r++; B[i].t++;
        cmpx.push_back(B[i].l);
        cmpx.push_back(B[i].r);
        cmpy.push_back(B[i].b);
        cmpy.push_back(B[i].t);
    }
    compress(cmpx); compress(cmpy);
    sort(A, A + n, [](point p, point q) {
        return p.x < q.x;
    });
    sort(B, B + m, [](rect p, rect q) {
        return p.r < q.r;
    });
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && B[j].r <= A[i].x) {
            int l = upper_bound(cmpy.begin(),
            cmpy.end(), B[j].b) - cmpy.begin();
            int r = upper_bound(cmpy.begin(),
            cmpy.end(), B[j].t) - cmpy.begin();
            ST.setVal(l, r, B[j].r); j++;
        }
        int p = upper_bound(cmpy.begin(),
        cmpy.end(), A[i].y) - cmpy.begin();
        int x = ST.getVal(p);
        if (idx.count(ii(x, A[i].y)))
            Edge.push_back({idx[ii(x, A[i].y)],
            A[i].id, A[i].x - x});
        ST.setVal(p, p, A[i].x);
    }
    ST.reset();
    sort(A, A + n, [](point p, point q) {
        return p.y < q.y;
    });
    sort(B, B + m, [](rect p, rect q) {
        return p.t < q.t;
    });
    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && B[j].t <= A[i].y) {
            int l = upper_bound(cmpx.begin(),
            cmpx.end(), B[j].l) - cmpx.begin();
            int r = upper_bound(cmpx.begin(),
            cmpx.end(), B[j].r) - cmpx.begin();
            ST.setVal(l, r, B[j].t); j++;
        }
        int p = upper_bound(cmpx.begin(),
        cmpx.end(), A[i].x) - cmpx.begin();
        int y = ST.getVal(p);
        if (idx.count(ii(A[i].x, y)))
            Edge.push_back({idx[ii(A[i].x, y)],
            A[i].id, A[i].y - y});
        ST.setVal(p, p, A[i].y);
    }
    int cmp = n;
    sort(Edge.begin(), Edge.end(),
    [](edge p, edge q) {
        return p.w < q.w;
    });
    memset(Par, -1, sizeof Par);
    for (auto e : Edge)
        if (Unite(e.u, e.v)) {
            MST.push_back(e.w); cmp--;
        }
    int len = MST.size();
    reverse(MST.begin(), MST.end());
    Sum.resize(len + 1);
    for (int i = 0; i < MST.size(); i++)
        Sum[i + 1] = Sum[i] + MST[i];
    while (q--) {
        int cost, lim;
        cin >> cost >> lim;
        if (lim < cmp) {
            cout << "-1\n"; continue;
        }
        ll res = Sum.back() + ll(cost) * cmp;
        int lo = 0, p = -1;
        int hi = min(lim - cmp, len) - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (MST[mi] >= cost) {
                p = mi; lo = mi + 1;
            }
            else hi = mi - 1;
        }
        res -= Sum[p + 1] - ll(cost) * (p + 1);
        cout << res << '\n';
    }
}