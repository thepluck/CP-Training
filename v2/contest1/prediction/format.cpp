#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
  cin.tie(0)->sync_with_stdio(0);
  ifstream in(argv[1]);
  int L, N, M;
  in >> L >> N >> M;
  vector<tuple<int, int, int, int>> v(M);
  for (int i = 0; i < M; i++) {
    int c, t, x, y;
    in >> c >> t >> x >> y;
    v[i] = {c, t, x - 1, y - 1};
  }
  in.close();
  ofstream out(argv[1]);
  out << L << ' ' << N << ' ' << M << '\n';
  for (int i = 0; i < M; i++) {
    out << get<0> (v[i]) << ' ';
    out << get<1> (v[i]) << ' ';
    out << get<2> (v[i]) << ' ';
    out << get<3> (v[i]) << '\n';
  }
  out.close();
}