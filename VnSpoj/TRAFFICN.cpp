#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, w; bool type;
    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 1e4 + 5;
int dis[N][2];
vector <edge> adj[N];
priority_queue <edge> pq;

int dijkstra(int s, int t){
    priority_queue <edge> ().swap(pq);
    memset(dis, 0x3f, 4 * N * 2); 
    dis[s][0] = 0; pq.push({s, 0, 0});
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (dis[cur.u][cur.type] < cur.w) continue;
        if (cur.u == t) return cur.w;
        for (edge e : adj[cur.u]){
            if (cur.type && !e.type && dis[e.u][1] > dis[cur.u][1] + e.w){
                dis[e.u][1] = dis[cur.u][1] + e.w;
                pq.push({e.u, dis[e.u][1], 1});
            }
            if (!cur.type && dis[e.u][e.type] > dis[cur.u][0] + e.w){
                dis[e.u][e.type] = dis[cur.u][0] + e.w;
                pq.push({e.u, dis[e.u][e.type], e.type});
            }
        }
    }
    return -1;
}

void solve(){
    int n, m, k, s, t, u, v, w;
    cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= n; i++) adj[i].clear();
    while (m--){
        cin >> u >> v >> w;
        adj[u].push_back({v, w, 0});
    }
    while (k--){
        cin >> u >> v >> w;
        adj[u].push_back({v, w, 1});
        adj[v].push_back({u, w, 1});
    }
    cout << dijkstra(s, t) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}