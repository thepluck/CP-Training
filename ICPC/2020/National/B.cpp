#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};

int main() {
    //freopen("input.txt", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 || m == 0) break;
        vector <vector <int>> a(n + 1,
        vector <int> (m + 1));
        vector <vector <int>> d(n + 1,
        vector <int> (m + 1, -1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char c; cin >> c;
                if (c == '#') a[i][j] = 0;
                if (c == '.') a[i][j] = 1;
                if (c == '@') a[i][j] = 2;
            }
        deque <pair <int, int>> dq;
        if (a[1][1] != 2) {
            d[1][1] = a[1][1];
            if (a[1][1])
                dq.emplace_back(1, 1);
            else dq.emplace_front(1, 1);
        }
        for (int i = 1; i <= n; i++)
            if (a[i][1] != 2) {
                d[i][1] = a[i][1];
                if (a[i][1])
                    dq.emplace_back(i, 1);
                else dq.emplace_front(i, 1);
            }
        for (int j = 2; j <= m; j++)
            if (a[n][j] != 2) {
                d[n][j] = a[n][j];
                if (a[n][j])
                    dq.emplace_back(n, j);
                else dq.emplace_front(n, j);
            }
        while (dq.size()) {
            int x, y;
            tie(x, y) = dq.front();
            dq.pop_front();
            for (int k = 0; k < 8; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (i < 1 || i > n || j < 1
                || j > m || ~d[i][j] ||
                a[i][j] == 2) continue;
                d[i][j] = d[x][y] + a[i][j];
                if (a[i][j])
                    dq.emplace_back(i, j);
                else dq.emplace_front(i, j);
            }
        }
        int res = -1;
        for (int j = 1; j <= m; j++)
            if (~d[1][j]) {
                if (res < 0) res = d[1][j];
                else cmin(res, d[1][j]);
            }
        for (int i = 2; i <= n; i++)
            if (~d[i][m]) {
                if (res < 0) res = d[i][m];
                else cmin(res, d[i][m]);
            }
        cout << res << '\n';
    }
}