#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

struct edge {
    int v; ll w;
    
    edge(int v, ll w): v(v), w(w) {}
    
    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

struct bro {
    int s, t; bool type = 1;
    
    bool operator < (const bro &o) const {
        return type > o.type;
    }
};

const int N = 1e5 + 5;

vector <edge> g[N];
priority_queue <edge> pq;
ll dis[N], tmp[2][N], dp[1 << 5][10][N];
bro br[10];

void dijkstra(int s, ll d[]) {
    pq.emplace(s, d[s] = 0);
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.v] < cur.w) continue;
        for (edge e : g[cur.v])
            if (cmin(d[e.v], cur.w + e.w))
                pq.emplace(e.v, d[e.v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].eb(v, w); g[v].eb(u, w);
    }
    cin >> br[0].s >> br[0].t;
    int st = 0;
    for (int i = 1; i < k; i++) {
        cin >> br[i].s >> br[i].t;
        cin >> br[i].type;
        st += !br[i].type;
    }
    sort(br, br + k);
    memset(dis, 0x3f, sizeof dis);
    dijkstra(br[st].s, dis);
}