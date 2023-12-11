#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

struct edge{
    int v, id; ll w;

    edge(int v, int id, ll w):
    v(v), id(id), w(w){}

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 5;
ll dis[N], del;
vector <edge> adj[N];
priority_queue <edge> pq;

ll dijkstra(int s, int t){
    dis[s] = 0; pq.emplace(s, 0, 0);
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (cur.v == t) return cur.w;
        if (dis[cur.v] < cur.w) continue;
        for (edge nxt : adj[cur.v]){
            ll cost = cur.w + nxt.w;
            if (nxt.v != t) cost += del * nxt.id;
            if (cur.v != s) cost += nxt.id;
            if (cost < dis[nxt.v]){
                dis[nxt.v] = cost;
                pq.emplace(nxt.v, 0, cost);
            }
        }
    }
    return -1;
}

int main(){
    freopen("metro.inp", "r", stdin);
    freopen("metro.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t >> del;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].eb(v, i, w);
    }
    cout << dijkstra(s, t) << '\n';
}