#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int n = opt<int> ("n");
  int t = min(10000, 300000 / (n * n * n));
  cout << t << '\n';
  while (t--) {
    string type = "manual";
    cout << n << ' ' << 2 * n * n - 2 * n + 1 << ' ' << type << '\n';
    vector<int> a = rnd.perm(n * n, 0);
    for (int i = 0; i < n * n; i++)
      cout << a[i] << " \n"[i == n * n - 1];
  }
}