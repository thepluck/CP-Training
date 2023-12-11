#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)
#define lb lower_bound
#define ub upper_bound
#define eb emplace_back
using ll = long long;

const int N = 1e5 + 5;
int in[N], out[N], tr[N], tim;
int hv[N], col[N], bit[N], n;
ll res; vector <int> adj[N];

void add_edge(int u, int v){
    adj[u].eb(v); adj[v].eb(u);

}

void update(int i, int t){
    for (; i <= n; i += i & -i) bit[i] += t;
}

int retrieve(int i){
    int ans = 0; 
    for (; i > 0; i -= i & -i) ans += bit[i];
    return ans;
}

int dfs_tour(int v, int p){
    int v_sz = 1, maxc_sz = 0, c_sz;
    in[v] = ++tim; tr[tim] = v;
    for (int c : adj[v]) if (c != p){
        v_sz += c_sz = dfs_tour(c, v);
        if (c_sz > maxc_sz){
            maxc_sz = c_sz; hv[v] = c;
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
        if (c != p && c != hv[v])
            for (int i = in[c]; i <= out[c]; i++)
                update(col[tr[i]], 1);
    int cnt = retrieve(col[v] - 1);
    res += 1ll * cnt * (cnt - 1) / 2;
    update(col[v], 1);
    if (cl) for (int i = in[v]; i <= out[v]; i++)
        update(col[tr[i]], -1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> col[1]; vector <int> cmp;
    for (int i = 2, j; i <= n; i++){
        cin >> j >> col[i]; add_edge(i, j);
    }
    for (int i = 1; i <= n; i++) cmp.eb(col[i]);
    sort(all(cmp));
    cmp.resize(unique(all(cmp)) - cmp.begin());
    for (int i = 1; i <= n; i++)
        col[i] = ub(all(cmp), col[i]) - cmp.begin();
    dfs_tour(1, 0); dfs_sol(1, 0, 0);
    cout << res << '\n'; return 0;
}