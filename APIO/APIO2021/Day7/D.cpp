#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 1e18;
const int MAXN = 200005;

struct line {
    ll k, m, p;

    line(ll k = 0, ll m = 0, ll p = -INF):
    k(k), m(m), p(p) {}

    ll operator () (ll x) {
        return k * x + m;
    }
};

struct CHT {
    vector <line> hull; int N = 0;
    vector <tuple <int, int, line>> buck;

    ll floor(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    
    ll ceil(ll a, ll b) {
        if (b > 0)
            return floor(a + b - 1, b);
        return floor(-a - b - 1, -b);
    }

    bool isect(line x, line &y) {
        y.p = ceil(y.m - x.m, x.k - y.k);
        return x.p >= y.p;
    }

    void push(line l) {
        int lo = 0, hi = N;
        while (lo < hi) {
            int mi = (lo + hi) / 2;
            if (isect(hull[mi], l)) hi = mi;
            else lo = mi + 1;
        }
        if (hi == int(hull.size()))
            hull.emplace_back();
        buck.emplace_back(hi, N, hull[hi]);
        if (hi) isect(hull[hi - 1], l);
        hull[hi] = l; N = hi + 1;
    }

    void pop() {
        int i; line l;
        tie(i, N, l) = buck.back();
        buck.pop_back(); hull[i] = l;
    }

    ll get(ll x) {
        if (!N) return -INF;
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mi = (lo + hi + 1) / 2;
            if (hull[mi].p <= x) lo = mi;
            else hi = mi - 1;
        }
        return hull[lo](x);
    }
};

CHT BIT[MAXN]; int idx[MAXN];
vector <pair <int, int>> adj[MAXN];
ll P[MAXN], Q[MAXN], D[MAXN], L[MAXN];
vector <int> path; ll DP[MAXN];

void push(int i, line l) {
    for (; i > 0; i -= i & -i)
        BIT[i].push(l);
}

void pop(int i) {
    for (; i > 0; i -= i & -i)
        BIT[i].pop();
}

ll get(int i, ll x) {
    ll res = -INF;
    for (; i < MAXN; i += i & -i)
        res = max(res, BIT[i].get(x));
    return res;
}

void DFS1(int u) {
    for (auto e : adj[u]) {
        int v, w; tie(v, w) = e;
        D[v] = D[u] + w; DFS1(v);
    }
}

void DFS2(int u) {
    int lo = 0, hi = path.size() - 1;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (D[path[mi]] + L[u] >= D[u])
            hi = mi;
        else lo = mi + 1;
    }
    DP[u] = -get(idx[path[hi]], P[u]);
    DP[u] += P[u] * D[u] + Q[u];
    push(idx[u], {D[u], -DP[u], -INF});
    path.push_back(u);
    for (auto e : adj[u]) DFS2(e.first);
    path.pop_back(); pop(idx[u]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int u = 2; u <= N; u++) {
        int p, w; cin >> p >> w;
        cin >> P[u] >> Q[u] >> L[u];
        adj[p].emplace_back(u, w);
    }
    DFS1(1); vector <ll> rar;
    for (int i = 1; i <= N; i++)
        rar.push_back(D[i]);
    sort(rar.begin(), rar.end());
    rar.erase(unique(rar.begin(),
    rar.end()), rar.end());
    for (int i = 1; i <= N; i++)
        idx[i] = upper_bound(rar.begin(),
        rar.end(), D[i]) - rar.begin();
    push(idx[1], line());
    path.push_back(1);
    for (auto e : adj[1]) DFS2(e.first);
    for (int i = 2; i <= N; i++)
        cout << DP[i] << '\n';
}