#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define fi first
#define se second

using ii = pair <int, int>;

const int N = 1005;
int a[N][N], sz[N][N], b[N][N];
int p, q, n, m;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void dfs(int x, int y) {
    a[x][y] = 1;
    if (~sz[p][q]) sz[p][q]++;
    for (int k = 0; k < 4; k++) {
        int i = x + dx[k];
        int j = y + dy[k];
        if (!i || !j) {
            sz[p][q] = -1; continue;
        }
        if (i > n || j > m) {
            sz[p][q] = -1; continue;
        }
        if (a[i][j]) continue;
        dfs(i, j);
    }
}

void cal(int x, int y) {
    b[x][y] = 1;
    for (int k = 0; k < 4; k++) {
        int i = x + dx[k];
        int j = y + dy[k];
        if (!i || !j || i > n ||
        j > m || b[i][j]) continue;
        cal(i, j);
    }
}

int main() {
    freopen("hanoi.inp", "r", stdin);
    freopen("hanoi.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int k; cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char x; cin >> x;
            if (x == '#')
                b[i][j] = a[i][j] = 1;
        }
    vector <ii> lakes;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!a[i][j]) {
                p = i; q = j;
                dfs(i, j);
                if (~sz[i][j])
                    lakes.eb(i, j);
            }
    sort(lakes.begin(), lakes.end(),
    [&](ii x, ii y) {
        return sz[x.fi][x.se] < sz[y.fi][y.se];
    });
    int res = 0;
    for (int i = 0; i < lakes.size() - k; i++) {
        res += sz[lakes[i].fi][lakes[i].se];
        cal(lakes[i].fi, lakes[i].se);
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << (b[i][j] ? '#' : '.');
        cout << '\n';
    }
}