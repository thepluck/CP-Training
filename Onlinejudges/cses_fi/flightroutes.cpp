#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

using ll = long long;

struct edge{
    int v; ll w;

    edge(){}

    edge(int v, ll w): v(v), w(w){}

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 5;
const int K = 15;
priority_queue <edge> pq;
vector <edge> adj[N];
vector <ll> dis[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    while (m--){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].eb(v, w);
    }
    pq.emplace(1, 0);
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (dis[cur.v].size() >= k) continue;
        dis[cur.v].eb(cur.w);
        for (edge e : adj[cur.v])
            pq.emplace(e.v, e.w + cur.w);
    }
    for (ll w : dis[n]) cout << w << '\n';
}