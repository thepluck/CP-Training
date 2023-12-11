#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int sumn = opt<int> ("sumn");
  int test = opt<int> ("test");
  vector<int> ns = rnd.partition(test, sumn);
  cout << test << '\n';
  for (int n : ns) {
    cout << n << '\n';
  }
}