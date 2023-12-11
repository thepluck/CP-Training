#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int sum_n = opt<int> ("sum_n");
  int min_n = opt<int> ("min_n");
  int test = opt<int> ("test");
  int swap_bias = opt<int> ("swap_bias");
  int rev_bias = opt<int> ("rev_bias");
  vector<int> ns = rnd.partition(test, sum_n, min_n);
  cout << test << '\n';
  for (int n : ns) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    for (int s = 0; s < swap_bias; s++)
      swap(p[rnd.next(n)], p[rnd.next(n)]);
    if (rev_bias) reverse(p.begin(), p.end());
    cout << n << '\n';
    for (int i = 0; i < n; i++)
      cout << p[i] << " \n"[i == n - 1];
  }
}
