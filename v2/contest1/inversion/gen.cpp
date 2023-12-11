#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int sub = opt<int> ("sub");
  string type = opt<string> ("type");
  int n;
  if (sub == 1) n = rnd.next(95, 100);
  else if (sub == 2) n = rnd.next(495, 500);
  else if (sub == 3) n = rnd.next(1995, 2000);
  else n = rnd.next(4995, 5000);
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    a[i] = i;
  if (type == "inc") {
  } else if (type == "dec") {
    reverse(a.begin(), a.end());
  } else {
    int num = rnd.wnext(20, n, opt<int> ("bias"));
    while (num--) {
      swap(a[rnd.next(n)], a[rnd.next(n)]);
    }
  }
  cout << n << '\n';
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
}