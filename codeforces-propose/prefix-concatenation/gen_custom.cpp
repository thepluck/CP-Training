#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

struct dsu {
  vector<int> par;
  
  dsu(int n): par(n, -1) {}
  
  int root(int u) {
    return par[u] < 0 ? u : par[u] = root(par[u]);
  }
  
  bool join(int u, int v) {
    u = root(u); v = root(v);
    return u != v ? par[v] = u, 1 : 0;
  }
};

void join(int l, int r, int k, vector<dsu> &dsus) {
  if (dsus[k].join(l, r) && k > 0) {
    join(l, r, k - 1, dsus);
    join(l + (1 << (k - 1)), r + (1 << (k - 1)), k - 1, dsus);
  }
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int positive = opt<int> ("positive");
  string type = opt<string> ("type");
  int patt = opt<int> ("patt");
  vector<int> ns;
  if (type == "long") {
    ns = rnd.partition(rnd.next(10, 20), 1000000 / patt, 10000 / patt);
  } else ns.push_back(1e6 / patt);
  cout << ns.size() << '\n';  
  for (int n : ns) {
    auto pos = rnd.perm(n - 1, 1);
    vector<dsu> dsus(20, n);
    for (int i = 0; i < min(n - 1, positive); i++) {
      int len = rnd.next(n - pos[i]) + 1;
      int l = 0, r = pos[i];
      for (int k = 0; k < 20; k++)
        if (len >> k & 1) join(l, r, k, dsus);
    }
    vector<string> s(n);
    for (int i = 0; i < n; i++)
      if (dsus[0].par[i] < 0)
        s[i] = rnd.next("[a-z]{%d, %d}", patt, patt);
    for (int i = 0; i < n; i++)
      s[i] = s[dsus[0].root(i)];
    reverse(s.begin(), s.end());
    cout << n * patt << '\n';
    for (string ss : s) cout << ss;
    cout << '\n';
  }
}