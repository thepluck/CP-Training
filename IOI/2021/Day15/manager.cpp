#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <iomanip>
#include <signal.h>

using namespace std;

ofstream fifoManagerToContestant;
ifstream fifoContestantToManager;

void wrongAnswer(string error) {
  fifoManagerToContestant.close();
  fifoContestantToManager.close();
  printf("0.000000\n");
  cerr << error << endl;
  exit(0);
}

void accepted(int n, int p) {
  fifoManagerToContestant.close();
  fifoContestantToManager.close();

  printf("1\n");

  exit(0);
}

bool valid(int n, int e, int o) {
  return 1 <= e && e <= n / 2 && 1 <= o && o <= (n + 1) / 2;
}

int main(int argc, char **argv) {
  signal(SIGPIPE, SIG_IGN);

  // When the sandbox opens the other endpoints of these fifos to redirect
  // them to to stdin/out it does so first for stdin and then for stdout.
  // We must match that order as otherwise we would deadlock.
  // So DO NOT change the order of the next 2 lines.
  fifoManagerToContestant.open(argv[2]); //this is the stream we write into so that the contestant can read from
  fifoContestantToManager.open(argv[1]); //this is the stream the contestant writes into so that we can read from

  int theta, n, res;
  int cntCompare = 0;
  int even[10101];
  int odd[10101];
  // manager read data from secret input
  ifstream secretInput("input.txt");
  secretInput >> theta >> n;
  for (int i = 1; i <= n / 2; i++) secretInput >> even[i];
  for (int i = 1; i <= (n + 1) / 2; i++) secretInput >> odd[i];
  secretInput.close();

  // and pass to contestant
  fifoManagerToContestant << theta << " " << n << endl;
  // fifoManagerToContestant << flush;

  while (true) {
    string queryType;
    fifoContestantToManager >> queryType;

    if (queryType == "compare") {
      cntCompare++;
      int u, v;
      fifoContestantToManager >> u >> v;
      if (!valid(n, u, v)) {
        wrongAnswer("Invalid call");
      }
      if (cntCompare <= 300000) {
        if (even[u] < odd[v])
          fifoManagerToContestant << "<" << endl;
        else
          fifoManagerToContestant << ">" << endl;
        // fifoManagerToContestant << flush;
      } else {
        wrongAnswer("Too many calls");
      }
    } else if (queryType == "answer") {
      for (int i = 1; i <= n / 2; i++) {
        int x;
        fifoContestantToManager >> x;
        if (x != even[i]) {
          wrongAnswer("Incorrect answer");
        }
      }
      for (int i = 1; i <= (n + 1) / 2; i++) {
        int x;
        fifoContestantToManager >> x;
        if (x != odd[i]) {
          wrongAnswer("Incorrect answer");
        }
      }
      
      accepted(n, cntCompare);
    } else {
      //wrong query type
      wrongAnswer("Invalid call OR contestant's program quit unexpectedly");
    }
  }
}
