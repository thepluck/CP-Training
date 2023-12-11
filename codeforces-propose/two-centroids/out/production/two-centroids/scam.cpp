#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const int LOG = 18;

vector<int> adj[N];
int tin[N], tout[N], timer;
int par[LOG][N], bit[N], dep[N];

void dfs(int u) {
  tin[u] = ++timer;
  dep[u] = dep[par[0][u]] + 1;
  for (int k = 1; k < LOG; k++)
    par[k][u] = par[k - 1][par[k - 1][u]];
  for (int v : adj[u]) dfs(v);
  tout[u] = timer;  
}

void add(int u) {
  for (int i = tin[u]; i < N; i += i & -i)
    bit[i]++;
}

int get(int u) {
  int res = 0;
  for (int i = tout[u]; i > 0; i -= i & -i)
    res += bit[i];
  for (int i = tin[u] - 1; i > 0; i -= i & -i)
    res -= bit[i];
  return res;
}

int jump(int u, int d) {
  for (int k = 0; k < LOG; k++)
    if (d >> k & 1) u = par[k][u];
  return u;
}

bool cover(int u, int v) {
  return tin[u] <= tin[v] && tin[v] <= tout[u];
}

void solve() {
  int n; cin >> n;
  
  /// reset
  timer = 0;
  for (int i = 1; i <= n; i++) {
    bit[i] = 0; adj[i].clear();
  }
  
  for (int i = 2; i <= n; i++) {
    cin >> par[0][i];
    adj[par[0][i]].push_back(i);
  }
  dfs(1); add(1);
  int cen = 1, max_siz = 0;
  for (int u = 2; u <= n; u++) {
    add(u);
    if (cover(cen, u)) {
      int v = jump(u, dep[u] - dep[cen] - 1);
      int siz = get(v);
      if (siz >= (u + 1) / 2) {
        cen = v; max_siz = u / 2;
      } else max_siz = max(max_siz, siz);
    } else {
      int siz = get(cen);
      if (siz < (u + 1) / 2) {
        cen = par[0][cen]; max_siz = u / 2;
      } else max_siz = max(max_siz, u - siz);
    }
    int res = 2 * get(cen) - u;
    for (int v : adj[cen])
      res = min(res, u - 2 * get(v));
    cout << res;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) solve();
}