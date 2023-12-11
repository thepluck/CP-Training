#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  vector<pair<int, int>> all;
  for (int i = 2; i <= 100; i++)
    for (int j = 1; j < i; j++)
      all.emplace_back(i, j);
  int test = opt<int> ("test");
  int start = test * 100;
  int finish = min((test + 1) * 100, int(all.size()));
  cout << finish - start << '\n';
  for (int i = start; i < finish; i++)
    cout << all[i].first << ' ' << all[i].second << '\n';
}