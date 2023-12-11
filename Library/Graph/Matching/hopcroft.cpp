#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

namespace HopcroftKarp {
    int lef[N], rig[N], n;
    queue <int> que; int dis[N];
    vector <int> adj[N];

    void init(int n) {
        HopcroftKarp::n = n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    bool bfs() {
        for (int u = 1; u <= n; u++)
            if (!rig[u]) {
                dis[u] = 0; que.push(u);
            }
            else dis[u] = -1;
        bool flag = 0;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int v : adj[u])
                if (!lef[v]) flag = true;
                else if (dis[lef[v]] < 0) {
                    dis[lef[v]] = dis[u] + 1;
                    que.push(lef[v]);
                }
        }
        return flag;
    }

    bool dfs(int u) {
        for (int v : adj[u])
            if (!lef[v] || (dis[lef[v]] ==
            dis[u] + 1 && dfs(lef[v]))) {
                lef[v] = u; rig[u] = v;
                return true;
            }
        dis[u] = -1; return false;
    }

    int maximum_matching() {
        int matching = 0;
        while (bfs())
            for (int u = 1; u <= n; u++)
                if (!rig[u])
                    matching += dfs(u);
        return matching;
    }

    bool is_match(int u, int v) {
        return rig[u] == v;
    }
};

int main() {
    
}