#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct edge{
    int v; ll w;

    edge(int v, ll w): v(v), w(w){}

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 2e5 + 5;
priority_queue <edge> pq;
vector <edge> adj[N]; ll dis[N];

ll dijkstra(int s, int t){
    dis[s] = 0; pq.emplace(s, 0);
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (cur.v == t) return cur.w;
        if (dis[cur.v] < cur.w) continue;
        for (edge nxt : adj[cur.v])
            if (dis[nxt.v] > cur.w + nxt.w){
                dis[nxt.v] = cur.w + nxt.w;
                pq.emplace(nxt.v, dis[nxt.v]);
            }
    }
    return -1;
}

int main(){
    freopen("nicetour.inp", "r", stdin);
    freopen("nicetour.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= m; i++){
        int t, w, u, v;
        cin >> t >> w >> u;
        for (int i = 1; i < t; i++){
            cin >> v;
            adj[u].emplace_back(v, w);
        }
    }
    cout << dijkstra(1, n) << '\n';
}