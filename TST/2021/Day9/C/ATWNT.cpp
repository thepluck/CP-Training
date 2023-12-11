#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int W = 1e6 + 5;

vector <int> adj[N];
vector <pair <int, int>> que[N];
int ans[N];

map <int, int> DFS(int u) {
    int deg = adj[u].size();
    map <int, int> cur;
    if (deg == 0) cur[1] = 1;
    else if (deg == 1)
        cur = move(DFS(adj[u][0]));
    else {
        for (int v : adj[u]) {
            auto nxt = move(DFS(v));
            for (auto pp : nxt)
                if (pp.first * deg < W)
                    cur[pp.first * deg] += pp.second;
        }
    }
    for (auto qq : que[u])
        for (auto pp : cur)
            if (qq.first % pp.first == 0)
                ans[qq.second] -= qq.first / pp.first * pp.second;
    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int u, w; cin >> u >> w;
        que[u].emplace_back(w, i);
        ans[i] = w;
    }
    DFS(1);
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}