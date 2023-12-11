#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

using ii = pair<int, int>;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool adj[N][N][4];

int main(int argc, char **argv) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1000);
    inf.readEoln();
    vector<pair<ii, ii>> seg;
    while (n--) {
        int x, y, u, v;
        x = inf.readInt(-1000, 1000);
        inf.readSpace();
        y = inf.readInt(-1000, 1000);
        inf.readSpace();
        u = inf.readInt(-1000, 1000);
        inf.readSpace();
        v = inf.readInt(-1000, 1000);
        inf.readEoln();
        x += 1000; y += 1000; u += 1000; v += 1000;
        if (x > u || y > v) {
            swap(x, u); swap(y, v);
        }
        if (x == u) {
            for (int k = y; k < v; k++) {
                ensuref(!adj[x][k][3], "segments can not overlap");
                adj[x][k][3] = adj[x][k + 1][2] = true;
            }
        } else {
            for (int k = x; k < u; k++) {
                ensuref(!adj[k][y][1], "segments can not overlap");
                adj[k][y][1] = adj[k + 1][y][0] = true;
            }
        }
    }
    inf.readEof();
}
