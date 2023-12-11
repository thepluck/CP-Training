#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> blacks;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
int vx[35], vy[35];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c; cin >> r >> c;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        blacks.emplace(u, v);
        vx[i] = u; vy[i] = v;
    }
    n = blacks.size();
    if (r <= 40 && c <= 40) {
        int res = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (blacks.count(make_pair(i, j)))
                    continue;
                int u, v; queue<pair<int, int>> que;
                vector<vector<int>> dis(r, vector<int> (c, -1));
                dis[i][j] = 0; que.emplace(i, j);
                while (que.size()) {
                    tie(u, v) = que.front(); que.pop();
                    res += dis[u][v];
                    for (int d = 0; d < 4; d++) {
                        int x = u + dx[d], y = v + dy[d];
                        if (0 <= x && x < r && 0 <= y && y < c &&
                        dis[x][y] < 0 && !blacks.count(make_pair(x, y))) {
                            dis[x][y] = dis[u][v] + 1; que.emplace(x, y);
                        }
                    }
                }
            }
        cout << res / 2; return 0;
    } else {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                queue<pair<int, int>> que;
                
            }
    }
}