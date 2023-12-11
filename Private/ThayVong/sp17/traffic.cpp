#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
using ll = long long;

const int N = 2e5 + 5;
vector <int> adj[N];
int dis[2][N], cnt[N], cn[N];
queue <int> q; long long ans;

void bfs(int s, int res[]){
    res[s] = 0; q.emplace(s);
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u]){
            if (res[v] != -1) continue;
            res[v] = res[u] + 1;
            q.emplace(v);
        }
    }
}

int main(){
    freopen("traffic.inp", "r", stdin);
    freopen("traffic.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, m, s, t;
    memset(dis, -1, sizeof dis);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    bfs(s, dis[0]); bfs(t, dis[1]);
    for (int i = 1; i <= n; i++){
        cnt[dis[0][i]]++;
        cn[dis[1][i]]++;
    }
    int path = dis[0][t];
    for (int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 0; i < path - 1; i++)
        ans += cn[i] * cnt[path - 2 - i];
    cout << ans << '\n';
}