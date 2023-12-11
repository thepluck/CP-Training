#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

#define eb emplace_back
#define all(v) (v).begin(), (v).end()
using ll = long long;

struct edge{
    int v; ll w;

    edge(){}

    edge(int v, ll w): v(v), w(w){}

    bool operator < (const edge &o) const {
        return w > o.w;
    }
};

const int N = 1e5 + 5;
ll dp[N], dis_s[N], dis_t[N];
ll dis_x[N], dis_y[N];
vector <edge> adj[N];
priority_queue <edge> pq;

void dijkstra(int s, ll res[]){
    res[s] = 0; pq.emplace(s, 0);
    while (!pq.empty()){
        edge cur = pq.top(); pq.pop();
        if (res[cur.v] < cur.w) continue;
        for (auto nxt : adj[cur.v])
            if (chkmin(res[nxt.v], cur.w + nxt.w))
                pq.emplace(nxt.v, res[nxt.v]);
    }
}

int main(){
    //freopen("pathlib.inp", "r", stdin);
    //freopen("pathlib.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, s, t, x, y;
    cin >> n >> m >> s >> t >> x >> y;
    memset(dis_s, 0x3f, sizeof dis_s);
    memset(dis_t, 0x3f, sizeof dis_t);
    memset(dis_x, 0x3f, sizeof dis_x);
    memset(dis_y, 0x3f, sizeof dis_y);
    for (int i = 1; i <= m; i++){
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].eb(v, w); adj[v].eb(u, w);
    }
    dijkstra(s, dis_s); dijkstra(t, dis_t);
    dijkstra(x, dis_x); dijkstra(y, dis_y);
    vector <int> in_st_path;
    for (int i = 1; i <= n; i++)
        if (dis_s[i] + dis_t[i] == dis_s[t])
            in_st_path.eb(i);
    sort(all(in_st_path), [&](int p, int q){
        return dis_s[p] < dis_s[q];
    });
    for (int u : in_st_path) dp[u] = dis_x[u];
    ll res = dis_x[y];
    for (int u : in_st_path){
        chkmin(res, dp[u] + dis_y[u]);
        for (auto nxt : adj[u]){
            if (dis_s[nxt.v] != dis_s[u] + nxt.w)
                continue;
            chkmin(dp[nxt.v], dp[u]);
        }
    }
    for (int u : in_st_path) dp[u] = dis_y[u];
    for (int u : in_st_path){
        chkmin(res, dp[u] + dis_x[u]);
        for (auto nxt : adj[u]){
            if (dis_s[nxt.v] != dis_s[u] + nxt.w)
                continue;
            chkmin(dp[nxt.v], dp[u]);
        }
    }
    cout << res << '\n';
}
