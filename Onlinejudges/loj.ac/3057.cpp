/// Determine whether exist a path (not necessarily simple) from u to v is a palindrome

/// Naive O(m^2)
/// New graph (u, v)
/// (u, v) -> (x, y) if color[x] = color[y] and u-x, v-y adjcent
/// BFS from (i, i) and (u, v) with color[u] = color[v] and u-v adjcent
/// Answer: Check if (u, v) is visited

/// Improved O(nm) 70%
/// New graph (u, v, t)
/// t = 0: u move one step
/// t = 1: v move one step while keeping path palindrome
/// BFS from (i, i, 0) and (u, v, 0)
/// Answer: Check if (u, v, 0) is visited

/// Reduce number of edges
/// Split edges to 2 types
/// 1: connect 2 vertices of the same color
/// 2: opposite

/// if we want find a path from u to x and from v to y using the same type of edge
/// just find a path u - x and v - y have the same parity of length
/// then we can move back and forth on the same edge until 2 paths equal

/// so for any (u, v) we only need to determine
/// if u can reach v using odd or even number of edge
 
/// For type 1, consider a connected component, find a spanning tree
/// If this component isn't bipartite, add a self-loop to one of its vertices

/// For type 2, just find a spanning tree because it 's always bipartite

/// Complexity O(n^2) enough to pass

#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

char str[N], vis[N];
vector <int> org[N], red[N];
bool mark[N][N][2];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q >> (str + 1);
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        org[u].push_back(v);
        org[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        queue <int> que;
        que.push(i); vis[i] = 1;
        bool odd = false;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : org[u])
                if (str[u] == str[v]) {
                    if (!vis[v]) {
                        red[u].push_back(v);
                        red[v].push_back(u);
                        vis[v] = -vis[u];
                        que.push(v);
                    }
                    else if (vis[u] == vis[v])
                        odd = true;
                }
        }
        if (odd) red[i].push_back(i);
    }
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        queue <int> que;
        que.push(i); vis[i] = 1;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : org[u])
                if (str[u] != str[v] && !vis[v]) {
                    red[u].push_back(v);
                    red[v].push_back(u);
                    vis[v] = 1; que.push(v);
                }  
        }
    }
    queue <tuple <int, int, bool>> que;
    for (int u = 1; u <= n; u++) {
        que.emplace(u, u, 0);
        mark[u][u][0] = 1;
        for (int v : red[u])
            if (str[u] == str[v]) {
                que.emplace(u, v, 0);
                mark[u][v][0] = 1;
            }
    }
    while (que.size()) {
        int u, v; bool t;
        tie(u, v, t) = que.front(); que.pop();
        if (t) {
            for (int w : red[v])
                if (str[u] == str[w] && !mark[u][w][0]) {
                    mark[u][w][0] = 1;
                    que.emplace(u, w, 0);
                }
        }
        else {
            for (int w : red[u])
                if (!mark[w][v][1]) {
                    mark[w][v][1] = 1;
                    que.emplace(w, v, 1);
                }
        }
    }
    while (q--) {
        int u, v; cin >> u >> v;
        cout << (mark[u][v][0] ? "YES\n" : "NO\n");
    }
}