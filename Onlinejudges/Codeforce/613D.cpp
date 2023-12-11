#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

vector <int> adj[N];
set <int> rem[N], que[N];
int ans[N];

void dfs(int u, int p = 0) {
    set <int> need;
    for (int v : adj[u]) {
        if (v == p) continue; dfs(v, u);
        if (rem[v].size() > rem[u].size())
            swap(rem[v], rem[u]);
        for (int q : que[v])
            if (que[u].count(q))
                ans[q] = inf;
        for (int q : rem[v])
            if (que[u].count(q)) ans[q]++;
            else if (rem[u].count(q))
                need.insert(q);
            else rem[u].insert(q);
    }
    for (int q : need) {
        rem[u].erase(q); ans[q]++;
    }
    for (int q : que[u])
        if (rem[u].count(q)) ans[q]++;
        else rem[u].insert(q);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int k, u; cin >> k;
        while (k--) {
            cin >> u;
            que[u].insert(i);
        }
    }
    dfs(1);
    for (int i = 1; i <= q; i++)
        if (ans[i] >= inf) cout << "-1\n";
        else cout << ans[i] << '\n';
}