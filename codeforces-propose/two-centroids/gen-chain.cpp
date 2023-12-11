#include "gen-type.h"

using namespace std;

vector<string> tree_type({"normal", "binary", "caterpillar", "sperm"});

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  cout << 1 << '\n';
  int length = opt<int> ("length");
  int n = 500000;
  double bias_tree = opt<double> ("bias-tree");
  vector<int> cmps;
  if (length != 2) {
    cmps = max_partition(length, n, max(1, n / length - 20), n / length + 20);
  } else {
    cmps = vector<int> (2, n / 2);
    tree_type = {"sperm"};
  }
  int offset = 0;
  vector<pair<int, int>> edges;
  for (int siz : cmps) {
    auto sub_edge = random_tree(siz, convert(-siz, siz, bias_tree), rnd.any(tree_type));
    for (auto [u, v] : sub_edge)
      edges.emplace_back(u + offset, v + offset);
    offset += siz;
  }
  offset = 0;
  for (int i = 0; i + 1 < cmps.size(); i++) {
    edges.emplace_back(rnd.next(cmps[i]) + offset,
    rnd.next(cmps[i + 1]) + offset + cmps[i]);
    offset += cmps[i];
  }
  
  print_parents(edges);
}
 