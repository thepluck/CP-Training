#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int subtask = opt<int> ("subtask");
  vector<int> Ns;
  string type;
  if (subtask != 1) type = opt<string> ("type");
  if (subtask == 1) {
    Ns.resize(rnd.next(190, 200));
    for (int &N : Ns) N = rnd.next(12, 15);
  } else if (subtask == 2) {
    if (type == "all") {
      Ns.push_back(rnd.next(190, 200));
    } else if (type == "huge") {
      Ns = rnd.partition(rnd.next(1, 10), rnd.next(190, 200) - 20, 2);
      Ns.push_back(20);
    } else if (type == "large") {
      Ns = rnd.partition(rnd.next(11, 20), rnd.next(190, 200) - 20, 2);
      Ns.push_back(20);
    } else if (type == "small") {
      Ns = rnd.partition(rnd.next(21, 50), rnd.next(190, 200) - 20, 2);
      Ns.push_back(20);
    } else quitf(_fail, "?????");
  } else if (subtask == 3) {
    if (type == "all") {
      Ns.push_back(rnd.next(950000, 1000000));
    } else if (type == "huge") {
      Ns = rnd.partition(rnd.next(1, 100), rnd.next(950000, 1000000), 2);
    } else if (type == "large") {
      Ns = rnd.partition(rnd.next(101, 1000), rnd.next(950000, 1000000), 2);
    } else if (type == "small") {
      Ns = rnd.partition(rnd.next(1001, 10000), rnd.next(950000, 1000000), 2);
    } else quitf(_fail, "?????");
  } else quitf(_fail, "?????");
  cout << Ns.size() << '\n';
  /*
  1: increasing
  2: gen pmax first, |pmax| short
  3: gen pmax first, |pmax| random
  4: gen p q first, |p| short
  5: gen p q first, |p| random
  6: random
  */
  for (int N : Ns) {
    cout << N << '\n';
    int genType;
    if (Ns.size() == 1) genType = rnd.next(2, 6);
    else genType = rnd.next(1, 6);
    if (genType == 1) {
      set<int> s;
      while (s.size() < N) s.insert(rnd.next(1, 1'000'000'000));
      vector<int> a(s.begin(), s.end());
      for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
    } else if (genType == 2) {
      set<int> s;
      int len = rnd.next(1, max(1, min(N / 10, 100)));
      while (s.size() < len) s.insert(rnd.next(N + 1, 1'000'000'000));
      vector<int> dis = rnd.partition(len, N, 1);
      int pos = 0;
      vector<int> a(N);
      for (int i = 0; i < len; i++) {
        a[pos] = *s.begin(); s.erase(s.begin());
        pos += dis[i];
      }
      assert(s.empty());
      int pmax = 0;
      for (int i = 0; i < N; i++) {
        if (!a[i]) {
          while (s.count(a[i] = rnd.next(1, pmax - 1)));
        } else pmax = a[i];
        s.insert(a[i]);
      }
      for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
    } else if (genType == 3) {
      set<int> s;
      int len = rnd.next(1, N);
      while (s.size() < len) s.insert(rnd.next(N + 1, 1'000'000'000));
      vector<int> dis = rnd.partition(len, N, 1);
      int pos = 0;
      vector<int> a(N);
      for (int i = 0; i < len; i++) {
        a[pos] = *s.begin(); s.erase(s.begin());
        pos += dis[i];
      }
      assert(s.empty());
      int pmax = 0;
      for (int i = 0; i < N; i++) {
        if (!a[i]) {
          while (s.count(a[i] = rnd.next(1, pmax - 1)));
        } else pmax = a[i];
        s.insert(a[i]);
      }
      for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
    } else if (genType == 4) {
      set<int> s;
      int len = rnd.next(1, max(1, min(N / 10, 100)));
      while (s.size() < 2 * len) s.insert(rnd.next(N + 1, 1'000'000'000));
      vector<int> tmp(s.begin(), s.end());
      shuffle(tmp.begin(), tmp.end());
      set<int> s1, s2;
      for (int i = 0; i < len; i++) {
        s1.insert(tmp[i]); s2.insert(tmp[i + len]);
      }
      vector<int> order(2 * len);
      for (int i = 0; i < len; i++)
        order[i] = 1;
      shuffle(order.begin(), order.end());
      vector<int> dis = rnd.partition(2 * len, N, 1);
      int pos = 0;
      vector<int> a(N);
      for (int i = 0; i < 2 * len; i++) {
        if (order[i]) {
          a[pos] = *s1.begin(); s1.erase(s1.begin());
        } else {
          a[pos] = *s2.begin(); s2.erase(s2.begin());
        }
        pos += dis[i];
      }
      assert(s1.empty());
      int pmax = 0;
      for (int i = 0; i < N; i++) {
        if (!a[i]) {
          while (s1.count(a[i] = rnd.next(1, pmax - 1)));
        } else pmax = max(pmax, a[i]);
        s1.insert(a[i]);
      }
      for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
    } else if (genType == 5) {
      set<int> s;
      int len = rnd.next(1, N / 2);
      while (s.size() < 2 * len) s.insert(rnd.next(N + 1, 1'000'000'000));
      vector<int> tmp(s.begin(), s.end());
      shuffle(tmp.begin(), tmp.end());
      set<int> s1, s2;
      for (int i = 0; i < len; i++) {
        s1.insert(tmp[i]); s2.insert(tmp[i + len]);
      }
      vector<int> order(2 * len);
      for (int i = 0; i < len; i++)
        order[i] = 1;
      shuffle(order.begin(), order.end());
      vector<int> dis = rnd.partition(2 * len, N, 1);
      int pos = 0;
      vector<int> a(N);
      for (int i = 0; i < 2 * len; i++) {
        if (order[i]) {
          a[pos] = *s1.begin(); s1.erase(s1.begin());
        } else {
          a[pos] = *s2.begin(); s2.erase(s2.begin());
        }
        pos += dis[i];
      }
      assert(s1.empty());
      int pmax = 0;
      for (int i = 0; i < N; i++) {
        if (!a[i]) {
          while (s1.count(a[i] = rnd.next(1, pmax - 1)));
        } else pmax = max(pmax, a[i]);
        s1.insert(a[i]);
      }
      for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
    } else if (genType == 6) {
      set<int> s;
      while (s.size() < N) s.insert(rnd.next(1, 1'000'000'000));
      vector<int> a(s.begin(), s.end());
      shuffle(a.begin(), a.end());
      for (int i = 0; i < N; i++)
        cout << a[i] << " \n"[i == N - 1];
    } else quitf(_fail, "?????");
  }
}