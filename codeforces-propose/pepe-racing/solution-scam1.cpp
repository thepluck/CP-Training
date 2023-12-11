#include <bits/stdc++.h>

using namespace std;

const int N = 30;

vector<int> buc[N];
int buc_id[N * N], buc_max[N];
int n, q;

int ask(vector<int> que) {
  q--;
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

void send(int id, int last_id) {
  for (int &pepe : buc[id])
    if (pepe == buc_max[id])
      swap(pepe, buc[id][0]);
  while (int(buc[last_id].size()) < n && int(buc[id].size()) > 1) {
    buc[last_id].push_back(buc[id].back());
    buc_id[buc[id].back()] = last_id;
    buc[id].pop_back();
  }
}


int main() {
  cout << endl;
  int t; cin >> t;
  while (t--) {
    cin >> n >> q;
    for (int id = 0; id < n; id++)
      buc[id].clear();
      
    for (int pepe = 0; pepe < n * n; pepe++) {
      buc_id[pepe] = pepe / n;
      buc[pepe / n].push_back(pepe);
    }
    
    for (int id = 0; id < n; id++)
      buc_max[id] = ask(buc[id]);
      
    vector<int> ans;
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);

    for (int step = 0; ; step++) {
      ans.push_back(ask_all());
      int last_id = buc_id[ans.back()];
      remove(last_id, ans.back());
      
      if (step == n * n - n - 1) {
        vector<int> que;
        for (int id = 0; id < n; id++)
          for (int pepe : buc[id])
            que.push_back(pepe);
        ans.push_back(ask(que));
        break;
      }
      if (buc[last_id].size() == 1) {
        buc_max[last_id] = buc[last_id][0];
      } else if (buc[last_id].size() > 1) {
        
        sort(ids.begin(), ids.end(), [&](int i, int j) {
          return buc[i].size() < buc[j].size();
        });
        for (int id : ids)
          if (id != last_id)
            send(id, last_id);
        for (int id = 0; id < n; id++)
          if (id != last_id && int(buc[last_id].size()) < n && buc[id].size()) {
            buc[last_id].push_back(buc[id].back());
            buc_id[buc[id].back()] = last_id;
            buc[id].pop_back();
          }
        buc_max[last_id] = ask(buc[last_id]);
      }
    }
    answer(ans);
  }
}