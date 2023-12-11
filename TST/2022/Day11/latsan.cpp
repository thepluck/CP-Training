#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, k, m, a[205][205], cnt;
set<pair<int, int>> cur, nxt;
vector<vector<pair<int, int>>> ans;

bool inside(int x, int y) {
    return x > 0 && x <= m && y > 0 && y <= m;
}

void extend(int x, int y) {
    for (int d = 0; d < 4; d++)
        if (inside(x + dx[d], y + dy[d])
        && !a[x + dx[d]][y + dy[d]])
            nxt.emplace(x + dx[d], y + dy[d]);
}

void check(int x, int y) {
    if (a[x][y]) return;
    int sur = 0;
    for (int d = 0; d < 4; d++)
        sur += a[x + dx[d]][y + dy[d]] > 0;
    if (sur == 3) {
        int d = 0; cnt++;
        while (a[x + dx[d]][y + dy[d]]) d++;
        ans.emplace_back();
        for (int i = 0; i < k; i++) {
            a[x][y] = cnt;
            ans.back().emplace_back(x, y);
            x += dx[d]; y += dy[d];
        }
        d ^= 1;
        for (int i = 0; i < k; i++) {
            extend(x, y);
            x += dx[d]; y += dy[d];
        }
    }
    if (sur == 2) {
        for (int d1 : {0, 1})
            for (int d2 : {2, 3})
                if (!a[x + dx[d1]][y + dy[d1]] &&
                !a[x + dx[d2]][y + dy[d2]]) {
                    int u = x, v = y;
                    bool f1 = 0, f2 = 0;
                    for (int i = 0; i < k; i++) {
                        if (a[u][v]) f1 = 1;
                        u += dx[d1]; v += dy[d1];
                    }
                    u = x; v = y;
                    for (int i = 0; i < k; i++) {
                        if (a[u][v]) f2 = 1;
                        u += dx[d2]; v += dy[d2];
                    }
                    if (f1) {
                        int d = d2; cnt++;
                        for (int i = 0; i < k; i++) {
                            a[x][y] = cnt;
                            ans.back().emplace_back(x, y);
                            x += dx[d]; y += dy[d];
                        }
                        d ^= 1;
                        for (int i = 0; i < k; i++) {
                            extend(x, y);
                            x += dx[d]; y += dy[d];
                        }
                    } else if (f2) {
                        int d = d1; cnt++;
                        for (int i = 0; i < k; i++) {
                            a[x][y] = cnt;
                            ans.back().emplace_back(x, y);
                            x += dx[d]; y += dy[d];
                        }
                        d ^= 1;
                        for (int i = 0; i < k; i++) {
                            extend(x, y);
                            x += dx[d]; y += dy[d];
                        }
                    }
                }
    }
}

int main() {
    cin >> n >> k; m = n * k;
    for (int i : {0, m + 1})
        for (int j = 0; j <= m + 1; j++)
            a[i][j] = a[j][i] = INT_MAX;
    while (cnt != n * n * k) {
        for (int i = 0; i <= m + 1; i++)
            for (int j = 0; j <= m + 1; j++)
                if (a[i][j]) extend(i, j);
        vector<pair<int, int>> tmp(nxt.begin(), nxt.end());
        {
            auto p = tmp[rand(0, tmp.size() - 1)];
            cout << "ASK " << p.first << ' ' << p.second << endl;
            tmp.clear(); tmp.push_back(p);
            a[p.first][p.second] = ++cnt;
            for (int i = 1; i < k; i++) {
                cin >> p.first >> p.second;
                tmp.push_back(p);
                a[p.first][p.second] = cnt;
            }
        }
        ans.push_back(tmp);
        nxt.clear(); cur.clear();
        for (auto p : tmp)
            for (int d = 0; d < 4; d++)
                if (!a[p.first + dx[d]][p.second + dy[d]])
                    cur.emplace(p.first + dx[d], p.second + dy[d]);
        while (cur.size()) {
            assert(nxt.empty());
            for (auto p : cur) check(p.first, p.second);
            cur = move(nxt);
        }
    }
    cout << "ANSWER" << endl;
    for (auto v : ans) {
        for (auto x : v) cout << x.first << ' ' << x.second << ' ';
        cout << endl;
    }
}