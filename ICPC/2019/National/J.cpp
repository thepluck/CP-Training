#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

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

namespace Tarjan {
    int num[N * 2], low[N * 2], n;
    int cmp[N * 2], scc, tim;
    vector <int> adj[N * 2];
    stack <int, vector <int>> st;

    void init(int n) {
        Tarjan::n = n;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    void dfs(int u) {
        low[u] = num[u] = ++tim;
        st.push(u);
        for (int v : adj[u])
            if (num[v])
                cmin(low[u], num[v]);
            else {
                dfs(v);
                cmin(low[u], low[v]);
            }
        if (num[u] == low[u]) {
            scc++; int v;
            do {
                v = st.top(); st.pop();
                num[v] = low[v] = n + 1;
                cmp[v] = scc;
            }
            while (v != u);
        }
    }

    void find_scc() {
        for (int u = 1; u <= n; u++)
            if (!num[u]) dfs(u);
    }

    bool is_same_scc(int u, int v) {
        return cmp[u] == cmp[v];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    HopcroftKarp::init(n);
    Tarjan::init(2 * n);
    set <pair <int, int>> seen;
    vector <pair <int, int>> edges;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        HopcroftKarp::add_edge(u, v);
        edges.push_back({u, v});
    }
    HopcroftKarp::maximum_matching();
    for (auto edge : edges) {
        int u, v; tie(u, v) = edge;
        if (!seen.count(edge) &&
        HopcroftKarp::is_match(u, v))
            Tarjan::add_edge(v + n, u);
        else Tarjan::add_edge(u, v + n);
        seen.insert({u, v});
    }
    Tarjan::find_scc(); int fixs = 0;
    for (auto edge : seen) {
        int u, v; tie(u, v) = edge;
        if (HopcroftKarp::is_match(u, v)
        && !Tarjan::is_same_scc(u, v + n))
            fixs++;
    }
    cout << m - fixs << '\n';
}