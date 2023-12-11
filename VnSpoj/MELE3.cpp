#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
const int N = 1e3 + 5;
priority_queue <ii, vector <ii>, greater <ii>> pq;
vector <int> adj[N];
int dis[N];

int dijkstra(int s, int t){
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0; pq.push({0, s}); int u, dist;
    while (!pq.empty()){
        tie(dist, u) = pq.top(); pq.pop();
        if (dis[u] < dist) continue;
        if (u == t) return 5ll * dist;
        for (int v : adj[u]){
            int wait = abs(u - v), cycle = 2 * abs(u - v);
            if (u < v && dis[u] % cycle != 0)
                wait += cycle - (dis[u] % cycle);
            if (u > v && (dis[u] + wait) % cycle != 0)
                wait += cycle - (dis[u] + wait) % cycle;
            if (dis[v] > dis[u] + wait){
                dis[v] = dis[u] + wait; pq.push({dis[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, u, v; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dijkstra(1, n) << '\n';
}