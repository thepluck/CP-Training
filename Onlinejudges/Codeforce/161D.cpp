#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int hv[N], cnt[N], k, n, tim, dep[N];
int in[N], out[N], ver[N]; ll res;
vector <int> adj[N];

void add_edge(int u, int v){
    adj[u].push_back(v); adj[v].push_back(u);
}

int dfs_hv(int v, int p){
    int v_sz = 1, maxc_sz = 0, c_sz;
    in[v] = ++tim; ver[tim] = v;
    for (int c : adj[v]) if (c != p){
        dep[c] = dep[v] + 1; 
        v_sz += c_sz = dfs_hv(c, v);
        if (c_sz > maxc_sz){
            hv[v] = c; maxc_sz = c_sz;
        }
    }
    out[v] = tim; return v_sz;
}

void dfs_sol(int v, int p, bool cl){
    for (int c : adj[v])
        if (c != p && c != hv[v])
            dfs_sol(c, v, 1);
    if (hv[v]) dfs_sol(hv[v], v, 0);
    for (int c : adj[v])
        if (c != p && c != hv[v]){
            for (int i = in[c]; i <= out[c]; i++)
                if (k + 2 * dep[v] - dep[ver[i]] >= 0)
                    res += cnt[k + 2 * dep[v] - dep[ver[i]]];
            for (int i = in[c]; i <= out[c]; i++)
                cnt[dep[ver[i]]]++;
        }
    res += cnt[k + dep[v]]; cnt[dep[v]]++;
    if (cl) for (int i = in[v]; i <= out[v]; i++)
        cnt[dep[ver[i]]]--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v; add_edge(u, v);
    }
    dfs_hv(1, 0); dfs_sol(1, 0, 0);
    cout << res << '\n';
}