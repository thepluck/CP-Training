#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int N = 1e5 + 5;

namespace Tarjan {
    int num[N], low[N], n;
    int cmp[N], scc, tim;
    vector <int> adj[N];
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