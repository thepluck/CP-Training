#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ii = pair <int, int>;
const int N = 5e5 + 5; char col[N];
int heavy[N], tour[N], in[N], out[N];
int tim, dep[N], cnt[N][30], state[N], ans[N];
vector <int> adj[N]; vector <ii> que[N];

void add_edge(int u, int v){
    adj[u].push_back(v); adj[v].push_back(u);
}

void add_cnt(int u){
    state[dep[u]] -= cnt[dep[u]][col[u] - 'a'];
    cnt[dep[u]][col[u] - 'a'] ^= 1;
    state[dep[u]] += cnt[dep[u]][col[u] - 'a']; 
}

int dfs_tour(int v, int p){
    int cur_sz = 1, maxc_sz = 0; 
    dep[v] = dep[p] + 1;
    in[v] = ++tim; tour[tim] = v;
    for (int c : adj[v]) if (c != p){
        int c_sz = dfs_tour(c, v); 
        cur_sz += c_sz; 
        if (maxc_sz < c_sz){
            heavy[v] = c; maxc_sz = c_sz;
        }
    }
    out[v] = tim; return cur_sz;
}

void dfs_sol(int v, int p, bool keep){
    for (int c : adj[v]) 
        if (c != p && c != heavy[v])
            dfs_sol(c, v, false);
    if (heavy[v]) dfs_sol(heavy[v], v, true);
    for (int c : adj[v])
        if (c != p && c != heavy[v])
            for (int u = in[c]; u <= out[c]; u++)
                add_cnt(tour[u]);
    add_cnt(v);
    for (auto qq : que[v]) 
        ans[qq.fi] = state[qq.se] < 2;
    if (!keep) 
        for (int u = in[v]; u <= out[v]; u++)
            add_cnt(tour[u]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 2, j; i <= n; i++){
        cin >> j; add_edge(i, j);
    }
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1, v, h; i <= q; i++){
        cin >> v >> h; que[v].push_back({i, h});
    }
    dfs_tour(1, 0); dfs_sol(1, 1, 0);
    for (int i = 1; i <= q; i++)
        if (ans[i]) puts("Yes"); else puts("No");
}