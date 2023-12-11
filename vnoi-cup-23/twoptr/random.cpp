#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

typedef struct item* pitem;

struct item {
  int prior, value, cnt;
  pitem l, r;

  item(int value): value(value), cnt(1) {
    prior = rand(0, 1e9);
    l = r = nullptr;
  }
};

int cnt(pitem it) {
  return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
  if (it) it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r) {
    t = l ? l : r;
  } else if (l->prior > r->prior) {
    merge(l->r, l->r, r); t = l;
  } else {
    merge(r->l, l, r->l); t = r;
  }
  upd_cnt(t);
}

void split(pitem t, pitem &l, pitem &r, int key, int add = 0) {
  if (!t) return void(l = r = 0);
  int cur_key = add + cnt(t->l);
  if (key <= cur_key) {
    split(t->l, l, t->l, key, add); r = t;
  } else {
    split(t->r, t->r, r, key, add + 1 + cnt(t->l)); l = t;
  }
  upd_cnt(t);
}

int get(pitem &t, int p) {
  pitem t1, t2, t3;
  split(t, t1, t2, p);
  split(t2, t2, t3, 1);
  int res = t2->value;
  merge(t, t1, t2);
  merge(t, t, t3);
  return res;
}

void insert(pitem &t, int p, int v) {
  pitem t1, t2;
  split(t, t1, t2, p);
  merge(t, t1, new item(v));
  merge(t, t, t2);

}

void trav(pitem t, vector<int> &p) {
  if (!t) return;
  trav(t->l, p);
  p.push_back(t->value);
  trav(t->r, p);
}

int ans[10005], p, q;
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

void solve() {
  p = q = cost = 0;
  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ans[i];
  vector<int> p, a(n);
  pitem root = nullptr;
  for (int i = 0; i < n; i++) {
    int l = 0, r = i;

    while (l < r) {
      int m = rand(l, r - 1);
      if (comp(i, get(root, m))) r = m;
      else l = m + 1;
    }
    insert(root, r, i);
  }
  trav(root, p);
  for (int i = 0; i < n; i++)
    a[p[i]] = i;
  answer(a);
}

int main() {
  cout << "\n";
  int t; cin >> t;
  while (t--) solve();
}