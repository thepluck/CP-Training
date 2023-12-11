#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
template <class X, class Y>
bool maximize(X &a, const Y &b) {
  return a < b ? a = b, 1 : 0;
}
 
 
template<class T>
using ordered_set = tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;
 
const int N = 200005;
 
int n, q, position[N], weight[N];
 
int nearest_left[N], nearest_right[N];
 
ordered_set<pair<char, int>> group[N];
int group_index[N], group_position[N];
int num_group;
 
 
string direction;
 
/// find nearest ant that heavier than query ant and have opposite direction
struct hld {
  int depth[N], parent[N], head[N];
  
  vector<int> adjacency[N];
  
  set<pair<int, int>> chain[N];
  
  void add_edge(int u, int v) {
    assert(weight[u] >= weight[v]);
    adjacency[u].push_back(v);
    parent[v] = u;
  }
 
  int dfs_prepare(int u) {
    int heavy = 0, total = 1;
    for (int &v : adjacency[u]) {
      depth[v] = depth[u] + 1;
      int current = dfs_prepare(v);
      total += current;
      if (maximize(heavy, current))
        swap(v, adjacency[u][0]);
    }
    return total;
    /// first child of u is the biggest
  }
  
  void dfs_decompose(int u) {
    if (parent[u] && u == adjacency[parent[u]][0])
      head[u] = head[parent[u]];
    else head[u] = u;
    for (int v : adjacency[u])
      dfs_decompose(v);
  }
  
  void erase(int u) {
    chain[head[u]].erase({depth[u], u});
  }
  
  void insert(int u) {
    chain[head[u]].insert({depth[u], u});
  }
  
  int ancestor(int u) {
    int v = u;
    while (v) {
      v = head[v];
      if (chain[v].size() && chain[v].begin()->first <= depth[u]) {
        int t = prev(chain[v].upper_bound({depth[u], u}))->second;
        return prev(chain[v].upper_bound({depth[u], u}))->second;
      }
      u = v = parent[v];
    }
    return 0;
  }
  
  void prepare() {
    for (int u = 1; u <= n; u++)
      if (!parent[u]) dfs_prepare(u);
    for (int u = 1; u <= n; u++)
      if (!parent[u]) dfs_decompose(u);
  }
} tree_left, tree_right;
 
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> q;
 
  for (int i = 1; i <= n; i++)
    cin >> position[i];
  for (int i = 1; i <= n; i++)
    cin >> weight[i];
 
  cin >> direction;
  direction = " " + direction;
 
  vector<int> decrease;
  for (int i = 1; i <= n; i++) {
    while (decrease.size() && weight[decrease.back()] < weight[i])
      decrease.pop_back();
      
    if (decrease.size()) tree_left.add_edge(decrease.back(), i);
    
    if (decrease.size() && weight[decrease.back()] == weight[i]) {
      group_index[i] = group_index[decrease.back()];
      group_position[i] = group_position[decrease.back()] + 1;
    } else group_index[i] = ++num_group;
    
    while (decrease.size() && weight[decrease.back()] <= weight[i])
      decrease.pop_back();
    
    if (decrease.size()) nearest_left[i] = decrease.back();
      
    decrease.push_back(i);
 
  }
  
  decrease.clear();
  for (int i = n; i > 0; i--) {
    while (decrease.size() && weight[decrease.back()] < weight[i])
      decrease.pop_back();
 
    if (decrease.size()) tree_right.add_edge(decrease.back(), i);
 
    while (decrease.size() && weight[decrease.back()] <= weight[i])
      decrease.pop_back();
      
    if (decrease.size()) nearest_right[i] = decrease.back();
    
    decrease.push_back(i);
  }
  
  tree_left.prepare(); tree_right.prepare();
  
  for (int i = 1; i <= n; i++) {
    group[group_index[i]].insert({direction[i], i});
    if (direction[i] == 'L') tree_right.insert(i);
    else tree_left.insert(i);
  }
  
  int cnt2=0;
  
  while (q--) {
    int command, i; cin >> command >> i;
    if (command == 1) {
      if (direction[i] == 'L') {
        tree_right.erase(i);
        tree_left.insert(i);
      } else {
        tree_left.erase(i);
        tree_right.insert(i);
      }
      group[group_index[i]].erase({direction[i], i});
      direction[i] ^= 'R' ^ 'L';
      group[group_index[i]].insert({direction[i], i});
    } else {
      int distance = -1;
      int j = group[group_index[i]].find_by_order(group_position[i])->second;
      if (direction[j] == 'L') {
        int k = tree_left.ancestor(nearest_left[j]);
        if (k) distance = position[j] - position[k]; 
      } else {
        int k = tree_right.ancestor(nearest_right[j]);
        if (k) distance = position[k] - position[j];
      }
      if (distance < 0) cout << "-1\n";
      else cout << distance / 2 << (distance & 1 ? ".5" : ".0") << '\n';
    }
  }
}
