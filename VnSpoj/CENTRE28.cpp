#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, w;
    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 3e4 + 5;
int dis1[N], cnt1[N], dis2[N], cnt2[N];
vector <edge> adj[N];

void dijkstra(int s, int t){
    priority_queue <edge> pq;
    memset(dis1, 0x3f, sizeof dis1);
    memset(dis2, 0x3f, sizeof dis2);
    dis1[s] = 0; dis2[t] = 0;
    cnt1[s] = 1; cnt2[t] = 1;
    pq.push({s, 0});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w > dis1[cur.u]) continue;
        for (auto nxt : adj[cur.u])
            if (dis1[nxt.u] > dis1[cur.u] + nxt.w){
                dis1[nxt.u] = dis1[cur.u] + nxt.w;
                pq.push({nxt.u, dis1[nxt.u]});
                cnt1[nxt.u] = cnt1[cur.u];
            }
            else if (dis1[nxt.u] == dis1[cur.u] + nxt.w)
                cnt1[nxt.u] += cnt1[cur.u];
    }
    priority_queue <edge>().swap(pq); pq.push({t, 0});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w > dis2[cur.u]) continue;
        for (auto nxt : adj[cur.u])
            if (dis2[nxt.u] > dis2[cur.u] + nxt.w){
                dis2[nxt.u] = dis2[cur.u] + nxt.w;
                pq.push({nxt.u, dis2[nxt.u]});
                cnt2[nxt.u] = cnt2[cur.u];
            }
            else if (dis2[nxt.u] == dis2[cur.u] + nxt.w)
                cnt2[nxt.u] += cnt2[cur.u];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, u, v, w; cin >> n >> m;
    while (m--){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra(1, n); vector <int> ans;
    for (int i = 2; i < n; i++)
        if (dis1[i] + dis2[i] > dis1[n] || 1ll * cnt1[i] * cnt2[i] < cnt1[n])
            ans.push_back(i);
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << '\n';
}