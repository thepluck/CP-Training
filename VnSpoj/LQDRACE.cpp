#include <bits/stdc++.h>
using namespace std;


struct edge{
    int v, w;
};

mt19937 rng(chrono::steady_clock::now().
time_since_epoch().count());

struct custom_hash{
    static int splitmix64(int x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    int operator()(int x) const {
        static const int FIXED_RANDOM = rng();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#define fi first
#define se second

const int N = 2e5 + 5;
int in[N], out[N], tour[N], tim;
int heavy[N], dep[N], ans, n;
unordered_map <int, int, custom_hash> mp;
int dis[N], k; vector <edge> adj[N];
 
void add_edge(int u, int v, int w){
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}
 
template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}
 
int dfs_tour(int v, int p){
    int v_sz = 1, maxc_sz = 0;
    in[v] = ++tim; tour[tim] = v;
    for (auto e : adj[v]){
        if (e.v == p) continue;
        dep[e.v] = dep[v] + 1;
        dis[e.v] = dis[v] + e.w;
        int c_sz = dfs_tour(e.v, v);
        v_sz += c_sz;
        if (c_sz > maxc_sz){
            maxc_sz = c_sz;
            heavy[v] = e.v;
        }
    }
    out[v] = tim; return v_sz;
}
 
void dfs_sol(int v, int p, bool cl){
    for (auto e : adj[v])
        if (e.v != p && e.v != heavy[v])
            dfs_sol(e.v, v, 1);
    if (heavy[v]) dfs_sol(heavy[v], v, 0);
    mp[dis[v]] = dep[v];
    for (auto e : adj[v])
        if (e.v != p && e.v != heavy[v]){
            for (int u = in[e.v]; u <= out[e.v]; u++){
                auto it = mp.find(dis[v] * 2 + k - dis[tour[u]]);
                if (it != mp.end()) 
                    ans = min(ans, it->se + dep[tour[u]] - 2 * dep[v]);
            }
            for (int u = in[e.v]; u <= out[e.v]; u++){
                if (mp.count(dis[tour[u]]))
                    chkmin(mp[dis[tour[u]]], dep[tour[u]]);
                else mp[dis[tour[u]]] = dep[tour[u]];   
            }
        }
    mp[dis[v]] = dep[v];
    auto it = mp.find(dis[v] + k);
    if (it != mp.end())
        ans = min(ans, it->se - dep[v]);
    if (cl) mp.clear();
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k; ans = n + 1;
    for (int i = 1, u, v, w; i < n; i++){
        cin >> u >> v >> w;
        u++; v++; add_edge(u, v, w);
    }
    dfs_tour(1, 0); dfs_sol(1, 0, 0);
    if (ans == n + 1) cout << "-1";
    else cout << ans;
}