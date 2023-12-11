#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

bool a[35][35];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            if (c == '#') a[i][j] = true;
        }
    int res = 0;
    vector <vector <pair <int, int>>> cur, nxt;
    cur.push_back({{0, 0}});
    for (int st = 1; st < k; st++) {
        nxt.clear();
        for (auto state : cur)
            for (auto cell : state)
                for (int d = 0; d < 4; d++) {
                    vector <pair <int, int>> newState = state;
                    pair <int, int> newCell;
                    newCell.first = cell.first + dx[d];
                    newCell.second = cell.second + dy[d];
                    if (newCell.first < 0) continue;
                    if (newCell.first == 0 && newCell.second < 0) continue;
                    if (find(state.begin(), state.end(),
                    newCell) != state.end()) continue;
                    newState.push_back(newCell);
                    sort(newState.begin(), newState.end());
                    nxt.push_back(newState);
                }
        cur.swap(nxt); sort(cur.begin(), cur.end());
        cur.erase(unique(cur.begin(), cur.end()), cur.end());
        
    }
    for (auto state : cur) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool flag = true;
                for (auto cell : state) {
                    pair <int, int> realCell;
                    realCell.first = cell.first + i;
                    realCell.second = cell.second + j;
                    if (realCell.first < 0 || realCell.first >= n
                    || realCell.second < 0 || realCell.second >= m
                    || !a[realCell.first][realCell.second]) {
                        flag = false; break;
                    }
                }
                if (flag) res++;
            }
    }
    cout << res << '\n';
}