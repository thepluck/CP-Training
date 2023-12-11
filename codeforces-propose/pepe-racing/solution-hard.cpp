#include <bits/stdc++.h>

using namespace std;

const int N = 30;

vector<int> buc[N];
int buc_id[N * N], buc_max[N];
int n;

int ask(vector<int> que) {
  cout << "?";
  for (int i : que) cout << ' ' << i;
  cout << endl;
  int res; cin >> res;
  return res;
}

int ask_all() {
  vector<int> que;
  for (int i = 0; i < n; i++)
    if (buc[i].size())
      que.push_back(buc_max[i]);
  for (int i = 0; i < n; i++)
    for (int j : buc[i])
      if (int(que.size()) < n && j != buc_max[i])
        que.push_back(j);
  return ask(que);
}

void answer(vector<int> ans) {
  cout << "!";
  for (int i : ans) cout << ' ' << i;
  cout << endl;
}

void add(int id, int pepe) {
  buc[id].push_back(pepe);
  buc_id[pepe] = id;
}

void remove(int id, int pepe) {
  buc[id].erase(find(buc[id].begin(), buc[id].end(), pepe));
}

void send(int id, vector<int> &que) {
  for (int pepe : buc[id])
    if (int(que.size()) < n && pepe != buc_max[id])
      que.push_back(pepe);
}

void check_balance() {
  size_t min_size = n, max_size = 0;
  for (int id = 0; id < n; id++) {
    min_size = min(min_size, buc[id].size());
    max_size = max(max_size, buc[id].size());
  }
  assert(max_size - min_size <= 1);
}


int main() {
  cout << endl;
  int t; cin >> t;
  while (t--) {
    cin >> n;
    for (int id = 0; id < n; id++)
      buc[id].clear();
      
    for (int pepe = 0; pepe < n * n; pepe++) {
      buc_id[pepe] = pepe / n;
      buc[pepe / n].push_back(pepe);
    }
    
    for (int id = 0; id < n; id++)
      buc_max[id] = ask(buc[id]);
      
    vector<int> ans;
    
    /// balancing phase
    for (int step = 0; step < n * n - 2 * n; step++) {
      ans.push_back(ask_all());
      int last_id = buc_id[ans.back()];
      remove(last_id, ans.back());
      
      vector<int> que;
              
      for (int pepe : buc[last_id])
        que.push_back(pepe);
        
      /// find bucket with largest size != last_id
      int max_id = (last_id == 0);
      for (int id = 0; id < n; id++)
        if (id != last_id && buc[id].size() > buc[max_id].size())
          max_id = id;
          
      
      send(max_id, que);
      
      for (int id = 0; id < n; id++)
        if (id != max_id && id != last_id)
          send(id, que);
      
      buc_max[last_id] = ask(que);
      int move_id = buc_id[buc_max[last_id]];
      if (move_id != last_id) {
        remove(move_id, buc_max[last_id]);
        add(move_id, buc[last_id].back());
        remove(last_id, buc[last_id].back());
        add(last_id, buc_max[last_id]);
      }        
      
      if (buc[last_id].size() == buc[max_id].size() - 2) {
        if (move_id == max_id) {
          add(last_id, buc[move_id].back());
          remove(move_id, buc[move_id].back());
        } else {
          for (int pepe : buc[max_id])
            if (pepe != buc_max[max_id]) {
              add(last_id, pepe);
              remove(max_id, pepe);
              break;
            }
        }
      }
      
      check_balance();
    }
  
    
    for (int step = 0; step < n + 1; step++) {
      ans.push_back(ask_all());
      int last_id = buc_id[ans.back()];
      remove(last_id, ans.back());
      if (buc[last_id].size())
        buc_max[last_id] = buc[last_id][0];
    }
    
    answer(ans);
  }
}