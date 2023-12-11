#include "network.h"

#include <stdio.h>
using namespace std;

int main() {
  int N, D, subtask;
  scanf("%d %d %d", &N, &D, &subtask);
  int x[N], y[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d %d", &x[i], &y[i]);
  }
  vector<int> res = getMaximumSubset(N, D, subtask, x, y);
  printf("%d\n", (int)res.size());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d", res[i]);
    printf(i == res.size() - 1 ? "\n" : " ");
  }
  return 0;
}
