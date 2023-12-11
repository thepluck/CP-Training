#include "testlib.h"

using namespace std;

int main(int argc, char **argv) {
  registerGen(argc, argv, 1);
  prepareOpts(argc, argv);
  int bias = opt<int> ("bias");
  int cnt[3];
  cnt[0] = rnd.wnext(1, 98, bias);
  cnt[1] = rnd.wnext(1, 100 - cnt[0] - 1, bias / 2);
  cnt[2] = 100 - cnt[0] - cnt[1];
  string chr = "012";
  shuffle(chr.begin(), chr.end());
  string s;
  for (int i = 0; i < 3; i++)
    s += string(cnt[i], chr[i]);
  shuffle(s.begin(), s.end());
  cout << 100 << '\n' << s << '\n';
}