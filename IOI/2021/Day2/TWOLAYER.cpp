#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

using ll = long long;

const ll INF = 1e18;

struct edge {
    int v, w1, w2;

    edge(int v, int w1, int w2):
    v(v), w1(w1), w2(w2) {}
};

struct path {
    int v; ll w;

    path(int v, ll w): v(v), w(w) {}

    bool operator < (const path &o) const {
        return w > o.w;
    }
};

const int MAXN = 100005;

vector <edge> adj[MAXN];
ll dis1[MAXN], disn[MAXN];
priority_queue <path> pq;
int N, M, C[MAXN]; ll disa[MAXN];

void Dijkstra1(int s, ll dis[]) {
    for (int i = 1; i <= N; i++)
        dis[i] = INF;
    pq.emplace(s, dis[s] = 0);
    while (pq.size()) {
        path p = pq.top(); pq.pop();
        if (dis[p.v] < p.w) continue;
        for (edge e : adj[p.v])
            if (cmin(dis[e.v], p.w + e.w1))
                pq.emplace(e.v, dis[e.v]);
    }
}

void Dijkstra2() {
    for (int i = 1; i <= N; i++)
        pq.emplace(i, disa[i] = C[i]);
    while (pq.size()) {
        path p = pq.top(); pq.pop();
        if (disa[p.v] < p.w) continue;
        for (edge e : adj[p.v])
            if (cmin(disa[e.v], p.w + e.w1 + e.w2))
                pq.emplace(e.v, disa[e.v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> C[i];
    int u, v, w1, w2;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w1 >> w2;
        adj[u].emplace_back(v, w1, w2);
        adj[v].emplace_back(u, w1, w2);
    }
    Dijkstra1(1, dis1);
    Dijkstra1(N, disn);
    Dijkstra2();
    ll res = INF;
    for (int i = 1; i <= N; i++)
        cmin(res, dis1[i] + disn[i] + disa[i]);
    cout << res << '\n';
}