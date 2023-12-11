#include "guessstr.h"
#include <iostream>

using namespace std;

int N, A, B, C; string S;
int count_ask = 0;

void wa(string msg) {
  cout << "WA\n" << msg << '\n';
  exit(0);
}

void ok() {
  cout << "OK\n" << count_ask << '\n';
}

int count_matching(string T) {
  count_ask++;
  if (count_ask > 10000) {
    wa("query limit exceeded");
  }
  if (int(T.size()) < N) {
    wa("length of T must equals to N");
  }
  int TA = 0, TB = 0, TC = 0;
  int matching = 0;
  for (int i = 0; i < N; i++) {
    TA += T[i] == '0';
    TB += T[i] == '1';
    TC += T[i] == '2';
    matching += S[i] == T[i];
  }
  if (TA != A) {
    wa("number of letters 0 must equals to A");
  }
  if (TB != B) {
    wa("number of letters 1 must equals to B");
  }
  if (TC != C) {
    wa("number of letters 2 must equals to C");
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
  if (guess_string(A, B, C) != S)
    wa("returned string is wrong");
  ok();
}