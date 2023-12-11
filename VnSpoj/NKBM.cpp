#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
vector <int> adj[N];
int x[N], y[N], dis[N], n, m;

bool bfs(){
    queue <int> q; bool flag = false;
    for (int u = 1; u <= n; u++)
        if (x[u] == 0){
            dis[u] = 0; q.push(u);
        }
        else dis[u] = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (y[v] == 0) flag = true;
            else if (dis[y[v]] == -1){
                dis[y[v]] = dis[u] + 1; 
                q.push(y[v]);
            }
    }
    return flag;
}

bool dfs(int u){
    if (dis[u] == -1) return false;
    for (int v : adj[u]){
        if (y[v] == 0){
            x[u] = v; y[v] = u; return true;
        }
        if (dis[y[v]] == dis[u] + 1 && dfs(y[v])){
            x[u] = v; y[v]= u; return true;
        }
    }
    return false;
}

int matching(){
    int match = 0;
    while (bfs()){
        for (int u = 1; u <= n; u++)
            if (x[u] == 0) match += dfs(u);
    }
    return match;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int e, u, v; cin >> n >> m >> e;
    while (e--){
        cin >> u >> v; adj[u].push_back(v);
    }
    cout << matching() << '\n';
}
