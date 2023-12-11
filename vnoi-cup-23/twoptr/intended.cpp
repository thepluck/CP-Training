#include <bits/stdc++.h>

using namespace std;

namespace hilbert {
  constexpr int logn = 14;
  constexpr int maxn = 1 << logn;

  long long get_order(int x, int y) {
    long long d = 0;
    for (int s = 1 << (logn - 1); s; s >>= 1) {
      bool rx = x & s, ry = y & s;
      d = d << 2 | rx * 3 ^ static_cast<int>(ry);
      if (!ry) {
        if (rx) {
          x = maxn - x;
          y = maxn - y;
        }
        swap(x, y);
      }
    }
    return d;
  }
};

int ans[10005], p, q;
int pos[10005], min_pos[10005];
long long cost;

bool comp(int i, int j) {
  // cout << "? " << i << ' ' << j << endl;
  // int res; cin >> res; return res;
  cost += abs(i - p) + abs(j - q);
  p = i; q = j;
  return ans[p] < ans[q];
}

void answer(vector<int> a) {
  // cout << "!";
  // for (int i = 0; i < a.size(); i++)
  //   cout << ' ' << a[i];
  // cout << endl;
  for (int i = 0; i < a.size(); i++)
    if (a[i] != ans[i]) {
      cout << "WA\n"; return;
    }
  cout << "OK " << cost << '\n';
}

struct query {
  int l, r; bool inv;
  long long order;

  query(int l, int r): l(l), r(r), inv(0) {
    if (l > r) {
      swap(this->l, this->r); inv = 1;
    }
    order = hilbert::get_order(this->l, this->r);
  }

  bool excute() {
    if (inv) {
      swap(l, r); return 1 - comp(r, l);
    }
    return comp(l, r);
  }
};

vector<int> merge(vector<int> x, vector<int> y, int l, int r) {
  if (x.empty()) return y;
  if (y.empty()) return x;
  int k = sqrt(r - l);
  vector<int> z;
  for (int i = 1; i < x.size(); i += 2)
    z.push_back(x[i]);
  y = merge(y, z, l, r);
  vector<query> que;
  for (int i = 0, j = 0; i < x.size(); i += 2, j++) {
    if (i + 1 < x.size()) {
      while (y[j] != x[i + 1])
        que.emplace_back(x[i], y[j++]);
    } else {
      while (j < y.size())
        que.emplace_back(x[i], y[j++]);
    }
  }
  for (int i = 0; i < y.size(); i++)
    pos[y[i]] = i;
  for (int i = 0; i < x.size(); i += 2)
    min_pos[x[i]] = i + 1 < x.size() ? pos[x[i + 1]] : y.size();
  sort(que.begin(), que.end(), [&](query a, query b) {
    if (a.l / k != b.l / k) return a.l < b.l;
    return a.l / k & 1 ? a.r < b.r : a.r > b.r;
  });
  for (query q : que)
    if (q.excute())
      min_pos[q.l] = min(min_pos[q.l], pos[q.r]);
  z.clear();
  for (int i = 0, j = 0; i < x.size(); i += 2) {
    while (j < min_pos[x[i]])
      z.push_back(y[j++]);
    z.push_back(x[i]);
    if (i + 2 >= x.size()) {
      while (j < y.size())
        z.push_back(y[j++]);
    }
  }
  return z;
}

vector<int> solve(int l, int r) {
  if (l + 1 == r) return vector<int> (1, l);
  int m = (l + r) / 2;
  return merge(solve(l, m), solve(m, r), l, r);
}

void solve() {
  p = q = cost = 0;
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ans[i];
  vector<int> a(n), p = solve(0, n);
  for (int i = 0; i < n; i++)
    a[p[i]] = i;
  answer(a);
}

int main() {
  cout << "\n";
  int t; cin >> t;
  while (t--) solve();
}