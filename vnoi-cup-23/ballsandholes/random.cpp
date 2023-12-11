#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n, k;

int get_adj(int offset, int x) {
  if ((x - offset) & 1) return x - 1;
  return x + 1;
}

bool hole[105];

void move_ball(int player, int l, int r) {
  assert(l < r && hole[l] && !hole[r]);
  if (player) cout << l << ' ' << r << endl;
  hole[l] ^= 1; hole[r] ^= 1;
}

bool check_ended() {
  for (int i = n - k; i < n; i++)
    if (!hole[i]) return false;
  return true;
}

void solve() {
  cin >> n >> k;
  
  memset(hole, 0, sizeof hole);
  for (int i = 0; i < k; i++)
    hole[i] = 1;
  int turn = rng() & 1;
  if (turn) cout << "Alice\n";
  else cout << "Bob\n";
  while (!check_ended()) {
    if (!turn) {
      int l, r; cin >> l >> r;
      move_ball(0, l, r);
    } else {
      int first = 0;
      while (!hole[first]) first++;
      int last = n - 1;
      while (hole[last]) last--;
      vector<int> pos;
      for (int i = first; i < last; i++)
        if (hole[i]) pos.push_back(i);
      int choose = pos[rng() % pos.size()];
      pos.clear();
      for (int i = choose + 1; i < n; i++)
        if (!hole[i]) pos.push_back(i);
      move_ball(1, choose, pos[rng() % pos.size()]);
    }
    turn ^= 1;
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
}