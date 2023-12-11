#include <bits/stdc++.h>
using namespace std;
 
using ll = unsigned long long;
 
struct edge{
    int u, w;
};
 
struct path{
    int u; ll w; int k;
    bool operator < (const path &o) const {
        return w > o.w;
    }
};
 
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 5;
const int K = 7; ll dis[N][K];
vector <edge> adj[N];
priority_queue <path> pq;
 
ll dijkstra(int n, int k, int s, int t){
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dis[i][j] = inf;
    dis[s][0] = 0; pq.push({s, 0, 0});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w > dis[cur.u][cur.k])
            continue;
        if (cur.u == t) return cur.w;
        for (auto e : adj[cur.u]){
            if (dis[e.u][cur.k] > dis[cur.u][cur.k] + e.w){
                dis[e.u][cur.k] = dis[cur.u][cur.k] + e.w;
                pq.push({e.u, dis[e.u][cur.k], cur.k});
            }
            if (cur.k < k && dis[e.u][cur.k + 1] > dis[cur.u][cur.k]){
                dis[e.u][cur.k + 1] = dis[cur.u][cur.k];
                pq.push({e.u, dis[e.u][cur.k + 1], cur.k + 1});
            }
        }
    }
    return -1;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k, s, t, u, v, w;
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << dijkstra(n, k, s, t) << '\n';
} 