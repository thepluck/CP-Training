#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 305;

bool adj[MAXN][MAXN];
int A[MAXN]; bool vis[MAXN];
queue <int> que;

vector <int> get_component
(int u, const vector <int> &node) {
    vector <int> cmp;
    que.push(u); vis[u] = 1;
    while (que.size()) {
        u = que.front(); que.pop();
        cmp.push_back(u);
        for (int v : node)
            if (!vis[v] && adj[u][v]) {
                vis[v] = 1; que.push(v);
            }
    }
    return cmp;
}

int get_weight(const vector <int> &node) {
    int res = 0;
    for (int u : node) res += A[u];
    return res;
}

vector <int> get_max_weight
(const vector <int> &node, bool type) {
    if (node.size() == 1) return node;
    for (int u : node)
        for (int v : node)
            if (u != v) adj[u][v] ^= 1;
    vector <int> res; int wres = 0;
    vector <vector <int>> cmps;
    for (int u : node)
        if (!vis[u])
            cmps.push_back
            (get_component(u, node));
    for (int u : node) vis[u] = 0;
    for (auto cmp : cmps) {
        vector <int> tmp =
        get_max_weight(cmp, type ^ 1);
        if (type) {
            if (cmax(wres, get_weight(tmp)))
                res = tmp;
        } else {
            for (int u : tmp)
                res.push_back(u);
        }
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector <int> node;
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i]; node.push_back(i);
    }
    while (M--) {
        int u, v; cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    
    vector <int> res; int wres = 0;
    vector <vector <int>> cmps;
    for (int u : node)
        if (!vis[u])
            cmps.push_back
            (get_component(u, node));
    for (int u : node) vis[u] = 0;
    for (auto cmp : cmps) {
        vector <int> tmp =
        get_max_weight(cmp, 0);
        if (cmax(wres, get_weight(tmp)))
            res = tmp;
    }
    cout << wres << '\n' << res.size() << '\n';
    for (int u : res) cout << u << ' ';
}