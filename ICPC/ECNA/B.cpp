#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int a[N], p[N], d[N];
vector<int> adj[N];

void dfs(int u) {
  for (int v : adj[u]) {
    a[v] += a[u];
    d[v] = d[u] + 1;
    dfs(v);
  }
}

int lca(int u, int v) {
  if (d[u] < d[v])
    swap(u, v);
  while (d[u] > d[v])
    u = p[u];
  while (u != v)
    u = p[u], v = p[v];
  return u;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (m--) {
    int u, v; cin >> u >> v; p[v] = u;
  }
  for (int i = 1; i <= n; i++)
    adj[p[i]].push_back(i);
  dfs(0);
  int res = 1e9;
  for (int u = 1; u <= n; u++) {
    if (adj[u].size()) continue;
    for (int v = u + 1; v <= n; v++) {
      if (adj[v].size()) continue;
      res = min(res, a[u] + a[v] - a[lca(u, v)]);
    }
  }
  cout << res << '\n';
}