#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int a[N], dp[N], siz[N];
int sum[N], tra[N][32];
vector<int> adj[N], ans;

void dfs(int u) {
  siz[u] = 1; sum[u] = a[u];
  dp[u] = 1 << a[u];
  for (int v : adj[u]) {
    dfs(v); siz[u] ^= siz[v];
    sum[u] ^= sum[v];
    int tmp = 0;
    for (int x = 0; x < 32; x++)
      for (int y = 0; y < 32; y++)
        if ((dp[u] >> x & 1) && (dp[v] >> y & 1)) {
          tmp |= 1 << (x ^ y); tra[v][x ^ y] = y;
        }
    dp[u] = tmp;
  }
  if (!siz[u]) dp[u] |= 1 << 0;
}

void trace(int u, int x) {
  if (!x && !siz[u]) return ans.push_back(u);
  reverse(adj[u].begin(), adj[u].end());
  for (int v : adj[u]) {
    trace(v, tra[v][x]); x ^= tra[v][x];
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 2; i <= n; i++) {
    int j; cin >> j; adj[j].push_back(i);
  }
  dfs(1);
  if (~dp[1] & 1) return cout << -1, 0;
  trace(1, 0); ans.push_back(1);
  cout << ans.size() << '\n';
  for (int u : ans) cout << u << ' ';
}