#include "matching.h"
#include <cstdio>
#include <vector>

int main() {
  int N, M, A, B;
  scanf("%d%d%d%d", &N, &M, &A, &B);
  std::vector<int> U(M), V(M);
  for(int i = 0; i < M; ++i) {
    scanf("%d%d", &U[i], &V[i]);
  }
  int ans = count_matching(N, M, A, B, U, V);
  printf("%d\n", ans);
  return 0;
}
