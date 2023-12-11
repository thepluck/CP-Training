#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define X first
#define Y second
#define print(_c) for (auto& _e : _c) {cout << _e << ' ';} cout << '\n';
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int inf = 1e9;
int pw(ll x, ll k) {
  ll res = 1;
  for (; k; k >>= 1, x = (x * x) % mod) if (k & 1) res = (res * x) % mod;
  return res;
}
vector<pii> seg;
pii get(int a, int b, int k, int l, int r) {
  if (r < a || l > b) return {inf, 0};
  if (l == r) return seg[k];
  int m = (l + r) >> 1;
  pii x = get(a, b, k<<1, l, m), y = get(a, b, k<<1|1, m+1, r);
  if (x.X == y.X) return {x.X, (x.Y + y.Y) % mod};
  return min(x, y);
}
void update(int i, int x, int y, int k, int l, int r) {
  if (i < l || i > r) return;
  assert(l <= i && i <= r);
  if (l == r) {
    if (seg[k].X == x) seg[k].Y = (seg[k].Y + y) % mod;
    else if (x < seg[k].X) seg[k] = {x, y};
    return;
  }
  int m = (l + r) >> 1;
  update(i, x, y, k<<1, l, m); update(i, x, y, k<<1|1, m+1, r);
  if (seg[k<<1].X == seg[k<<1|1].X) seg[k] = {seg[k<<1].X, (seg[k<<1].Y + seg[k<<1|1].Y) % mod};
  else seg[k] = min(seg[k<<1], seg[k<<1|1]);
}
void solve() {
  int n; cin >> n;
  vector<pii> a(n);
  for (auto& x : a) cin >> x.Y >> x.X;
  sort(a.rbegin(), a.rend()); vector<int> b; // so lan xh
  for (int i = 0; i < n;) {
    b.push_back(1); i++;
    while (i < n && a[i] == a[i-1]) {
      b.back()++; i++;
    }
  }
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size(); vector<int> val(n), c(2 * n);
  for (int i = 0; i < n; ++i) {
    if (a[i].X == a[i].Y) b[i] = pw(2, b[i]);
    val[i] = a[i].X - a[i].Y;
    c[i] = a[i].X; c[i + n] = a[i].Y;
  }
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  int m = c.size(); seg.resize(4 * m, {inf, 0}); vector<pii> rank(n);
  for (int i = 0; i < n; ++i) {
    rank[i].X = lower_bound(c.begin(), c.end(), a[i].X) - c.begin();
    rank[i].Y = lower_bound(c.begin(), c.end(), a[i].Y) - c.begin();
  }
  vector<int> dp(n, inf), cnt(n, 1); dp[0] = a[0].X;
  update(rank[0].X, dp[0], (1ll * cnt[0] * b[0]) % mod, 1, 0, m-1);
  for (int i = 1; i < n; ++i) {
    pii p = get(rank[i].Y, m-1, 1, 0, m-1);
    if (p.X == inf) {
      dp[i] = a[i].X; 
    } else {
      dp[i] = p.X + val[i]; 
      cnt[i] = p.Y;
    }
    update(rank[i].X, dp[i], (1ll * cnt[i] * b[i]) % mod, 1, 0, m-1);
  }
  int minval = *min_element(dp.begin(), dp.end()), res = 0;
  for (int i = 0; i < n; ++i) if (dp[i] == minval) res = (res + cnt[i]) % mod;
  cout << res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}