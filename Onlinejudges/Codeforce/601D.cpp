#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int AL = 26;

int a[N], c[N], s[N];
vector <int> adj[N];
int res, tr[N][AL];
int cnt, sz[N], num;

void merge(int u, int v) {
    sz[u] = 1;
    for (int i = 0; i < AL; i++) {
        if (tr[v][i]) {
            if (tr[u][i])
                merge(tr[u][i], tr[v][i]);
            else tr[u][i] = tr[v][i];
        }
        if (tr[u][i])
            sz[u] += sz[tr[u][i]];
    }
}

int dfs(int u, int p = 0) {
    int tu = ++cnt; sz[tu] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        int tv = dfs(v, u);
        if (!tr[tu][a[v]]) {
            sz[tu] += sz[tv];
            tr[tu][a[v]] = tv;
        }
        else {
            int tc = tr[tu][a[v]];
            sz[tu] -= sz[tc];
            merge(tc, tv);
            sz[tu] += sz[tc];
        }
    }
    if (c[u] + sz[tu] == res) num++;
    else if (c[u] + sz[tu] > res) {
        res = c[u] + sz[tu]; num = 1;
    }
    return tu;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++) {
        char x; cin >> x;
        a[i] = x - 'a';
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); 
    cout << res << '\n' << num << '\n';
}