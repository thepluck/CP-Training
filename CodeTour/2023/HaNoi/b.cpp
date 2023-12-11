#include <bits/stdc++.h>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<vector<int>> adj(n);
  int u, v;
  while (cin >> u >> v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> vis(n);
  int cnt = 0, res = 0;
  for (int i = 0; i < n; i++)
    if (!vis[i]) {
      int cur = 0;
      queue<int> q; q.push(i);
      vis[i] = 1;
      while (q.size()) {
        cur++; res += cnt;
        int u = q.front(); q.pop();
        for (int v : adj[u])
          if (!vis[v]) {
            vis[v] = 1; q.push(v);
          }
      }
      cnt += cur;
    }
  cout << res;
}