#include "testlib.h"

using namespace std;

vector<string> types({"random", "greedy1", "greedy2"});

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  vector<int> ns;
  int sum_n3 = 0;
  for (int t = 1; t <= 10000; t++) {
    int n = rnd.next(2, 20);
    if (sum_n3 + n * n * n > 300000) continue;
    sum_n3 += n * n * n;
    ns.push_back(n);
  }
  cout << ns.size() << '\n';
  for (int n : ns) {
    cout << n << ' ' << 2 * n * n - 2 * n  + 1 << ' ' << rnd.any(types) << '\n';
  }
}