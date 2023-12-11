#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

struct edge {
    int v; ll w;

    edge(int v, ll w): v(v), w(w) {}

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int K = 17;
const int N = 100000;
const ll inf = 1e14 + 5;

int cap[K], n, m, k;
priority_queue <edge> pq;
vector <edge> g[N]; ll d[K][N];
int dp[1 << K]; ll cnt[1 << K];

void dijkstra(int s, ll c[]) {
    for (int i = 0; i < n; i++)
        c[i] = s == i ? 0 : inf;
    pq.emplace(s, 0);
    while (pq.size()) {
        edge t = pq.top(); pq.pop();
        if (c[t.v] < t.w) continue;
        for (edge e : g[t.v])
            if (cmin(c[e.v], t.w + e.w))
                pq.emplace(e.v, c[e.v]);
    }
}

bool check(ll x) {
    for (int j = 0; j < (1 << k); j++)
        dp[j] = 0;
    for (int u = 0; u < n; u++) {
        int j = 0;
        for (int i = 0; i < k; i++)
            if (d[i][u] <= x)
                j |= 1 << i;
        dp[j]++;
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < (1 << k); j++)
            if (j >> i & 1)
                dp[j] += dp[j ^ (1 << i)];
    for (int j = 0; j < (1 << k); j++)
        if (cnt[j] < dp[j]) return 0;
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;        
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    for (int i = 0; i < k; i++) {
        int s, c; cin >> s >> c; s--;
        dijkstra(s, d[i]);
        for (int j = 0; j < (1 << k); j++)
            if (j >> i & 1) cnt[j] += c;
    }
    ll lo = 0, hi = inf;
    while (lo < hi) {
        ll mi = (lo + hi) / 2;
        if (check(mi)) hi = mi;
        else lo = mi + 1;
    }
    cout << hi << '\n';
}