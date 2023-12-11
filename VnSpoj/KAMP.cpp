#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmax(X &a, const Y &b){
    return a < b ? a = b, 1 : 0;
}

#define eb emplace_back
using ll = long long;

struct edge{
    int v, w;

    edge(int v, int w): v(v), w(w){}
};

const int N = 5e5 + 5;
const int ninf = 0xc0c0c0c0;
vector <edge> adj[N];
ll dp[N][2], tot, res[N], dis[N];
queue <int> q; bitset <N> vs;
int ver[N], has[N], root;

void dfs1(int u, int p){
    dp[u][0] = has[u] ? 0 : ninf;
    ver[u] = has[u] ? u : -1;
    for (edge e : adj[u]){
        if (e.v == p) continue;
        dfs1(e.v, u); has[u] += has[e.v];
        if (dp[u][0] <= dp[e.v][0] + e.w){
            dp[u][1] = dp[u][0];
            dp[u][0] = dp[e.v][0] + e.w;
            ver[u] = e.v;
        }
        else chkmax(dp[u][1], dp[e.v][0] + e.w);
    }
}

void dfs2(int u, int p){
    for (edge e : adj[u]){
        if (e.v == p) continue;
        if (ver[u] != e.v){
            if (dp[e.v][0] <= dp[u][0] + e.w){
                dp[e.v][1] = dp[e.v][0];
                dp[e.v][0] = dp[u][0] + e.w;
                ver[e.v] = u;
            }
            else chkmax(dp[e.v][1], dp[u][0] + e.w);
        }
        else {
            if (dp[e.v][0] <= dp[u][1] + e.w){
                dp[e.v][1] = dp[e.v][0];
                dp[e.v][0] = dp[u][1] + e.w;
                ver[e.v] = u;
            }
            else chkmax(dp[e.v][1], dp[u][1] + e.w);
        }
        dfs2(e.v, u);
    }
}

void dfs3(int u, int p){
    for (edge e : adj[u])
        if (e.v != p && has[e.v]){
            tot += e.w; q.push(e.v);
            vs[e.v] = 1; dfs3(e.v, u);
        }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w); adj[v].eb(u, w);
    }
    for (int i = 1; i <= k; i++){
        int u; cin >> u;
        has[u] = 1; root = u;
    }
    q.push(root);
    dfs1(root, 0); dfs2(root, 0);
    dfs3(root, 0); vs[root] = 1;
    while (!q.empty()){
        int u = q.front(); q.pop();
        res[u] = 2 * dis[u] + 2 * tot - dp[u][0];
        for (edge e : adj[u]){
            if (vs[e.v]) continue;
            vs[e.v] = 1; q.push(e.v);
            dis[e.v] = dis[u] + e.w;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
}