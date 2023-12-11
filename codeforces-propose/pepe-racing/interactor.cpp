#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;

const int MAX_N = 20;
const int MAX_SIZE = MAX_N * MAX_N;
 
bitset<MAX_SIZE> les[MAX_SIZE];
int n, q;
int buc_cnt[MAX_SIZE];
/// cnt greater
bitset<MAX_SIZE> rmv, temp1, temp2;
int cnt_unique[MAX_SIZE];

/// a[u] < a[v]
void add_edge(int u, int v) {
  if (rmv[v]) return;
  for (int x = 0; x < n * n; x++)
    if (les[x][u]) {
      temp1 = les[x] ^ rmv;
      temp1[x] = 0;
      int cnt1 = temp1.count();
      les[x] |= les[v];
      temp2 = les[x] ^ rmv;
      temp2[x] = 0;
      int cnt2 = temp2.count();
      if (cnt1 == 0 && cnt2 == 1)
        cnt_unique[temp2._Find_first()]++;
      if (cnt1 == 1 && cnt2 > 1)
        cnt_unique[temp1._Find_first()]--;
    }
}
 
bool is_distinct(vector<int> v) {
  static int occ[MAX_SIZE], cnt;
  
  cnt++;
  for (int x : v) {
    if (occ[x] == cnt) {
      return false;
    }
    occ[x] = cnt;
  }
  return true;
}
 
int get_max_manual(vector<int> v, const vector<int> &a) {
  int p = v[0];
  for (int i = 1; i < n; i++)
    if (a[v[i]] > a[p]) p = v[i];
  return p;
}

void manual_case() {
  int asked = 0;
  vector<int> a(n * n), ans(n * n);
  for (int i = 0; i < n * n; i++) {
    a[i] = inf.readInt(0, n * n - 1, "a[i]");
    ans[i] = i;
  }
  sort(ans.begin(), ans.end(), [&](int i, int j) {
    return a[i] > a[j];
  });
  while (true) {
    string cmd = ouf.readToken("?|!");
    if (cmd == "?") {
      asked++;
      quitif(asked > q, _wa, "Query limit exceeded");
      vector<int> v(n);
      for (int i = 0; i < n; i++) {
        v[i] = ouf.readInt(0, n * n - 1, "v[i]");
      }
      quitif(!is_distinct(v), _wa, "The array v is not distinct.");
      cout << get_max_manual(v, a) << endl;
    } else {
      for (int i = 0; i < n * n - n + 1; i++) {
        int x = ouf.readInt(0, n * n - 1, "ans[i]");
        quitif(x != ans[i], _wa, "The array ans is wrong");
      }
      break;
    }
  }
}

void process(int pepe1, vector<int> v) {
  for (int pepe2 : v)
    if (pepe2 != pepe1)
      add_edge(pepe2, pepe1);
  buc_cnt[pepe1]++;
  if (rmv[pepe1]) return;
  for (int pepe2 = 0; pepe2 < n * n; pepe2++)
    if (!les[pepe1][pepe2] && !les[pepe2][pepe1])
      return;
  rmv[pepe1] = true;
  for (int pepe2 = 0; pepe2 < n * n; pepe2++)
    if (les[pepe2][pepe1]) {
      temp1 = les[pepe2] ^ rmv;
      temp1[pepe2] = 0;
      if (temp1.count() == 1)
        cnt_unique[temp1._Find_first()]++;
    }
}

int get_max_random(vector<int> v) {
  vector<int> can;
  for (int pepe1 : v) {
    bool good = true;
    for (int pepe2 : v)
      if (pepe2 != pepe1 && les[pepe1][pepe2]) {
        good = false; break;
      }
    if (good) can.push_back(pepe1);
  }
  quitif(can.empty(), _fail, "Why was I supposed to write this shit.");
  int pepe1 = rnd.any(can);
  process(pepe1, v);
  return pepe1;
}

/// use when some buckets overlap
/// fuck you
int get_max_greedy1(vector<int> v) {
  int max_buc_cnt = -1;
  vector<int> can;
  for (int pepe1 : v) {
    bool good = true;
    for (int pepe2 : v)
      if (pepe2 != pepe1 && les[pepe1][pepe2]) {
        good = false; break;
      }
    if (good) {
      if (buc_cnt[pepe1] > max_buc_cnt) {
        max_buc_cnt = buc_cnt[pepe1];
        can.clear();
      }
      if (buc_cnt[pepe1] == max_buc_cnt) {
        can.push_back(pepe1);
      }
    }
  }
  int pepe1 = rnd.any(can);
  process(pepe1, v);
  return pepe1;
}

/// fuck you
int get_max_greedy2(vector<int> v) {
  int max_cnt_unique = -1;
  vector<int> can;
  for (int pepe1 : v) {
    bool good = true;
    for (int pepe2 : v)
      if (pepe2 != pepe1 && les[pepe1][pepe2]) {
        good = false; break;
      }
    if (good) {
      if (cnt_unique[pepe1] > max_cnt_unique) {
        max_cnt_unique = cnt_unique[pepe1];
        can.clear();
      }
      if (cnt_unique[pepe1] == max_cnt_unique) {
        can.push_back(pepe1);
      }
    }
  }
  int pepe1 = rnd.any(can);
  process(pepe1, v);
  return pepe1;
}

int get_max(string type, vector<int> v) {
  if (type == "random") return get_max_random(v);
  if (type == "greedy1") return get_max_greedy1(v);
  return get_max_greedy2(v);
}

void strategy(string type) {
  int asked = 0;
  vector<int> ans;
  vector<char> occ(n * n);
  rmv.reset();
  for (int pepe = 0; pepe < n * n; pepe++) {
    les[pepe].reset();
    les[pepe][pepe] = true;
    buc_cnt[pepe] = cnt_unique[pepe] = 0;
  }
  while (true) {
    string cmd = ouf.readToken("?|!");
    if (cmd == "?") {
      asked++;
      quitif(asked > q, _wa, "Query limit exceeded");
      vector<int> v(n);
      for (int i = 0; i < n; i++) {
        v[i] = ouf.readInt(0, n * n - 1, "v[i]");
      }
      quitif(!is_distinct(v), _wa, "The array v is not distinct.");
      cout << get_max(type, v) << endl;
    } else {
      for (int i = 0; i < n * n - n + 1; i++) {
        ans.push_back(ouf.readInt(0, n * n - 1, "ans[i]"));
        occ[ans.back()] = true;
      }
      for (int i = 1; i < int(ans.size()); i++)
        quitif(!les[ans[i]][ans[i - 1]], _wa, "The array ans is wrong at index %d", i - 1);
      
      for (int pepe = 0; pepe < n * n; pepe++)
        quitif(!occ[pepe] && !les[pepe][ans.back()], _wa, "The array ans is wrong at index %d", int(ans.size()) - 1);
      break;
    }
  }
}
 
int main(int argc, char **argv) {
  registerInteraction(argc, argv);
  int t = inf.readInt(1, 10000, "t");
  cout << t << endl;
  for (int tc = 1; tc <= t; tc++) {
    setTestCase(tc);
    n = inf.readInt(1, 20, "n");
    q = 2 * n * n - 2 * n + 1;
    cout << n << endl;
    string type = inf.readToken("manual|random|greedy1|greedy2", "type");
    
    if (type == "manual") manual_case();
    else strategy(type);
  }
  quitf(_ok, "Accepted");
}
