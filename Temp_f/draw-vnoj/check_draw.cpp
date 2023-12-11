#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

using ii = pair<int, int>;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool adj[N][N][4];

bool check(const vector<pair<ii, ii>> &seg, const vector<vector<ii>> &seq) {
    for (auto s : seg) {
        int x, y, u, v;
        tie(x, y) = s.first;
        tie(u, v) = s.second;
        if (x == u) {
            for (int k = y; k < v; k++)
                adj[x][k][3] = adj[x][k + 1][2] = true;
        } else {
            for (int k = x; k < u; k++)
                adj[k][y][1] = adj[k + 1][y][0] = true;
        }
    }
    for (auto s : seq) {
        for (int i = 0; i + 1 < s.size(); i++) {
            int x, y, u, v;
            tie(x, y) = s[i];
            tie(u, v) = s[i + 1];
            for (int k = 0; k < 4; k++)
                if (x + dx[k] == u && y + dy[k] == v) {
                    if (!adj[x][y][k]) return false;
                    adj[x][y][k] = adj[u][v][k ^ 1] = false;
                }
        }
    }
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            for (int k = 0; k < 4; k++)
                if (adj[x][y][k]) return false;
    return true;
}

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(1, 1000);
    vector<pair<ii, ii>> seg;
    while (n--) {
        int x, y, u, v;
        x = inf.readInt(-1000, 1000);
        y = inf.readInt(-1000, 1000);
        u = inf.readInt(-1000, 1000);
        v = inf.readInt(-1000, 1000);
        x += 1000; y += 1000; u += 1000; v += 1000;
        if (x > u || y > v) {
            swap(x, u); swap(y, v);
        }
        seg.emplace_back(ii(x, y), ii(u, v));
    }
    int jans = ans.readInt();
    vector<vector<ii>> jseq;
    for (int i = 0; i < jans; i++) {
        int k = ans.readInt();
        jseq.emplace_back();
        while (k--) {
            int x = ans.readInt(-1000, 1000);
            int y = ans.readInt(-1000, 1000);
            x += 1000; y += 1000;
            jseq.back().emplace_back(x, y);
        }
    }
    if (!check(seg, jseq))
        quitf(_fail, "jury sequence is incorrect");
    int pans = ouf.readInt();
    if (pans > jans)
        quitf(_wa, "answer is not optimal");
    vector<vector<ii>> pseq;
    for (int i = 0; i < pans; i++) {
        int k = ouf.readInt();
        pseq.emplace_back();
        while (k--) {
            int x = ouf.readInt(-1000, 1000);
            int y = ouf.readInt(-1000, 1000);
            x += 1000; y += 1000;
            pseq.back().emplace_back(x, y);
        }
    }
    if (!check(seg, pseq))
        quitf(_wa, "sequence is incorrect");
    if (pans < jans)
        quitf(_fail, "jury answer is not optimal");
    quitf(_ok, "correct");
}