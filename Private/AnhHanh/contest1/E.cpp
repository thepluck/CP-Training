#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct path {
    int v; long long w;

    path(int v, long long w): v(v), w(w) {}

    bool operator < (const path &o) const {
        return w > o.w;
    }
};

const int N = 55;
const int C = 10005;

priority_queue <path> pq;
vector <path> adj[N];
long long dis[N][C * 2];
int n, m; long long req;

void Dijkstra(int mod) {
    memset(dis, 0x3f, sizeof dis);
    dis[1][0] = 0; pq.emplace(1, 0);
    while (pq.size()) {
        path t = pq.top(); pq.pop();
        if (dis[t.v][t.w % mod] < t.w) continue;
        for (path e : adj[t.v])
            if (cmin(dis[e.v][(t.w + e.w) % mod], t.w + e.w))
                pq.emplace(e.v, t.w + e.w);
    }
}

int main() {
    freopen("longtrip.inp", "r", stdin);
    freopen("longtrip.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> req;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    for (auto e : adj[1]) {
        Dijkstra(e.w * 2);
        if (dis[n][req % (e.w * 2)] <= req) {
            cout << "Possible\n"; return 0;
        }
        break;
    }
    cout << "Impossible\n";
}
