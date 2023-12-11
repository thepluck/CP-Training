#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int siz[N], col[N], cnt[N], par[N];
vector <int> adj[N], own[N]; int res;
bool ban[N], vis[N], mark[N];

void DFS1(int u, int p) {
    siz[u] = 1; mark[col[u]] = 0;
    cnt[col[u]] = vis[u] = 0;
    for (int v : adj[u])
        if (v != p && !ban[v]) {
            DFS1(v, u);
            siz[u] += siz[v];
        }
}

int findCen(int u) {
    int c = u, p = 0;
    while (true) {
        bool flag = false;
        for (int v : adj[c])
            if (v != p && !ban[v] &&
            siz[v] * 2 >= siz[u]) {
                p = c; c = v;
                flag = true; break;
            }
        if (!flag) break;
    }
    return c;
}

void BFS1(int u) {
    stack <int, vector <int>> st;
    st.push(u);
    while (st.size()) {
        u = st.top(); st.pop();
        cnt[col[u]]++;
        for (int v : adj[u])
            if (v != par[u] && !ban[v]) {
                par[v] = u; st.push(v);
            }
    }
}

int BFS2(int u) {
    int cur = 0;
    stack <int, vector <int>> st;
    st.push(u);
    while (st.size()) {
        u = st.top(); st.pop();
        if (mark[col[u]]) continue;
        mark[col[u]] = 1; cur++;
        if (cnt[col[u]] !=
        int(own[col[u]].size()))
            return 1000000000;
        for (int v : own[col[u]])
            while (par[v] && !vis[v]) {
                st.push(v); vis[v] = 1;
                v = par[v];
            }
    }
    return cur;
}

void DFS3(int u) {
    DFS1(u, 0); u = findCen(u);
    par[u] = 0; ban[u] = 1; BFS1(u);
    res = min(res, BFS2(u));
    for (int v : adj[u])
        if (!ban[v]) DFS3(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
        own[col[i]].emplace_back(i);
    }
    res = k; DFS3(1); cout << res - 1;
}