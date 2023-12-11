#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, w, t;
};

const int N = 2e5 + 5;
const int M = 5e5 + 5;

int n, m, k, l, Par[N];
edge Edge[M]; bool Spec[N];

int Find(int u) {
    return Par[u] < 0 ? u : Par[u] = Find(Par[u]);
}

bool Unite(int u, int v) {
    u = Find(u); v = Find(v);
    return u != v ? Par[v] = u, true : false;
}

long long calc(int x, int &Min, int &Max) {
    Min = 0, Max = 0;
    long long res = 0;
    sort(Edge, Edge + m,
    [&](const edge &p, const edge &q) {
        int pw = x * p.t + p.w;
        int qw = x * q.t + q.w;
        return pw != qw ? pw < qw : p.t < q.t;
    });
    memset(Par, -1, sizeof Par);
    for (int i = 0; i < m; i++)
        if (Unite(Edge[i].u, Edge[i].v)) {
            Min += Edge[i].t;
            res += x * Edge[i].t + Edge[i].w;
        }
    sort(Edge, Edge + m,
    [&](const edge &p, const edge &q) {
        int pw = x * p.t + p.w;
        int qw = x * q.t + q.w;
        return pw != qw ? pw < qw : p.t > q.t;
    });
    memset(Par, -1, sizeof Par);
    for (int i = 0; i < m; i++)
        if (Unite(Edge[i].u, Edge[i].v))
            Max += Edge[i].t;
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> l;
    for (int i = 0; i < k; i++) {
        int u; cin >> u; Spec[u] = 1;
    }
    memset(Par, -1, sizeof Par);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        Edge[i] = {u, v, w, Spec[u] ^ Spec[v]};
        Unite(u, v);
    }
    for (int u = 2; u <= n; u++)
        if (Find(u) != Find(1)) {
            cout << -1; return 0;
        }
    int lo = -1e5, hi = 1e5;
    while (lo <= hi) {
        int mi = (lo + hi) / 2, Min, Max;
        long long res = calc(mi, Min, Max);
        if (l < Min) lo = mi + 1;
        else if (l > Max) hi = mi - 1;
        else {
            cout << res - 1ll * l * mi;
            return 0;
        }
    }
    cout << -1;
}