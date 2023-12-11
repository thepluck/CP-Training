#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  string dump1;
  string dump2;
  int cnt2 = 0, cnt3 = 0, cnt4 = 0;
  vector<int> sub4;
  while (cin >> n >> dump1 >> dump2) {
    if (n <= 500) {
      cnt2++;
      string file = "tests/sub2_spec" + to_string(cnt2) + ".in";
      ofstream out(file);
      out << 1 << '\n' << n << '\n';
    } else if (n <= 5000) {
      cnt3++;
      string file = "tests/sub3_spec" + to_string(cnt3) + ".in";
      ofstream out(file);
      out << 1 << '\n' << n << '\n';
    } else sub4.push_back(n);
  }
  sort(sub4.begin(), sub4.end());
  for (int i = 0; i < sub4.size(); ) {
    cnt4++;
    string file = "tests/sub4_spec" + to_string(cnt4) + ".in";
    int j = i, sum = 0;
    while (j < sub4.size() && sum + sub4[j] <= 1000000) {
      sum += sub4[j++];
    }
    cerr<<sum<<'\n';
    ofstream out(file);
    out << j - i << '\n';
    while (i < j) {
      out << sub4[i] << '\n'; i++;
    }
  }
}