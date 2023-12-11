#include <bits/stdc++.h>

using namespace std;

template<class X, class Y>
bool minimize(X &a, const Y &b) {
  return a > b ? a = b, 1 : 0;
}

template<class X, class Y>
bool maximize(X &a, const Y &b) {
  return a < b ? a = b, 1 : 0;  
}

const int N = 300005;
const int M = 1000005;

struct treeNode {
  /// @brief minimum of the maximum one in all pair
  int minOfMaxPair = N, maxOfMinPair = 0;
  /// @brief left and right unpaired element
  int leftUnpaired = 0, rightUnpaired = 0;

  treeNode() {}

  bool empty() const {
    return !maxOfMinPair && !leftUnpaired && !rightUnpaired;
  }
};

/// @brief merge two tree node
treeNode operator + (treeNode a, treeNode b) {
  if (a.empty()) return b;
  if (b.empty()) return a;
  minimize(a.minOfMaxPair, b.minOfMaxPair);
  maximize(a.maxOfMinPair, b.maxOfMinPair);
  if (a.rightUnpaired) {
    assert(b.leftUnpaired);
    minimize(a.minOfMaxPair, max(a.rightUnpaired, b.leftUnpaired));
    maximize(a.maxOfMinPair, min(a.rightUnpaired, b.leftUnpaired));
  }
  a.rightUnpaired = b.rightUnpaired;
  return a;
}

/// @brief 
struct segmentTree {
  vector<array<treeNode, 2>> tree;
  vector<char> flip;
  vector<int> pos, idx;

  segmentTree(int n) {
    tree.resize(M * 4); flip.resize(M * 4);
    pos.resize(n + 1, M); idx.resize(M + 1);
  }
  
  void flipNode(int node) {
    flip[node] ^= 1;
    swap(tree[node][0], tree[node][1]);
  }
  
  void pushLazy(int node) {
    if (flip[node]) {
      flipNode(node * 2);
      flipNode(node * 2 + 1);
      flip[node] = 0;
    }
  }
  
  /// @brief update range [x, y]
  void update(int node, int l, int r, int x, int y) {
    if (l > x && r < y) return flipNode(node);
    if (l == r && (l == x || r == y)) {
      flip[node] ^= (l == x);
      tree[node][flip[node]].rightUnpaired = idx[l];
      tree[node][flip[node] ^ 1].leftUnpaired = idx[l];
      tree[node][flip[node]].leftUnpaired = 0;
      tree[node][flip[node] ^ 1].rightUnpaired = 0;
    } else {
      int m = (l + r) / 2; pushLazy(node);
      if (m >= x) update(node * 2, l, m, x, y);
      if (m < y) update(node * 2 + 1, m + 1, r, x, y);
      tree[node][0] = tree[node * 2][0] + tree[node * 2 + 1][0];
      tree[node][1] = tree[node * 2][1] + tree[node * 2 + 1][1];
    }
  }
  
  /// @brief change pos[i] to y
  void update(int i, int y) {
    int x = pos[i];
    idx[x] = 0; pos[i] = y; idx[y] = i;
    if (x > y) swap(x, y);
    update(1, 1, M - 1, x, y);
  }
  
  int winner() {
    /// @brief first player win
    if (tree[1][0].leftUnpaired <= tree[1][0].minOfMaxPair
    && tree[1][0].leftUnpaired >= tree[1][0].maxOfMinPair)
      return tree[1][0].leftUnpaired;
    treeNode cur, nxt;
    /// @brief find two candidate
    if (tree[1][0].maxOfMinPair > tree[1][0].minOfMaxPair) {
      int node = 1, l = 1, r = M - 1;
      while (l < r) {
        int m = (l + r) / 2; pushLazy(node);
        nxt = tree[node * 2 + 1][0] + cur;
        if (nxt.maxOfMinPair <= nxt.minOfMaxPair) {
          cur = nxt; r = m; node = node * 2;
        } else {
          l = m + 1; node = node * 2 + 1;
        }
      }
    } else cur = tree[1][0];
    assert(cur.leftUnpaired);
    if (cur.leftUnpaired < cur.maxOfMinPair)
      return cur.maxOfMinPair;
    return cur.minOfMaxPair;
  }
};


int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q; cin >> n >> q;
  segmentTree seg(n);
  for (int i = 1; i <= n; i++) {
    int y; cin >> y; seg.update(i, y);
  }
  while (q--) {
    char cmd; cin >> cmd;
    if (cmd == 'W') cout << seg.winner() << '\n';
    else {
      int i, y; cin >> i >> y; seg.update(i, y);
    }
  }
}