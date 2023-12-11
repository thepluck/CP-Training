// Problem: D. TWOSAT - Du lịch
// Contest: Codeforces - ACM set 18
// URL: https://codeforces.com/group/FLVn1Sc504/contest/274707/problem/D
// Memory Limit: 1024 MB
// Time Limit: 250 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector <int> adj[N], rev[N], ord;
bool vis[N]; int comp[N], ans[N];

int id(int i) {
    if (i > 0) return 2 * i - 1;
    return -2 * i;
}

void addEdge(int u, int v) {
    adj[id(-u)].push_back(id(v));
    adj[id(-v)].push_back(id(u));
    rev[id(v)].push_back(id(-u));
    rev[id(u)].push_back(id(-v));
}

void dfs1(int u) {
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v]) dfs1(v);
    ord.push_back(u);
}

void dfs2(int u, int cc) {
    comp[u] = cc;
    for (int v : rev[u])
        if (!comp[v]) dfs2(v, cc);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, cc = 0, res = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!vis[i]) dfs1(i);
    reverse(ord.begin(), ord.end());
    for (int u : ord)
        if (!comp[u]) dfs2(u, ++cc);
    for (int i = 1; i <= 2 * n; i += 2) {
        if (comp[i] == comp[i + 1]) {
            cout << "NO\n"; return 0;
        }
        ans[i] = comp[i] > comp[i + 1];
        res += ans[i];
    }
    cout << "YES\n" << res << '\n';
    for (int i = 1; i <= 2 * n; i += 2)
        if (ans[i])
            cout << (i + 1) / 2 << ' ';
}
