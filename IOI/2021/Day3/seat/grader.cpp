#include <string>
#include <vector>
#include <iostream>
#include "seat.h"

int main() {
  int N, Q;
  std::vector<int> A, B, tB;
  std::string C;

  std::cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }
  std::cin >> C;
  
  std::cin >> Q;
  B.resize(Q);
  for (int i = 0; i < Q; i++) {
    std::cin >> B[i];
  }

  prepare(N, A, C, Q);
  for (int i = 0; i < Q; i++) {
    tB.push_back(B[i]);

    std::cout << query(tB) << (i == Q - 1 ? '\n' : ' ');
  }
}