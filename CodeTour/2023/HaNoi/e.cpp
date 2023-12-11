#include <bits/stdc++.h>

using namespace std;

struct node {
  int cur = 0, mn = 0, mx = 0;
};

void add(const node &a, const node &b, node &res) {
  res.mn = min(a.mn, a.cur + b.mn);
  res.mx = max(a.mx, a.cur + b.mx);
  res.cur = a.cur + b.cur;
} 

const int N = 1e6 + 5;

string s;
node pre[N] ,suf[N];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m >> s;
  s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    node v;
    if (s[i] == '+') v.cur = v.mx = 1;
    else v.cur = v.mn = -1;
    add(pre[i - 1], v, pre[i]);
  }
  for (int i = n; i > 0; i--) {
    node v;
    if (s[i] == '+') v.cur = v.mx = 1;
    else v.cur = v.mn = -1;
    add(v, suf[i + 1], suf[i]);
  }
  while (m--) {
    int l, r; cin >> l >> r;
    node res; add(pre[l - 1], suf[r + 1], res);
    cout << res.mx - res.mn + 1 << '\n';
  }
}