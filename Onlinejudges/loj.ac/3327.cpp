#include <bits/stdc++.h>

using namespace std;

template<class X, class Y>
bool cmax(X &a, const Y &b) {
  return a < b ? a = b, 1 : 0;
}

template<class X, class Y>
bool cmin(X &a, const Y &b) {
  return a > b ? a = b, 1 : 0;
}

struct node {
  int val, cnt, tag;
};

const int N = 200005;

using ll = long long;

int a[N], n, k;
int cnt[N], mn[N], mx[N], lf[N], rg[N];
node seg[N * 4];

void build(int i, int l, int r) {
  seg[i] = {l, 1, 0};
  if (l != r) {
    int m = (l + r) / 2;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
  }
}

void update(int i, int l, int r, int x, int y, int v) {
  if (l >= x && r <= y) {
    seg[i].val += v; seg[i].tag += v; return;
  }
  int m = (l + r) / 2;
  if (m >= x) update(i * 2, l, m, x, y, v);
  if (m < y) update(i * 2 + 1, m + 1, r, x, y, v);
  seg[i].val = seg[i * 2].val;
  seg[i].cnt = seg[i * 2].cnt;
  if (seg[i].val > seg[i * 2 + 1].val) {
    seg[i].val = seg[i * 2 + 1].val;
    seg[i].cnt = seg[i * 2 + 1].cnt;
  } else if (seg[i].val == seg[i * 2 + 1].val)
    seg[i].cnt += seg[i * 2 + 1].cnt;
  seg[i].val += seg[i].tag;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  long long res = 0;
  build(1, 1, k);
  vector<int> inc, dec;
  inc.push_back(0); dec.push_back(0);
  for (int i = 1; i <= k; i++) {
    cin >> a[i]; cnt[a[i]] = 1;
    while (inc.size() > 1 && a[inc.back()] < a[i]) {
      update(1, 1, k, inc[inc.size() - 2] + 1,
      inc.back(), a[i] - a[inc.back()]);
      inc.pop_back();
    }
    while (dec.size() > 1 && a[dec.back()] > a[i]) {
      update(1, 1, k, dec[dec.size() - 2] + 1,
      dec.back(), a[dec.back()] - a[i]);
      dec.pop_back(); 
    }
    inc.push_back(i); dec.push_back(i);
    res += seg[1].cnt;
  }
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) continue;
    int j = i;
    while (j <= n && !cnt[j]) j++;
    res += 1ll * (j - i) * (j - i + 1) / 2;
    rg[i] = lf[j - 1] = j - i;
    i = j;
  }
  for (int i = 1; i <= n; i++)
    cnt[i] += cnt[i - 1];
  mn[k] = mx[k] = a[k];
  for (int i = k - 1; i > 0; i--) {
    mx[i] = max(mx[i + 1], a[i]);
    mn[i] = min(mn[i + 1], a[i]);
  }
  vector<int> pos;
  for (int i = k + 1; i > 1; ) {
    int j = i - 1;
    while (cnt[mx[j]] - cnt[mn[j] - 1] != k - j + 1) j--;
    pos.push_back(j);
    if (mx[j] - mn[j] != k - j) res++;
    i = j;
  }
  bool happen = false;
  for (int i = 0; i < pos.size(); ) {
    int best = 1, x = i, y = i + 1;
    int banana = 0;
    while (y < pos.size() && mx[pos[y]] == mx[pos[i]]) {
      if (mn[pos[x]] - mn[pos[y]] - (pos[x] - pos[y]) == lf[mn[pos[x]] - 1]) {
        best = max(best, y - x + 1); y++;
      } else {
        happen = true;
        x = max(x + 1, y - 1); y = x + 1;
        banana++;
      }
    }
    res += 1ll * rg[mx[pos[i]] + 1] * best;
    i = y;
    if (banana >= 3) happen = true;
  }
  for (int i = 0; i < pos.size(); ) {
    int best = 1, x = i, y = i + 1;
    int banana = 0;
    while (y < pos.size() && mn[pos[y]] == mn[pos[i]]) {
      if (mx[pos[y]] - mx[pos[x]] - (pos[x] - pos[y]) == rg[mx[pos[x]] + 1]) {
        best = max(best, y - x + 1); y++;
      } else {
        happen = true;
        x = max(x + 1, y - 1); y = x + 1;
        banana++;
      }
    }
    res += 1ll * lf[mn[pos[i]] - 1] * best;
    i = y;
    if (banana >= 3) happen = true;
  }
  cout << res << '\n';
}
