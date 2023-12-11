#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector <int> adj[N];
double res = 0;

void dfs(int u, int p, int d){
    res += 1.0 / d;
    for (int v : adj[u])
        if (v != p)
            dfs(v, u, d + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    cout.precision(10);
    fixed(cout);
    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 1);
    cout << res << '\n';
}