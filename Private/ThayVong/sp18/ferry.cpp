#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

struct edge{
    int v; ll w;

    edge(){}

    edge(int v, ll w): v(v), w(w){}

    bool operator <
    (const edge &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 5;
priority_queue <int> wei[N];
priority_queue <edge> pq;
vector <int> adj[N];
ll dis[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[v].eb(u);
        wei[u].emplace(w);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[n] = 0; pq.emplace(n, 0);
    while (!pq.empty()){
        int u = pq.top().v;
        ll w = pq.top().w; pq.pop();
        if (w > dis[u]) continue;
        for (int v : adj[u]){
            ll nw = w + wei[v].top();
            wei[v].pop();
            if (nw < dis[v]){
                dis[v] = nw;
                pq.emplace(v, nw);
            }
        }
    }
    cout << dis[1] << '\n';
}