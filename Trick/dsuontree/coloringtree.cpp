#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ub upper_bound

const int N = 1e5 + 5;
int col[N], cnt[N], hv[N], ans[N];
int in[N], out[N], ver[N], tim;
vector <int> adj[N];

void dfs_init(int v, int p){
    adj[v].erase(find(all(adj[v]), p));
    for (int c : adj[v]) dfs_init(c, v);
}

int dfs_hv(int v){
    in[v] = ++tim; ver[tim] = v;
    int c_sz, maxc_sz = 0, v_sz = 1;
    for (int c : adj[v]){
        v_sz += c_sz = dfs_hv(c);
        if (c_sz > maxc_sz){
            maxc_sz = c_sz; hv[v] = c;
        }
    }
    out[v] = tim; return v_sz;
}

void dfs_sol(int v, bool cl){
    for (int c : adj[v])
        if (c != hv[v]) dfs_sol(c, 1);
    if (hv[v]) dfs_sol(hv[v], 0);
    ans[v] = ans[hv[v]];
    ans[v] += ++cnt[col[v]] == 1;
    for (int c : adj[v]) if (c != hv[v])
        for (int i = in[c]; i <= out[c]; i++)
            ans[v] += ++cnt[col[ver[i]]] == 1;
    if (cl) for (int i = in[v]; i <= out[v]; i++)
                cnt[col[ver[i]]]--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, root; cin >> n >> m >> root;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    vector <int> cmp;
    for (int i = 1; i <= n; i++){
        cin >> col[i]; cmp.eb(col[i]);
    }
    adj[root].eb(0); dfs_init(root, 0); 
    sort(all(cmp));
    cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 1; i <= n; i++)
        col[i] = ub(all(cmp), col[i]) - cmp.begin();
    dfs_hv(root); dfs_sol(root, 0);
    for (int i = 1, u; i <= m; i++){
        cin >> u; cout << ans[u] << '\n';
    }
}