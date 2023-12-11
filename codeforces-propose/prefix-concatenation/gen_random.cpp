#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

string gen(int n, string &chr, int alpha) {
  shuffle(chr.begin(), chr.end());
  string s;
  for (int i = 0; i < n; i++)
    s.push_back(chr[rnd.next(alpha)]);
  return s;
}

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  string type = opt<string> ("type");
  int alpha = opt<int> ("alpha");
  string chr(26, 'a');
  for(int i = 0; i < 26; i++)
    chr[i] = 'a' + i;
  vector<int> ns;
  if (type == "many") {
    ns = rnd.partition(rnd.next(1000, 10000), 1000000, 10);
  } else if (type == "long") {
    ns = rnd.partition(rnd.next(10, 20), 1000000, 10000);
  } else if (type == "full") {
    ns.push_back(1000000);
  }
  cout << ns.size() << '\n';
  for (int n : ns)
    cout << n << '\n' << gen(n, chr, alpha) << '\n';
}