#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 5005;
int cap[N][N], h[N], exc[N], n;
vector <int> adj[N]; int flow[N][N];
queue <int> q;

void push(int u, int v){
    if (h[u] <= h[v]) return;
    int d = min(exc[u], cap[u][v]);
    cap[u][v] -= d; cap[v][u] += d;
    exc[u] -= d; exc[v] += d;
    flow[u][v] += d; flow[v][u] -= d;
    if (d && exc[v] == d) q.push(v);
}

void relabel(int u){
    int d = inf;
    for (int v : adj[u])
        if (cap[u][v] > 0)
            d = min(d, h[v]);
    if (d < inf) h[u] = d + 1;
}

void discharge(int u){
    for (int v : adj[u]) push(u, v);
    if (exc[u]){
        relabel(u); q.push(u);
    }
}

int max_flow(int s, int t){
    for (int i = 1; i <= n; i++)
        h[i] = exc[i] = 0;
    h[s] = n; exc[s] = inf;
    for (int v : adj[s]) push(s, v);
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (u != s && u != t) 
            discharge(u);
    }
    int res = 0;
    for (int v : adj[s]) 
        res += flow[s][v];
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, s, t, u, v, c;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = c;
    }
    cout << max_flow(s, t) << '\n';
}