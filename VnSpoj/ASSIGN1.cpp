#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

const int N = 1005;

vector <int> adj[N];
int x[N], y[N], dis[N], n, c[N][N];

bool bfs() {
    queue <int> q; bool ok = 0;
    for (int u = 1; u <= n; u++)
        if (!x[u]) {
            dis[u] = 0; q.push(u);
        }
        else dis[u] = -1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!y[v]) ok = 1;
            else if (dis[y[v]] == -1) {
                dis[y[v]] = dis[u] + 1;
                q.push(y[v]);
            }
    }
    return ok;
}

bool dfs(int u) {
    if (dis[u] == -1) return 0;
    for (int v : adj[u]) {
        if (!y[v] || (dis[y[v]] ==
        dis[u] + 1 && dfs(y[v]))) {
            x[u] = v; y[v] = u;
            return 1;
        }
    }
    return 0;
}

int matching() {
    for (int i = 1; i <= n; i++)
        x[i] = y[i] = 0;
    int match = 0;
    while (bfs()){
        for (int u = 1; u <= n; u++)
            if (!x[u]) match += dfs(u);
    }
    return match;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    int lo = 0, hi = 1e9, mi, ans = 0;
    while (lo <= hi) {
        mi = (lo + hi) / 2;
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            for (int j = 1; j <= n; j++)
                if (c[i][j] <= mi)
                    adj[i].eb(j);
        }
        if (matching() == n) {
            hi = mi - 1; ans = mi;
        }
        else lo = mi + 1;
    }
    cout << ans << '\n';
}
