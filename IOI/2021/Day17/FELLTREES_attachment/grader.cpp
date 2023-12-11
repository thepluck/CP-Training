#include "felltrees.h"
#include <cassert>
#include <cstdio>
#include <vector>
// BEGIN SECRET
#include <string>
// END SECRET

using namespace std;

int main() {
  // BEGIN SECRET
  const std::string input_secret = "8774ab74bffd38d2f3dbe5c64a56b342";
  const std::string output_secret = "232b4eac3aa9d1d479ec41418ba89d85";
  char secret[1000];
  assert(1 == scanf("%s", secret));
  if (std::string(secret) != input_secret) {
    printf("%s\n", output_secret.c_str());
    printf("SV\n");
    fclose(stdout);
    return 0;
  }
  // END SECRET
  int n, q;
  assert(scanf("%d%d", &n, &q) == 2);
  vector<int> x(n), h(n), l(q), r(q);
  for (int i = 0; i < n; ++i) {
    assert(scanf("%d%d", &x[i], &h[i]) == 2);
  }
  for (int i = 0; i < q; ++i) {
    assert(scanf("%d%d", &l[i], &r[i]) == 2);
  }
  fclose(stdin);

  vector<int> answer = fell_trees(n, q, x, h, l, r);
  // BEGIN SECRET
  printf("%s\n", output_secret.c_str());
  // END SECRET
  for (size_t i = 0; i < answer.size(); ++i) {
    printf("%d\n", answer[i]);
  }
  fclose(stdout);

  return 0;
}
