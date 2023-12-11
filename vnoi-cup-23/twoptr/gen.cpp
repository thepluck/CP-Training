#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int t = 10, n = 10000;
  cout << t << '\n';
  while (t--) {
    vector<int> a = rnd.perm(n, 0);
    cout << n << '\n';
    for (int i = 0; i < n; i++)
      cout << a[i] << " \n"[i == n - 1];
  }
}