#include <bits/stdc++.h>
using namespace std;

const int N = 505;
vector <int> adj[N];
int x[N], dis[N], a[N];
bool cho[N];

bool bfs(int n){
    queue <int> q; bool flag = false;
    for (int u = 1; u <= n; u++)
        if (x[u] == 0){
            dis[u] = 0; q.push(u);
        }
        else dis[u] = -1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (x[v] == 0) flag = true;
            else if (dis[x[v]] == -1){
                dis[x[v]] = dis[u] + 1; 
                q.push(x[v]);
            }
    }
    return flag;
}

bool dfs(int u){
    if (dis[u] == -1) return false;
    for (int v : adj[u]){
        if (x[v] == 0){
            x[u] = v; x[v] = u; return true;
        }
        if (dis[x[v]] == dis[u] + 1 && dfs(x[v])){
            x[u] = v; x[v]= u; return true;
        }
    }
    return false;
}

int matching(int n){
    int match = 0;
    while (bfs(n)){
        for (int u = 1; u <= n; u++)
            if (x[u] == 0) match += dfs(u);
    }
    return match;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        for (int j = 1; j < i; j++)
            if (a[i] % a[j] == 0){
                adj[j].push_back(i + n);
                adj[i + n].push_back(j);
            }
    }
    cout << n - matching(n) << '\n';
    queue <int> q;
    for (int i = 1; i <= n; i++){
        if (x[i] == 0) q.push(i);
        if (x[i + n] == 0) q.push(i + n);
    }
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!cho[v]){
                q.push(x[v]); cho[v] = 1;
            }
    }
    for (int i = 1; i <= n; i++)
        if (x[i] > 0 && !cho[i] && !cho[x[i]])
            cho[i] = true;
    for (int i = 1; i <= n; i++)
        if (!cho[i] && !cho[i + n])
            cout << a[i] << ' ';
}