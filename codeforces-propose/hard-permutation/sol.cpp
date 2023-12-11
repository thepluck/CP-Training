#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 500005;
const int LOG = 19;

int n, a[N], pos[N];
int lef[N], rig[N];

vector<int> st_max, st_min;

void connect(int x, int y) {
  rig[x] = y; lef[y] = x;
}

struct range_min {
  vector<int> spt[LOG];
  
  void build() {
    for (int k = 0; k < LOG; k++)
      spt[k].resize(n + 1);
    for (int i = 1; i <= n; i++)
      spt[0][i] = pos[i];
    for (int k = 1; k < LOG; k++)
      for (int i = 1; i + (1 << k) <= n + 1; i++) {
        spt[k][i] = min(spt[k - 1][i],
        spt[k - 1][i + (1 << (k - 1))]);
      }
  }
  
  int get_min_pos(int l, int r) {
    int k = __lg(r - l + 1);
    return min(spt[k][l], spt[k][r - (1 << k) + 1]);
  }
} rmq;

int get_min(int i) {
  return a[*lower_bound(st_min.begin(), st_min.end(), i)];
}

int get_max(int i) {
  return a[*lower_bound(st_max.begin(), st_max.end(), i)];
}

struct segtree1 {
#define il i * 2
#define ir i * 2 + 1
  struct node {
    int val, cnt, tag;
  };
  
  node tree[N * 4];
  
  void build(int i, int l, int r) {
    tree[i] = {l, 1, 0};
    if (l < r) {
      int m = (l + r) / 2;
      build(il, l, m);
      build(ir, m + 1, r);
    }
  }
  
  void add(int i, int l, int r, int x, int y, int v) {  
    if (l >= x && r <= y) {
      tree[i].val += v; tree[i].tag += v; return;
    }

    int m = (l + r) / 2;
    if (m >= x) add(il, l, m, x, y, v);
    if (m < y) add(ir, m + 1, r, x, y, v);
  
    tree[i].val = tree[il].val;
    tree[i].cnt = tree[il].cnt;

    if (tree[i].val > tree[ir].val) {
      tree[i].val = tree[ir].val;
      tree[i].cnt = tree[ir].cnt;
    } else if (tree[i].val == tree[ir].val)
      tree[i].cnt += tree[ir].cnt;

    tree[i].val += tree[i].tag;
  }
#undef il
#undef ir
} seg1;

struct copium {
  int curr, maxx, type;
  
  copium() {}
  
  copium(int curr, int maxx, int type):
  curr(curr), maxx(max(maxx, curr)), type(type) {}
};

copium lmin[N], lmax[N];
ll prefix, middle, suffix;

/// cancer
void calc(int i, int j, bool recalc) {
  int imin = get_min(i), imax = get_max(i);
  int jmin = get_min(j), jmax = get_max(j);
  int type;
  if (recalc) {
    middle -= 1ll * lmax[j].maxx * (rig[jmax] - jmax - 1);
    middle -= 1ll * lmin[j].maxx * (jmin - lef[jmin] - 1);
  }
  
  if (imax == jmax) {
    if (!recalc)
      middle -= 1ll * lmax[i].maxx * (rig[imax] - imax - 1);
      
    if (jmin - imin == j - i) type = 0;
    else if (imin + j - i == lef[jmin] + 1) type = 1;
    else type = 2;
    
    if (type == 2) lmax[j] = copium(1, lmax[i].maxx, type);
    else if (lmax[i].type == 0)
      lmax[j] = copium(lmax[i].curr + 1, lmax[i].maxx, type);
    else lmax[j] = copium(2, lmax[i].maxx, type);
    
  } else lmax[j] = {1, 1, 3};
  if (imin == jmin) {
    if (!recalc)
      middle -= 1ll * lmin[i].maxx * (imin - lef[imin] - 1);
      
    if (imax - jmax == j - i) type = 0;
    else if (imax + i - j == rig[jmax] - 1) type = 1;
    else type = 2;
    
    if (type == 2) lmin[j] = copium(1, lmin[i].maxx, type);
    else if (lmin[i].type == 0)
      lmin[j] = copium(lmin[i].curr + 1, lmin[i].maxx, type);
    else lmin[j] = copium(2, lmin[i].maxx, type);
    
  } else lmin[j] = {1, 1, 3};
  
  middle += 1ll * lmax[j].maxx * (rig[jmax] - jmax - 1);
  middle += 1ll * lmin[j].maxx * (jmin - lef[jmin] - 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; pos[a[i]] = i;
      lef[i] = rig[i] = 0;
    }
    
    st_min.assign(1, 0);
    st_max.assign(1, 0);
    
    set<int> sorted;
    sorted.insert(0);
    sorted.insert(n + 1);
    
    prefix = 0;
    suffix = 1ll * n * (n + 1) / 2;
    middle = 0;
    
    // k = 0
    cout << suffix << ' ';
    
    lef[n] = 0; rig[0] = n;
    
    seg1.build(1, 1, n); rmq.build();
    
    vector<int> good;
    
    for (int i = 1; i <= n; i++) {
      
      while (good.size()) { 
        int j = good.back();
        int jmin = get_min(j), jmax = get_max(j);
        
        if (rmq.get_min_pos(min(jmin, a[i]), max(jmax, a[i])) < j) {
          middle -= 1ll * lmax[j].maxx * (rig[jmax] - jmax - 1);
          middle -= 1ll * lmin[j].maxx * (jmin - lef[jmin] - 1);
          good.pop_back();
          if (good.size()) {
            if (lmax[j].type < 3)
              middle += 1ll * lmax[good.back()].maxx * (rig[jmax] - jmax - 1);
            if (lmin[j].type < 3)
              middle += 1ll * lmin[good.back()].maxx * (jmin - lef[jmin] - 1);
          }
        } else break;
      }
      
      if (good.size()) {
        int j = good.back();
        int jmin = get_min(j), jmax = get_max(j);
        middle -= 1ll * lmax[j].maxx * (rig[jmax] - jmax - 1);
        middle -= 1ll * lmin[j].maxx * (jmin - lef[jmin] - 1); 
      }
      
      auto it = sorted.upper_bound(a[i]);
      suffix -= 1ll * (*it - a[i]) * (a[i] - *prev(it));
      connect(*prev(it), a[i]); connect(a[i], *it);
      sorted.insert(a[i]);
      
      while (st_max.size() > 1 && a[st_max.back()] < a[i]) {
        seg1.add(1, 1, n, st_max[st_max.size() - 2] + 1,
        st_max.back(), a[i] - a[st_max.back()]);
        st_max.pop_back();
      }
      
      while (st_min.size() > 1 && a[st_min.back()] > a[i]) {
        seg1.add(1, 1, n, st_min[st_min.size() - 2] + 1,
        st_min.back(), a[st_min.back()] - a[i]);
        st_min.pop_back(); 
      }
      
      st_max.push_back(i); st_min.push_back(i);
      
      if (good.size()) {
        int j = good.back();
        int jmin = get_min(j), jmax = get_max(j);
        middle += 1ll * lmax[j].maxx * (rig[jmax] - jmax - 1);
        middle += 1ll * lmin[j].maxx * (jmin - lef[jmin] - 1); 
        calc(j, i, 0);
      } else {
        lmax[i] = lmin[i] = {1, 1, 3};
        middle += rig[a[i]] - lef[a[i]] - 2;
      }

      good.push_back(i);
      if (st_min.size() >= 2) {
        int k = upper_bound(good.begin(), good.end(),
        st_min[st_min.size() - 2]) - good.begin();
        if (k > 0 && k < good.size())
          calc(good[k - 1], good[k], 1);
      }
      if (st_max.size() >= 2) {
        int k = upper_bound(good.begin(), good.end(),
        st_max[st_max.size() - 2]) - good.begin();
        if (k > 0 && k < good.size())
          calc(good[k - 1], good[k], 1);
      }
      
      cout << prefix + good.size() + middle + suffix << ' ';
      
      prefix += seg1.tree[1].cnt; 
    }
    cout << '\n';
  }
}
