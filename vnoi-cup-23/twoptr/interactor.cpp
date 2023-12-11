#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int T = 10'000;
const int N = 50'000;

int get_t() {
#ifdef LOCAL
  return 10;
#else
  return inf.readInt(1, T);
#endif
}

int get_n() {
#ifdef LOCAL
  return 10000;
#else
  return inf.readInt(1, N);
#endif
}

vector<int> get_a(int n) {
#ifdef LOCAL
  return rnd.perm(n, 0);
#else
  return inf.readInts(n, 0, n - 1);
#endif
}

void solve() {
  int n = get_n();
  vector<int> a = get_a(n);
  cout << n << endl;
  long long cost = 0;
  int p = 0, q = 0;
  while (true) {
    string cmd = ouf.readToken("?|!", "cmd");
    if (cmd == "!") {
      for (int i = 0; i < n; i++)
        if (a[i] != ouf.readInt(0, n - 1))
          quitf(_wa, "returned array is wrong");
      tout << cost << '\n';
      break;
    }
    int new_p = ouf.readInt(0, n - 1, "new_p");
    int new_q = ouf.readInt(0, n - 1, "new_q");
    cost += abs(p - new_p) + abs(q - new_q);
    p = new_p; q = new_q;
    cout << (a[p] < a[q]) << endl;
  }

}

int main(int argc, char **argv) {
  registerInteraction(argc, argv);
  int t = get_t();
  cout << t << endl;
  for (int tc = 1; tc <= t; tc++) {
    setTestCase(tc);
    solve();
  }
}