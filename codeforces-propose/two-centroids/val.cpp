#include "testlib.h"
using namespace std;

const int max_testcount = 10'000;
const int max_n = 500'000;
const int max_sum_n = 500'000;

int main(int argc, char** argv) {
    registerValidation(argc, argv);

    int testcount = inf.readInt(1, max_testcount, "test-count");
    inf.readEoln();

    int sum_n = 0;
    for (int testcase = 1; testcase <= testcount; ++testcase) {
        setTestCase(testcase);

        int n = inf.readInt(1, max_n, "n");
        inf.readEoln();
        sum_n += n;
        ensuref(sum_n <= max_sum_n, "sum of n over all cases should not exceed %d", max_sum_n);
        
        for (int u = 2; u <= n; u++) {
            int p = inf.readInt(1, u - 1, "par[u]");
            if (u < n) inf.readSpace();
            else inf.readEoln();
        }
    }

    inf.readEof();
}