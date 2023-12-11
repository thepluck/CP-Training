#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge {
    int u, v, a, b;
};

struct edget {
    int v, a, b;
};

struct path {
    int v, w;
    
    bool operator < (const path &o) const {
        return w > o.w;
    }
};

const int N = 2e5 + 5;

int dis[N]; edge ed[N];
priority_queue <path> pq;
vector <edget> g[N];

int main() {
    freopen("airplane.inp", "r", stdin);
    freopen("airplane.out", "w", stdout);
    int s, t, m, r, p;
    cin >> s >> t >> m >> r >> p;
    vector <int> cmp;
    for (int i = 0; i < m; i++) {
        cin >> ed[i].u >> ed[i].v;
        cin >> ed[i].a >> ed[i].b;
        cmp.push_back(ed[i].u);
        cmp.push_back(ed[i].v);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(),
    cmp.end()), cmp.end());
    int n = cmp.size();
    for (int i = 0; i < m; i++) {
        ed[i].u = distance(cmp.begin(), upper_bound
        (cmp.begin(), cmp.end(), ed[i].u));
        ed[i].v = distance(cmp.begin(), upper_bound
        (cmp.begin(), cmp.end(), ed[i].v));
        g[ed[i].u].push_back({ed[i].v, ed[i].a, ed[i].b});
        g[ed[i].v].push_back({ed[i].u, ed[i].a, ed[i].b});
    }
    s = distance(cmp.begin(), upper_bound
    (cmp.begin(), cmp.end(), s));
    t = distance(cmp.begin(), upper_bound
    (cmp.begin(), cmp.end(), t));
    memset(dis, 0x3f, sizeof dis);
    pq.push({s, dis[s] = r});
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (dis[cur.v] < cur.w) continue;
        for (auto e : g[cur.v])
            if (cur.w + p < e.a && dis[e.v] > e.b)
                pq.push({e.v, dis[e.v] = e.b});
    }
    cout << dis[t] << '\n';
}