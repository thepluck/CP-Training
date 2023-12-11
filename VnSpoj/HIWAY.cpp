#include <bits/stdc++.h>
using namespace std;
 
template <class T, class cont, class cmp>
void clear(priority_queue <T, cont, cmp> &pq){
    priority_queue <T, cont, cmp>().swap(pq);
}
 
using ll = long long;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 50005;
ll dis[N]; int t1[N], t2[N];
vector <int> tt;
 
struct edge{
    int v; ll w;
    bool operator < (const edge &o) const {
        return w > o.w;
    }
};
 
priority_queue <edge> pq;
vector <edge> adj[N], res[N];
map <int, int> mp1, mp2;
int n, m, s, t, u, v, w;
 
void dfs(int cur){
    tt.push_back(cur);
    if (cur == t){
        cout << tt.size() << ' ';
        for (int x : tt) cout << x << ' ';
        cout << '\n';
    }
    for (auto e : adj[cur]) dfs(e.v);
    tt.pop_back();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
        adj[v].push_back({u, w});
        res[u].push_back({v, w});
        res[v].push_back({u, w});
    }
    fill_n(dis + 1, n, inf); dis[s] = 0;
    pq.push({s, 0ll});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w != dis[cur.v]) continue;
        for (auto e : adj[cur.v])
            if (dis[e.v] > dis[cur.v] + e.w){
                dis[e.v] = dis[cur.v] + e.w;
                pq.push({e.v, dis[e.v]});
                t1[e.v] = cur.v;
            }
    }
    if (dis[t] == inf) return cout << -1, 0;
    int temp = t; clear(pq);
    while (temp != s){
        mp1[temp] = t1[temp];
        mp2[t1[temp]] = temp;
        temp = t1[temp];
    }
    for (int i = 1; i <= n; i++)
        for (auto &e : adj[i]){
            e.w += dis[i] - dis[e.v];
            if (mp1[i] == e.v) e.w = 0ll;
            if (mp2[i] == e.v) e.w = inf;
        }
    fill_n(dis + 1, n, inf); dis[s] = 0;
    pq.push({s, 0ll});
    while (!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if (cur.w != dis[cur.v]) continue;
        for (auto e : adj[cur.v])
            if (dis[e.v] > dis[cur.v] + e.w){
                dis[e.v] = dis[cur.v] + e.w;
                pq.push({e.v, dis[e.v]});
                t2[e.v] = cur.v;
            }
    }
    if (dis[t] == inf) return cout << -1, 0;
    temp = t; mp2.clear(); mp1.clear();
    while (temp != s){
        mp2[temp] = t2[temp]; temp = t2[temp];
    }
    temp = t;
    while (temp != s){
        mp1[temp] = t1[temp]; temp = t1[temp];
    }
    for (auto qq : mp2){
        if (qq.second == 0) continue;
        tt.push_back(qq.first);
    }
    for (int x : tt)
        if (mp1[mp2[x]] == x){
            mp1.erase(mp2[x]); mp2.erase(x);
        }
    ll ans = 0;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++){
        for (auto e : res[i]){
            if (mp1[i] == e.v){
                ans += e.w; 
                adj[e.v].push_back({i, 0});
            }
            if (mp2[i] == e.v){
                ans += e.w; 
                adj[e.v].push_back({i, 0});
            }
        }
    }
    cout << ans << '\n'; tt.clear(); dfs(s);
}