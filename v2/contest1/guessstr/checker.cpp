#include "testlib.h"

using namespace std;

double score(InStream &stream, TResult verdict) {
  string result = stream.readToken();
  if (result == "WA") {
    string msg;
    if (!stream.seekEof())
      msg = stream.readLine();
    quitf(verdict, "WA %s", msg.data());
  }
  if (result != "OK")
    quitf(_fail, "Unknow grader result");
  int count_ask = stream.readInt(0, 10000);
  if (count_ask <= 100) return 50;
  return 5000.0 / (100 + count_ask);
}

int main(int argc, char **argv) {
  registerTestlibCmd(argc, argv);
  int N = inf.readInt(100, 100, "N");
  string S = inf.readToken("[0-2]{100, 100}", "S");
  score(ans, _fail);
  quitp(score(ouf, _wa), "");
}