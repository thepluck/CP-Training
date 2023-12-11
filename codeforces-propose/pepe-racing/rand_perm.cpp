#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  int n; cin >> n;
  println(rnd.perm(n * n, 0));
}