#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int r, c, k;
bool flag;

void move(int &x, int &y, char d) {
    if (d == 'L') y--;
    if (d == 'R') y++;
    if (d == 'U') x--;
    if (d == 'D') x++;
}

void dfs(int u, int cnt,
const vector<int> &color,
const vector<vector<int>> &adj) {
    cnt += color[u];
    if (u < r && cnt != 1) {
        if (flag)
            quitf(_fail, "path must have exactly 1 colored cell");
        else quitf(_wa, "path must have exactly 1 colored cell");
    }
    for (int v : adj[u])
        dfs(v, cnt, color, adj);
}

void check(const vector<string> &field,
const vector<pair<int, int>> &blacks) {
    vector<int> color(r * c);
    vector<vector<int>> adj(r * c);
    for (auto black : blacks) {
        int x, y; tie(x, y) = black;
        color[x + y * r] = 1;
    }
    for (int x = 0; x < r; x++)
        for (int y = 0; y < c - 1; y++) {
            int u = x, v = y;
            move(u, v, field[x][y]);
            if (v == c - 1)
                adj[(c - 1) * r].push_back(x + y * r);
            else adj[u + v * r].push_back(x + y * r);
        }
    dfs((c - 1) * r, 0, color, adj);
}

int main(int argc, char **argv) {
    registerTestlibCmd(argc, argv);
    r = inf.readInt();
    c = inf.readInt();
    k = inf.readInt();
    vector<string> field(r);
    for (auto &row : field)
        row = inf.readToken();
    flag = 0;
    bool out_result;
    {
        vector<pair<int, int>> blacks;
        int x = ouf.readInt(), y;  
        if (x == -1) out_result = false;
        else {
            out_result = true;
            y = ouf.readInt();
            if (x <= 0 || x > r || y <= 0 || y >= c)
                quitf(_wa, "cell is out of the field or in last column");
            blacks.emplace_back(x - 1, y - 1);
            for (int i = 1; i < k; i++) {
                x = ouf.readInt();
                y = ouf.readInt();
                if (x <= 0 || x > r || y <= 0 || y >= c)
                    quitf(_wa, "cell is out of the field or in last column");
                blacks.emplace_back(x - 1, y - 1);
            }
            sort(blacks.begin(), blacks.end());
            blacks.erase(unique(blacks.begin(), blacks.end()), blacks.end());
            if (blacks.size() != k)
                quitf(_wa, "duplicate cells");
            check(field, blacks);
        }
    }
    flag = 1;
    bool ans_result;
    {
        vector<pair<int, int>> blacks;
        int x = ans.readInt(), y;  
        if (x == -1) ans_result = false;
        else {
            ans_result = true;
            y = ans.readInt();
            if (x <= 0 || x > r || y <= 0 || y >= c)
                quitf(_fail, "cell is out of the field or in last column");
            blacks.emplace_back(x - 1, y - 1);
            for (int i = 1; i < k; i++) {
                x = ans.readInt();
                y = ans.readInt();
                if (x <= 0 || x > r || y <= 0 || y >= c)
                    quitf(_fail, "cell is out of the field or in last column");
                blacks.emplace_back(x - 1, y - 1);
            }
            sort(blacks.begin(), blacks.end());
            blacks.erase(unique(blacks.begin(), blacks.end()), blacks.end());
            if (blacks.size() != k)
                quitf(_fail, "duplicate cells");
            check(field, blacks);
        }
    }
    if (ans_result == out_result)
        quitf(_ok, "coloring is correct");
    else {
        if (out_result)
            quitf(_fail, "test data is wrong");
        else quitf(_wa, "coloring is incorrect");
    }
}