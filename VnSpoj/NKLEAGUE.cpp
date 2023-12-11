#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector <int> adj[N];
int topo[N], cnt;
bitset <N> used;

void dfs(int u){
    used[u] = true;
    for (int v : adj[u])
        if (!used[v]) dfs(v);
    topo[cnt--] = u;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n; cnt = n;
    for (int i = 1; i <= n; i++){
        char x;
        for (int j = 1; j <= n; j++){
            cin >> x; 
            if (x == '1') adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!used[i]) dfs(i);
    for (int i = 1; i <= n; i++)
        cout << topo[i] << ' ';
}