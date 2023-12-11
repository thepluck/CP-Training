#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 105;
const int M = 10205;

int a[N][N], p[N][N], len[M], col[M], b[N][N];
vector<pair<int, int>> ans[M];

int rand(int l, int r) {
    return uniform_int_distribution<int> (l, r)(rng);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, k, n;
    cin >> r >> c >> k >> n;
    vector<int> one, two;
    for (int i = 1; i <= n; i++) {
        cin >> len[i] >> col[i];
        if (len[i] == 1) one.push_back(i);
        else two.push_back(i);
    }
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            cin >> p[i][j];
    int res = -1;
    for (int step = 0; step < 5; step++) {
        memset(a, 0, sizeof a);
        shuffle(two.begin(), two.end(), rng);
        shuffle(one.begin(), one.end(), rng);
        for (int i = 1, ptr = 0; i <= r; i++)
            for (int j = 1; j + 1 <= c && ptr < two.size(); j += 2)
                a[i][j] = a[i][j + 1] = two[ptr++];
        int cur = 0;
        for (int i = 1, ptr = 0; i <= r; i++)
            for (int j = 1; j <= c; j++) {
                if (!a[i][j]) a[i][j] = one[ptr++];
                if (i > 1 && a[i][j] != a[i - 1][j])
                    cur += p[col[a[i][j]]][col[a[i - 1][j]]];
                if (j > 1 && a[i][j] != a[i][j - 1])
                    cur += p[col[a[i][j]]][col[a[i][j - 1]]];
            }
        int start = clock();
        while (clock() - start < 20 * CLOCKS_PER_SEC) {
            int x = rand(1, r), y = rand(1, c);
            int u = rand(1, r), v = rand(1, c);
            if (len[a[x][y]] > len[a[u][v]]) continue;
            if (len[a[x][y]] == 1) {
                if (len[a[u][v]] == 1) {
                    set<pair<int, int>> need;
                    need.emplace(x, y);
                    need.emplace(u, v);
                    if (x < r) need.emplace(x + 1, y);
                    if (y < c) need.emplace(x, y + 1);
                    if (u < r) need.emplace(u + 1, v);
                    if (v < c) need.emplace(u, v + 1);
                    int nxt = cur;
                    for (auto [i, j] : need) {
                        if (i > 1 && a[i][j] != a[i - 1][j])
                            nxt -= p[col[a[i][j]]][col[a[i - 1][j]]];
                        if (j > 1 && a[i][j] != a[i][j - 1])
                            nxt -= p[col[a[i][j]]][col[a[i][j - 1]]];
                    }
                    swap(a[x][y], a[u][v]);
                    for (auto [i, j] : need) {
                        if (i > 1 && a[i][j] != a[i - 1][j])
                            nxt += p[col[a[i][j]]][col[a[i - 1][j]]];
                        if (j > 1 && a[i][j] != a[i][j - 1])
                            nxt += p[col[a[i][j]]][col[a[i][j - 1]]];
                    }
                    if (nxt > cur || (nxt == cur && rand(0, 1))) cur = nxt;
                    else swap(a[x][y], a[u][v]);
                } else {
                    int d1 = 0;
                    for (int d = 0; d < 4; d++)
                        if (a[u + dx[d]][v + dy[d]] == a[u][v])
                            d1 = d;
                    bool flag = true;
                    for (int d = 0; d < 4 && flag; d++)
                        if (len[a[x + dx[d]][y + dy[d]]] == 1) {
                            set<pair<int, int>> need;
                            need.emplace(x, y);
                            need.emplace(u, v);
                            need.emplace(x + dx[d], y + dy[d]);
                            need.emplace(u + dx[d1], v + dy[d1]);
                            if (x < r) need.emplace(x + 1, y);
                            if (y < c) need.emplace(x, y + 1);
                            if (u < r) need.emplace(u + 1, v);
                            if (v < c) need.emplace(u, v + 1);
                            if (x + dx[d] < r) need.emplace(x + dx[d] + 1, y + dy[d]);
                            if (y + dy[d] < c) need.emplace(x + dx[d], y + dy[d] + 1);
                            if (u + dx[d1] < r) need.emplace(u + dx[d1] + 1, v + dy[d1]);
                            if (v + dy[d1] < c) need.emplace(u + dx[d1], v + dy[d1] + 1);
                            int nxt = cur;
                            for (auto [i, j] : need) {
                                if (i > 1 && a[i][j] != a[i - 1][j])
                                    nxt -= p[col[a[i][j]]][col[a[i - 1][j]]];
                                if (j > 1 && a[i][j] != a[i][j - 1])
                                    nxt -= p[col[a[i][j]]][col[a[i][j - 1]]];
                            }
                            swap(a[x][y], a[u][v]);
                            swap(a[x + dx[d]][y + dy[d]], a[u + dx[d1]][v + dy[d1]]);
                            for (auto [i, j] : need) {
                                if (i > 1 && a[i][j] != a[i - 1][j])
                                    nxt += p[col[a[i][j]]][col[a[i - 1][j]]];
                                if (j > 1 && a[i][j] != a[i][j - 1])
                                    nxt += p[col[a[i][j]]][col[a[i][j - 1]]];
                            }
                            if (nxt > cur || (nxt == cur && rand(0, 1))) {
                                cur = nxt; flag = false;
                            } else {
                                swap(a[x][y], a[u][v]);
                                swap(a[x + dx[d]][y + dy[d]], a[u + dx[d1]][v + dy[d1]]);
                            }
                        }
                }
            } else {
                int d1 = 0, d2 = 0;
                for (int d = 0; d < 4; d++) {
                    if (a[x + dx[d]][y + dy[d]] == a[x][y])
                        d1 = d;
                    if (a[u + dx[d]][v + dy[d]] == a[u][v])
                        d2 = d;
                }
                set<pair<int, int>> need;
                need.emplace(x, y);
                need.emplace(u, v);
                need.emplace(x + dx[d1], y + dy[d1]);
                need.emplace(u + dx[d2], v + dy[d2]);
                if (x < r) need.emplace(x + 1, y);
                if (y < c) need.emplace(x, y + 1);
                if (u < r) need.emplace(u + 1, v);
                if (v < c) need.emplace(u, v + 1);
                if (x + dx[d1] < r) need.emplace(x + dx[d1] + 1, y + dy[d1]);
                if (y + dy[d1] < c) need.emplace(x + dx[d1], y + dy[d1] + 1);
                if (u + dx[d2] < r) need.emplace(u + dx[d2] + 1, v + dy[d2]);
                if (v + dy[d2] < c) need.emplace(u + dx[d2], v + dy[d2] + 1);
                int nxt = cur;
                for (auto [i, j] : need) {
                    if (i > 1 && a[i][j] != a[i - 1][j])
                        nxt -= p[col[a[i][j]]][col[a[i - 1][j]]];
                    if (j > 1 && a[i][j] != a[i][j - 1])
                        nxt -= p[col[a[i][j]]][col[a[i][j - 1]]];
                }
                swap(a[x][y], a[u][v]);
                swap(a[x + dx[d1]][y + dy[d1]], a[u + dx[d2]][v + dy[d2]]);
                for (auto [i, j] : need) {
                    if (i > 1 && a[i][j] != a[i - 1][j])
                        nxt += p[col[a[i][j]]][col[a[i - 1][j]]];
                    if (j > 1 && a[i][j] != a[i][j - 1])
                        nxt += p[col[a[i][j]]][col[a[i][j - 1]]];
                }
                if (nxt > cur || (nxt == cur && rand(0, 1))) cur = nxt;
                else {
                    swap(a[x][y], a[u][v]);
                    swap(a[x + dx[d1]][y + dy[d1]], a[u + dx[d2]][v + dy[d2]]);
                }
            }
        }
        if (cur > res) {
            for (int i = 1; i <= r; i++)
                for (int j = 1; j <= c; j++)
                    b[i][j] = a[i][j];
            res = cur;
        }
    }
    
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++) {
            assert(1 <= b[i][j] && b[i][j] <= n);
            if (len[b[i][j]] == 1)
                ans[b[i][j]].emplace_back(i, j);
            else if (i > 1 && b[i][j] == b[i - 1][j]) {
                ans[b[i][j]].emplace_back(i, j);
                ans[b[i][j]].emplace_back(i - 1, j);
            } else if (j > 1 && b[i][j] == b[i][j - 1]) {
                ans[b[i][j]].emplace_back(i, j);
                ans[b[i][j]].emplace_back(i, j - 1);
            }
        }
    for (int x = 1; x <= n; x++) {
        for (auto [i, j] : ans[x])
            cout << i << ' ' << j << ' ';
        cout << '\n';
    }
    cerr<<res<<'\n';
}