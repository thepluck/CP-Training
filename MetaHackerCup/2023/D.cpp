#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 5;
const int MOD = 1e9 + 7;

pair<int, int> mx[N * 2], mn[N * 2];
int a[N];
bool flip[N * 2];

#define il i + 1
#define ir i + (m - l + 1) * 2

void build(int i, int l, int r) {
  flip[i] = 0;
  if (l == r) {
    mx[i] = {a[l], -l};
    mn[i] = {MOD - (a[l] ? a[l] : MOD), -l};
    return;
  }
  int m = (l + r) / 2;
  build(il, l, m);
  build(ir, m + 1, r);
  mx[i] = max(mx[il], mx[ir]);
  mn[i] = max(mn[il], mn[ir]);
}

void update(int i, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) {
    swap(mn[i], mx[i]);
    flip[i] ^= 1;
    return;
  }
  int m = (l + r) / 2;
  if (m >= ql)
    update(il, l, m, ql, qr);
  if (m < qr)
    update(ir, m + 1, r, ql, qr);
  mx[i] = max(mx[il], mx[ir]);
  mn[i] = max(mn[il], mn[ir]);
  if (flip[i])
    swap(mn[i], mx[i]);
}

void solve() {
  int n;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    update(1, 1, n, l, r);
    res += mx[1].second;
  }
  cout << -res << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  /// meta hacker cup
  for (int tc = 1; tc <= t; tc++) {
    cout << "Case #" << tc << ": ";
    solve();
  }
}