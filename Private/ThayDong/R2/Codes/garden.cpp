#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock
::now().time_since_epoch().count());

const int N = 2005;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int a[N][N], ans[N][N], n, m, k;

int cntAdj(int i, int j) {
    int cnt = 0;
    for (int d = 0; d < 4; d++)
        cnt += a[i + dx[d]][j + dy[d]] == 1;
    return cnt;
}

void DFS(int x, int y) {
    vector <pair <int, int>> child;
    for (int d = 0; d < 4; d++) {
        int p = x + dx[d], q = y + dy[d];
        if (p > 0 && q > 0 && p <= n && q <= m
        && !a[p][q] && cntAdj(p, q) == 1) {
            a[p][q] = true;
            child.emplace_back(p, q);
        }
    }
    shuffle(child.begin(), child.end(), rng);
    for (auto cell : child)
        DFS(cell.first, cell.second);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    vector <pair <int, int>> freeCell;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char c; cin >> c;
            if (c == '#') a[i][j] = 2;
            else freeCell.emplace_back(i, j);
        }
    int bestCnt = 0;
    while (clock() < 20 * CLOCKS_PER_SEC) {
        auto root = freeCell[rng() % freeCell.size()];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] < 2) a[i][j] = 0;
        a[root.first][root.second] = true;
        DFS(root.first, root.second); int cnt = 0;
        for (auto cell : freeCell) {
            int x, y; tie(x, y) = cell;
            if (a[x][y] == 1 && cntAdj(x, y) == 1) cnt++;
        }
        if (bestCnt < cnt) {
            bestCnt = cnt;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    ans[i][j] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            switch (ans[i][j]) {
                case 0 : cout << 'X'; break;
                case 1 : cout << '.'; break;
                case 2 : cout << '#'; break;
            }
        cout << '\n';
    }
}