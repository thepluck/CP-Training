#include <bits/stdc++.h>
using namespace std;

using ii = pair <int, int>;
const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
vector <int> adj[N];
int cap[N][N], par[N], n;

void add_edge(int u, int v, int c){
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = c; cap[v][u] = 0;
}

int bfs(int s, int t){
    fill_n(par + 1, n, 0);
    queue <ii> q; q.push({s, inf});
    int u, fl;
    while (!q.empty()){
        tie(u, fl) = q.front(); q.pop();
        for (int v : adj[u])
            if (!par[v] && cap[u][v]){
                par[v] = u;
                int nfl = min(fl, cap[u][v]);
                if (v == t) return nfl;
                q.push({v, nfl});
            }
    }
    return 0;
}

int max_flow(int s, int t){
    int fl = 0, nfl;
    while (nfl = bfs(s, t)){
        fl += nfl; int u = t;
        while (u != s){
            cap[par[u]][u] -= nfl;
            cap[u][par[u]] += nfl;
            u = par[u];
        }
    }
    return fl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, s, t, u, v, c;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> c; 
        add_edge(u, v, c);
    }
    cout << max_flow(s, t) << '\n';
}