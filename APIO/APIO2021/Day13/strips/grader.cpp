#include "strips.h"

#include <stdio.h>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);
  std::vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    scanf("%d", &C[i]);
  }
  printf("%d\n", getMaximumLength(N, C));
}
