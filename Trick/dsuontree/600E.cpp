#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 5; ll sum[N];
int heavy[N], tour[N], in[N], out[N];
int dom[N], cnt[N], n, col[N], tim = 0;
vector <int> adj[N];

int dfs_tour(int v, int p){
    int cur_sz = 1, maxc_sz = 0; 
    in[v] = ++tim; tour[tim] = v;
    for (int c : adj[v]) if (c != p){
        int c_sz = dfs_tour(c, v); cur_sz += c_sz; 
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
    sum[v] = sum[heavy[v]]; dom[v] = dom[heavy[v]];
    for (int c : adj[v])
        if (c != p && c != heavy[v])
            for (int u = in[c]; u <= out[c]; u++){
                cnt[col[tour[u]]]++; 
                if (cnt[col[tour[u]]] > dom[v]){
                    dom[v] = cnt[col[tour[u]]];
                    sum[v] = col[tour[u]];
                }
                else if (cnt[col[tour[u]]] == dom[v])
                    sum[v] += col[tour[u]];
            }
    cnt[col[v]]++; 
    if (cnt[col[v]] > dom[v]){
        dom[v] = cnt[col[v]]; sum[v] = col[v];
    }
    else if (cnt[col[v]] == dom[v]) sum[v] += col[v];
    if (!keep) for (int u = in[v]; u <= out[v]; u++)
        cnt[col[tour[u]]]--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v; 
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs_tour(1, 0); dfs_sol(1, 0, 0);
    for (int i = 1; i <= n; i++) 
        cout << sum[i] << ' ';
}