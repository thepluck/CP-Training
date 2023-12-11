#include <bits/stdc++.h>
using namespace std;

struct rectangle {
    int tx, ty, bx, by;
};

struct point {
    int x, y;

    bool operator < (const point &o) const {
        return x != o.x ? x < o.x : y < o.y;
    }

    bool operator == (const point &o) const {
        return x == o.x && y == o.y;
    }
};

struct edge {
    int v, w;

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 105;
const int V = 10005;

rectangle rec[N]; int d[V];
vector <int> adj[N]; bool vis[N];
vector <point> pt; point st, en;
priority_queue <edge> pq;
vector <edge> g[V * 10];

bool intersect(rectangle a, rectangle b) {
    return a.bx > b.tx && b.bx > a.tx
    && a.by > b.ty && b.by > a.ty;
}

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs(v);
}

void dijkstra(int s) {
    memset(d, 0x3f, sizeof d);
    pq.push({s, d[s] = 0});
    while (pq.size()) {
        edge t = pq.top(); pq.pop();
        if (d[t.v] < t.w) continue;
        for (edge e : g[t.v])
            if (d[e.v] > t.w + e.w) {
                d[e.v] = t.w + e.w;
                pq.push({e.v, d[e.v]});
            }
    }
}

int main() {
    //freopen("fence.in", "r", stdin);
    //freopen("fence.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    set <int> sx, sy;
    for (int i = 0; i < n; i++) {
        int tx, ty, bx, by;
        cin >> tx >> ty >> bx >> by;
        rec[i] = {tx, ty, bx, by};
        sx.insert(tx); sy.insert(ty);
        sx.insert(bx); sy.insert(by);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (intersect(rec[i], rec[j]))
                adj[i].push_back(j);
    dfs(0); st = {V, V};
    for (int i = 0; i < n; i++)
        if (vis[i]) st = min(st,
        {rec[i].tx, rec[i].ty});
    for (int x : sx)
        for (int y : sy)
            pt.push_back({x, y});
    en = {st.x, st.y + 1};
    pt.push_back(en); sort(pt.begin(), pt.end());
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    for (int i = 0; i < int(pt.size()); i++)
        for (int j = i + 1; j < int(pt.size()); j++) {
            if (pt[i].x != pt[j].x
            && pt[i].y != pt[j].y) continue;
            if (min(pt[i].x, pt[j].x) < st.x) continue;
            if (pt[i].x == st.x && pt[j].x == st.x
            && ((pt[i].y >= st.y) ^ (pt[j].y >= st.y))) continue;
            if (pt[i].x == st.x && pt[j].x == st.x
            && ((pt[i].y >= en.y) ^ (pt[j].y >= en.y))) continue;
            rectangle cur = {pt[i].x, pt[i].y,
            pt[j].x, pt[j].y};
            bool flag = 0;
            for (int k = 0; k < n; k++)
                if (intersect(cur, rec[k])) {
                    flag = 1; break;
                }
            if (!flag) {
                g[i].push_back({j, pt[j].x
                - pt[i].x + pt[j].y - pt[i].y});
                g[j].push_back({i, pt[j].x
                - pt[i].x + pt[j].y - pt[i].y});
            }
        }
    int s, t;
    for (int i = 0; i < int(pt.size()); i++) {
        if (pt[i] == st) s = i;
        if (pt[i] == en) t = i;
    }
    dijkstra(s); cout << d[t] + 1 << '\n';
}