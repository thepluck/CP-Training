#include "tree.h"
#include <cstdio>
#include <vector>

int main() {
  int N;
  scanf("%d", &N);
  
  std::vector<int> DFS(N), BFS(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &DFS[i]);
  }
  
  for (int i = 0; i < N; i++) {
    scanf("%d", &BFS[i]);
  }
  
  double average_height = count_average_height(N, DFS, BFS);
  printf("%.6lf\n", average_height);
}
