#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adj[N][N], y[N], n, m;
bitset <N> used;

bool dfs(int i) {
    if (used[i]) return 0;
    used[i] = 1;
    for (int j = 1; j <= m; j++)
        if (adj[i][j]) {
            if (!y[j] || dfs(y[j])) {
                y[j] = i; return 1;
            }
        }
    return 0;
}

int matching() {
    int match = 0;
    for (int i = 1; i <= n; i++) {
        used.reset(); 
        match += dfs(i);
    }
    return match;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int u, v; cin >> n >> m;
    while (cin >> u >> v)
    	adj[u][v] = 1;
    cout << matching() << '\n';
    for (int i = 1; i <= m; i++)
    	if (y[i])
    		cout << y[i] << ' ' << i << '\n';
}