#include "gen-type.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  double bias_tree = opt<double> ("bias-tree");
  int test_count = opt<int> ("test-count");
  string tree_type = opt <string>("tree-type");
  vector<int> ns = rnd.partition(test_count, 500000, 1);
  cout << test_count << '\n';
  for (int n : ns) {
    print_parents(random_tree(n, convert(-n, n, bias_tree), tree_type));
  }
}
 