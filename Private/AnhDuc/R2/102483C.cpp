#include <bits/stdc++.h>

using namespace std;

using Tp = long double;

const int N = 1005;

int siz[N]; vector <int> adj[N];
pair <Tp, Tp> ans[N];

void DFS1(int u, int p) {
    siz[u] = 1;
    for (int v : adj[u]) if (v != p) {
        DFS1(v, u); siz[u] += siz[v];
    }
}

void DFS2(int u, int p, Tp x, Tp y, Tp lo, Tp hi) {
    ans[u] = {x, y}; Tp cur = lo;
    for (int v : adj[u]) if (v != p) {
        Tp ang = (hi - lo) / (siz[u] - 1) * siz[v];
        Tp mi = (cur + cur + ang) / 2;
        DFS2(v, u, x + cos(mi), y + sin(mi), cur, cur + ang);
        cur += ang;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS1(1, 0);
    DFS2(1, 0, 0, 0, 0, atan2(0, -1) * 2);
    for (int i = 1; i <= n; i++)
        cout << ans[i].first << " " << ans[i].second << "\n"; 
}