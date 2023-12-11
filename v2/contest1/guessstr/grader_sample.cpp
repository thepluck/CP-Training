#include "guessstr.h"
#include <iostream>

using namespace std;

int N, A, B, C;
string S;
int count_ask = 0;

int count_matching(string T) {
  count_ask++;
  int matching = 0;
  for (int i = 0; i < N; i++) {
    matching += S[i] == T[i];
  }
  return matching;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> S;
  for (int i = 0; i < N; i++) {
    A += S[i] == '0';
    B += S[i] == '1';
    C += S[i] == '2';
  }
  cout << guess_string(A, B, C) << '\n';
  cout << count_ask << '\n';
}
