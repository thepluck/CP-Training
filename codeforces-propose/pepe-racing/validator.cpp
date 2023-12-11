#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerValidation(argc, argv);
  int t = inf.readInt(1, 10'000, "t");
  inf.readEoln();
  int sum_n3 = 0;
  for (int tc = 1; tc <= t; tc++) {
    setTestCase(tc);
    int n = inf.readInt(1, 20, "n");
    sum_n3 += n * n * n;
    ensuref(sum_n3 <= 300'000, "Sum of n^3 must not greater than 300000");
    inf.readSpace();
    int q = 2 * n * n - 2 * n + 1;
    q = inf.readInt(q, q, "q");
    inf.readSpace();
    string type = inf.readToken("manual|random", "type");
    inf.readEoln();
    if (type == "manual") {
      vector<int> a(n * n);
      for (int i = 0; i < n * n; i++) {
        a[i] = inf.readInt(0, n * n - 1, "a[i]");
        if (i == n * n - 1) inf.readEoln();
        else inf.readSpace();
      }
      sort(a.begin(), a.end());
      for (int i = 0; i < n * n; i++)
        ensuref(a[i] == i, "The array a is not a permutation of size %d x %d", n);
    }
  }
  inf.readEof();
}