#include "prediction.h"
#include<bits/stdc++.h>

#define ll long long
#define inf (1 << 30)
#define INF (1ll << 60)
#define pb push_back
#define pii pair < int, int >
  #define fi first
#define se second
#define mkp make_pair
#define pll pair < ll, ll >
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
  
using namespace std;

const int MAXN = 1e6 + 10;
const int MAXM = 300010;

vector < int > used[MAXN], e[MAXM];
map < int, int > mp[MAXN][2];
bitset < 10010 > dp[MAXM], tmp;
int tot = 0, deg[MAXM];

void sprd() {
  queue < int > q;
  rep(i, 1, tot) for (int s: e[i]) deg[s]++;
  rep(i, 1, tot) if (!deg[i]) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int s: e[x]) {
      dp[s] |= dp[x];
      if (--deg[s] == 0) q.push(s);
    }
  }
}

struct Query {
  int c, t, x, y;
  void input() {
    cin >> c >> t >> x >> y;
    used[x].pb(t);
  }
} q[MAXN];

int ans[MAXN];

vector<int> count_alive(int T, int n, int m, vector<int> _C, vector<int> _T, vector<int> _X, vector<int> _Y) {
  rep(i, 1, m) {
    q[i].c = _C[i - 1];
    q[i].t = _T[i - 1];
    q[i].x = _X[i - 1] + 1;
    q[i].y = _Y[i - 1] + 1;
    used[q[i].x].pb(q[i].t);
  }
  rep(i, 1, n) {
    used[i].pb(T + 1);
    sort(used[i].begin(), used[i].end());
    used[i].erase(unique(used[i].begin(), used[i].end()), used[i].end());
  }
  rep(i, 1, n) {
    for (int t: used[i]) {
      mp[i][0][t] = ++tot;
      mp[i][1][t] = ++tot;
    }
    rep(j, 0, (int) used[i].size() - 1) {
      if (j) e[mp[i][1][used[i][j - 1]]].pb(mp[i][1][used[i][j]]);
      if (j < (int) used[i].size() - 1)
        e[mp[i][0][used[i][j + 1]]].pb(mp[i][0][used[i][j]]);
    }
  }
  rep(i, 1, m) {
    if (q[i].c == 0) {
      int v = upper_bound(used[q[i].y].begin(), used[q[i].y].end(), q[i].t) - used[q[i].y].begin();
      int to = used[q[i].y][v];
      e[mp[q[i].y][0][to]].pb(mp[q[i].x][0][q[i].t]);
      e[mp[q[i].x][1][q[i].t]].pb(mp[q[i].y][1][to]);
    } else {
      int v = lower_bound(used[q[i].y].begin(), used[q[i].y].end(), q[i].t) - used[q[i].y].begin();
      int to = used[q[i].y][v];
      e[mp[q[i].y][0][to]].pb(mp[q[i].x][1][q[i].t]);
      e[mp[q[i].x][0][q[i].t]].pb(mp[q[i].y][1][to]);
    }
  }
  rep(i, 1, n) ans[i] = n - 1;
  for (int l = 1, r; l <= n;) {
    r = min(l + 9999, n);
    rep(i, 1, tot) dp[i].reset();
    rep(i, l, r) dp[mp[i][0][T + 1]][i - l + 1] = 1;
    sprd();
    tmp.reset();
    rep(i, l, r) if (dp[mp[i][1][T + 1]][i - l + 1]) {
      ans[i] = 0; tmp[i - l + 1] = 1;
    }
    rep(i, 1, n) dp[mp[i][1][T + 1]] |= tmp;
    rep(i, 1, n) if (ans[i]) ans[i] -= dp[mp[i][1][T + 1]].count();
    l = r + 1;
  }
  vector<int> res(ans + 1, ans + n + 1);
  return res;
}