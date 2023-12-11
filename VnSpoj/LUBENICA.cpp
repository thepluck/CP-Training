#define fi first
#define se second
#include <bits/stdc++.h>
using namespace std;

template <class T, class _T>
bool chkmax(T &a, const _T &b){
    return a < b ? a = b, true : false;
}

template <class T, class _T>
bool chkmin(T &a, const _T &b){
    return a > b ? a = b, true : false;
}

struct edge{
    int u, w;
};

const int N = 1e5 + 5;
using ii = pair <int, int>;
vector <edge> adj[N];
int anc[N][18], mi[N][18];
int ma[N][18], dep[N], n, q;

void dfs(int u, int par){
    for (auto e : adj[u])
        if (e.u != par){
            anc[e.u][0] = u; mi[e.u][0] = e.w;
            ma[e.u][0] = e.w; dep[e.u] = dep[u] + 1; 
            dfs(e.u, u);
        }
}

ii min_max(int u, int v){
    ii ans = {INT_MAX, 0};
    for (int k = 17; k >= 0; k--)
        if (dep[anc[u][k]] >= dep[v]){
            chkmin(ans.fi, mi[u][k]);
            chkmax(ans.se, ma[u][k]);
            u = anc[u][k];
        }
    for (int k = 17; k >= 0; k--)
        if (dep[anc[v][k]] >= dep[u]){
            chkmin(ans.fi, mi[v][k]);
            chkmax(ans.se, ma[v][k]);
            v = anc[v][k];
        }
    if (u == v) return ans;
    for (int k = 17; k >= 0; k--)
        if (anc[u][k] != anc[v][k]){
            chkmin(ans.fi, mi[u][k]);
            chkmin(ans.fi, mi[v][k]);
            chkmax(ans.se, ma[u][k]);
            chkmax(ans.se, ma[v][k]);
            u = anc[u][k]; v = anc[v][k];
        }
    chkmin(ans.fi, mi[u][0]);
    chkmax(ans.se, ma[u][0]);
    chkmax(ans.se, ma[v][0]);
    chkmin(ans.fi, mi[v][0]);
    return ans;
}

void solve(){
    cin >> n; int u, v, w;
    for (int i = 1; i < n; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0); dep[0] = -1;
    for (int k = 1; k <= 17; k++)
        for (int i = 1; i <= n; i++)
            if (dep[i] >= (1 << k)){
                anc[i][k] = anc[anc[i][k - 1]][k - 1];
                mi[i][k] = min(mi[i][k - 1], mi[anc[i][k - 1]][k - 1]);
                ma[i][k] = max(ma[i][k - 1], ma[anc[i][k - 1]][k - 1]);
            }
    cin >> q;
    while (q--){
        cin >> u >> v;
        auto ans = min_max(u, v);
        cout << ans.fi << ' ' << ans.se << '\n';
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
}