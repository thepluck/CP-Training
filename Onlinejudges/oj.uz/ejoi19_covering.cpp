#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

/// col = 1 : tâm
/// col = -1 : tâm nhưng đã dfs
/// col = 2 : đã đặt T lên 
vector<vector<int>> a, col, dp[2];
queue<pair<int, int>> que;
int n, m;

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void impossible() {
    cout << "No\n"; exit(0);
}

/// đặt T với hướng d bị khuyết 
void place(int i, int j, int d) {
    for (int k = 0; k < 4; k++)
        if (k != d) {
            int x = i + dx[k], y = j + dy[k];
            if (!inside(x, y) || col[x][y])
                impossible();
            col[x][y] = 2;
            que.emplace(x, y);
        }
    col[i][j] = 2;
}

/// đặt T liên tục dựa trên các ô đã đặt
void bfs() {
    int i, j;
    while (que.size()) {
        tie(i, j) = que.front(); que.pop();
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (inside(x, y) && abs(col[x][y]) == 1)
                place(x, y, k ^ 1);
        }
    }
}

/// tạo đồ thị giữa 2 ô có dx = 2, dy = 0 hoặc dx = 0, dy = 2
/// một thành phần liên thông có chu trình => đặt được luôn
/// còn lại là cây => dp 
void dfs(int i, int j, int p) {
    col[i][j] = -1;
    dp[0][i][j] = dp[1][i][j] = -1e9;
    for (int k = 0; k < 4; k++) {
        if (k == p) continue;
        int x = i + dx[k] * 2;
        int y = j + dy[k] * 2;
        if (!inside(x, y)) continue;
        if (col[x][y] == -1) {
            place(i, j, k); bfs();
        }
        if (col[x][y] == 1) dfs(x, y, k ^ 1);
    }
    for (int d = 0; d < 4; d++) {
        int tmp = a[i][j];
        for (int k = 0; k < 4; k++)
            if (k == d) {
                int x = i + dx[k] * 2;
                int y = j + dy[k] * 2;
                if (k != p && inside(x, y))
                    tmp += max(dp[0][x][y], dp[1][x][y]);
            } else {
                tmp += a[i + dx[k]][j + dy[k]];
                int x = i + dx[k] * 2;
                int y = j + dy[k] * 2;
                if (k != p && inside(x, y))
                    tmp += dp[0][x][y];
            }
        dp[d != p][i][j] = max(dp[d != p][i][j], tmp);
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m; a.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(m);
    dp[0] = dp[1] = col = a;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    /// coi như các ô ngoài bảng đã được đặt 
    for (int i = 0; i < n; i++) {
        que.emplace(i, -1);
        que.emplace(i, m);
    }
    for (int j = 0; j < m; j++) {
        que.emplace(-1, j);
        que.emplace(n, j);
    }
    int k; cin >> k;
    while (k--) {
        int x, y; cin >> x >> y;
        if (col[x][y]) impossible();
        col[x][y] = 1;
        que.emplace(x, y);
    }
    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (col[i][j] != 1) continue;
            /// trường hợp dx = 1, dy = 1 => đặt được luôn 
            if (j > 0 && col[i - 1][j - 1] == 1) {
                place(i, j, 0);
                place(i - 1, j - 1, 1);
            }
            if (j + 1 < m && col[i - 1][j + 1] == 1) {
                place(i, j, 0);
                place(i - 1, j + 1, 1);
            }
        }
    /// mỗi lần tìm được ô đặt được luôn thì bfs
    bfs(); int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (col[i][j] == 1) {
                dfs(i, j, -1);
                if (col[i][j] == -1)
                    res += dp[1][i][j];
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (col[i][j] == 2)
                res += a[i][j];
    cout << res;
}