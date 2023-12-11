#include <bits/stdc++.h>

using namespace std;

#define int long long

using ll = long long;

struct edge {
    int v, a, b;

    edge(int v, int a, int b): v(v), a(a), b(b) {}
};

struct point {
    ll x, y;

    point(ll x, ll y): x(x), y(y) {}

    point& operator += (const point &o) {
        x += o.x; y += o.y; return *this;
    }

    point& operator -= (const point &o) {
        x -= o.x; y -= o.y; return *this;
    }

    point operator + (const point &o) const {
        return point(*this) += o;
    }

    point operator - (const point &o) const {
        return point(*this) -= o;
    }

    bool operator < (const point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
};

ll dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

ll cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

bool polarComp(const point &a, const point &b) {
    return cross(a, b) > 0;
}

bool ccw(const point &a, const point &b, const point &c) {
    return cross(b - a, c - b) > 0;
}

const int N = 100005;

vector <edge> adj[N], path;
bool vis[N], pen[N], mark[N];
vector <vector <point>> poly;
int par[N];

void DFS(int u) {
    vis[u] = pen[u] = true;
    for (edge e : adj[u]) {
        if (e.v != par[u] && pen[e.v]) {
            ll sumA = e.a, sumB = e.b;
            for (int i = path.size() - 1; i >= 0 && path[i].v != e.v; i--) {
                mark[path[i].v] = true;
                sumA += path[i].a; sumB += path[i].b;
            }
            poly.emplace_back(vector <point> (1, {sumA - e.a, sumB - e.b}));
            for (int i = path.size() - 1; i >= 0 && path[i].v != e.v; i--)
                poly.back().emplace_back(sumA - path[i].a, sumB - path[i].b);
        }
        if (!vis[e.v]) {
            path.push_back(e);
            par[e.v] = u; DFS(e.v);
            path.pop_back();
        }
    }
    pen[u] = false;
}

void convexHull(vector <point> &poly) {
    sort(poly.begin(), poly.end());
    vector <point> hull; int k = 0;
    for (point p : poly) {
        while (k > 1 && !ccw(hull[k - 2], hull[k - 1], p)) {
            k--; hull.pop_back();
        }
        hull.push_back(p); k++;
    }
    poly.clear();
    poly.push_back(hull.front());
    for (int i = 0; i + 1 < hull.size(); i++)
        poly.push_back(hull[i + 1] - hull[i]);
}

vector <point> minkowskiSum(const vector <point> &a, const vector <point> &b) {
    vector <point> sum(1, a[0] + b[0]);
    merge(a.begin() + 1, a.end(), b.begin() + 1, b.end(), back_inserter(sum), polarComp);
    return sum;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    ll sumA = 0, sumB = 0;
    for (int i = 0; i < m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        adj[u].emplace_back(v, a, b);
        adj[v].emplace_back(u, a, b);
        sumA += a; sumB += b;
    }
    DFS(1);
    for (int u = 2; u <= n; u++)
        if (!mark[u]) {
            for (edge e : adj[u])
                if (e.v == par[u])
                    poly.push_back(vector <point> (1, {e.a, e.b}));
        }
    for (auto &p : poly) convexHull(p);
    while (poly.size() > 1) {
        vector <vector <point>> newPoly;
        for (int i = 0; i < poly.size(); i += 2)
            if (i + 1 < poly.size())
                newPoly.push_back(minkowskiSum(poly[i], poly[i + 1]));
            else newPoly.push_back(poly[i]);
        poly.swap(newPoly);
    }
    vector <point> sum = poly.back();
    point cur = sum[0];
    ll res = cur.x * cur.y;
    for (int i = 1; i < sum.size(); i++) {
        cur += sum[i]; res = min(res, cur.x * cur.y);
    }
    cout << res << '\n';
}
