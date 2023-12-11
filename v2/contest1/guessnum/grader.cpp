#include "guessnum.h"
#include <iostream>

using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    cout << count_pair(n) << '\n';
  }
}