#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e6 + 5;
const int LOG = 20;
 
/// lca stuff
int tin[N], timer = 0;
vector<int> path, rmq[20];
 
/// some tree stuff
vector<int> adj[N], leaf, topo;
int n, m, par[N], val[N];
 
/// trips
vector<int> trip[N];
 
void dfs_pre(int u) {
  topo.push_back(u);
  tin[u] = timer++;
  for (int v : adj[u])
     if (v != par[u]) {
      path.push_back(u);
      rmq[0].push_back(tin[u]);
      par[v] = u; dfs_pre(v);
     }
}
 
int get_min(int l, int r) {
  assert(l < r);
  int k = 31 - __builtin_clz(r - l);
  return min(rmq[k][l], rmq[k][r - (1 << k)]);
}
 
int lca(int u, int v) {
  if (u == v) return u;
  tie(u, v) = minmax(tin[u], tin[v]);
  return path[get_min(u, v)];
}
 
int lca_reroot(int r, int u, int v) {
  return lca(r, u) ^ lca(r, v) ^ lca(u, v);
}
 
void calc_val() {
  for (int u : topo)
    for (int v : adj[u])
      if (v != par[u]) val[u] += val[v];
}
 
void add(int u) {
  for (int v : trip[u])
    if (v < 0) val[-v]--;
    else val[v]++;
}
 
bool check(int l) {
  for (int u = 1; u <= n; u++) val[u] = 0;
  for (int i = 0; i < l; i++) add(leaf[i]);
  calc_val();
  for (int u = 1; u <= n; u++)
    if (val[u] == l) return true;
  return false;
}
 
void solve() {
  cin >> n >> m;
    
  /// reset 
  for (int i = 1; i <= n; i++) {
    adj[i].clear(); trip[i].clear();
  }
  timer = 0; leaf.clear(); topo.clear();
  path.clear(); rmq[0].clear();
 
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  /// leaves only
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    if (adj[u].size() == 1)
      trip[u].push_back(v);
    if (adj[v].size() == 1)
      trip[v].push_back(u);
  }
  
  if (n == 1) {
    cout << "YES\n"; return;
  }
  
  /// prepare
  dfs_pre(1);
  reverse(topo.begin(), topo.end());
  for (int k = 1; (1 << k) <= n; k++) {
    rmq[k].resize(n - (1 << k) + 1);
    for (int i = 0; i + (1 << k) <= n; i++)
      rmq[k][i] = min(rmq[k - 1][i],
      rmq[k - 1][i + (1 << (k - 1))]);
  }
  
  for (int u = 1; u <= n; u++)
    if (adj[u].size() == 1) {
      leaf.push_back(u);
      trip[u].push_back(u);
      sort(trip[u].begin(), trip[u].end(),
      [&](int x, int y) {
        return tin[x] < tin[y];});
      int l = trip[u].size();
      for (int i = 0; i + 1 < l; i++)
        trip[u].push_back(-lca
        (trip[u][i], trip[u][i + 1]));
      trip[u].push_back(-par[lca
      (trip[u][0], trip[u][l - 1])]);
    }
  
  /// find longest prefix of leaves 
  int l = 0;
  for (int k = LOG - 1; k >= 0; k--)
    if (l + (1 << k) <= leaf.size()
    && check(l + (1 << k))) l += 1 << k;
 
  if (l == leaf.size()) {
    cout << "YES\n"; return;
  }
  
  cout << "NO\n";
 
  for (int u = 1; u <= n; u++) val[u] = 0;
  add(leaf[l]); calc_val();
  
  for (int u : leaf) {
    bool good = false;
    for (int v : trip[u]) {
      if (v <= 0) break;
      if (val[lca_reroot(leaf[l], u, v)]) {
        good = true; break;
      }
    }
    if (!good) {
      cout << leaf[l] << ' ' << u << '\n';
      return;
    }
  }
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t; cin >> t;
  
  while (t--) solve();
}
