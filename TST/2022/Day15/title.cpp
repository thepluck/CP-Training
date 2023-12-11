#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

const int N = 3e5 + 100;
const int MOD = 998244353;

pair<int, int> a[N], que[N];
int p[11][N], idx[N];
int seg[N * 4], lo, hi, pos;

void add(int i, int l, int r, int v) {
    if (l >= lo && r <= hi) {
        seg[i] += v; return;
    }
    int m = (l + r) / 2;
    if (m >= lo) add(i * 2, l, m, v);
    if (m < hi) add(i * 2 + 1, m + 1, r, v);
}

void get(int i, int l, int r) {
    pos += seg[i];
    if (l != r) {
        int m = (l + r) / 2;
        if (m >= lo) get(i * 2, l, m);
        else get(i * 2 + 1, m + 1, r);
    }
}

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r, c, n, q, b;
    while (cin >> r >> c >> n >> q >> b) {
        bool all1 = true, all2 = true;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first >> a[i].second;
            p[a[i].first][a[i].second] = i;
        }
        for (int i = 1; i <= q; i++) {
            string dir;
            cin >> que[i].first >> dir;
            if (dir == "up") que[i].second = 0;
            else if (dir == "down") que[i].second = 1;
            else if (dir == "left") que[i].second = 2;
            else que[i].second = 3;
            if (que[i].second < 2) all2 = false;
            else all1 = false;
        }
        if (all1) {
            for (int i = 1; i <= q; i++) {
                int j = que[i].first;
                int x, y; tie(x, y) = a[j];
                while (x >= 0 && x < r && p[x][y])
                    x += dx[que[i].second];
                int tmp = a[j].first;
                if (x < 0 || x >= r) continue;
                while (x != tmp) {
                    p[x][y] = p[x + dx[que[i].second ^ 1]][y];
                    a[p[x][y]].first += dx[que[i].second];
                    x += dx[que[i].second ^ 1];
                }
                p[x][y] = 0;
            }
        } else if (all2) {
            for (int i = 0; i < r; i++) {
                memset(seg, 0, sizeof seg);
                int cnt = 0;
                for (int j = 0; j < c; j++)
                    if (p[i][j]) idx[p[i][j]] = ++cnt;
                for (int j = 0; j < c; j++)
                    if (p[i][j]) {
                        lo = idx[p[i][j]], hi = lo;
                        add(1, 1, cnt, j);
                    }
                for (int j = 1; j <= q; j++) {
                    if (a[que[j].first].first != i) continue;
                    if (que[j].second == 2) {
                        int l = 1, r = idx[que[j].first];
                        pos = 0; lo = idx[que[j].first];
                        get(1, 1, cnt);
                        int tmp = pos;
                        while (l < r) {
                            lo = (l + r) / 2;
                            pos = 0; get(1, 1, cnt);
                            if (tmp - pos == idx[que[j].first] - lo)
                                r = lo;
                            else l = lo + 1;
                        }
                        pos = 0; lo = r; get(1, 1, cnt);
                        if (pos == 0) continue;
                        lo = r; hi = idx[que[j].first];
                        add(1, 1, cnt, -1);
                    } else if (que[j].second == 3) {
                        int l = idx[que[j].first], r = cnt;
                        pos = 0; lo = idx[que[j].first];
                        get(1, 1, cnt);
                        int tmp = pos;
                        while (l < r) {
                            lo = (l + r + 1) / 2;
                            pos = 0; get(1, 1, cnt);
                            if (tmp - pos == idx[que[j].first] - lo)
                                l = lo;
                            else hi = lo - 1;
                        }
                        pos = 0; lo = l; get(1, 1, cnt);
                        if (pos == c - 1) continue;
                        lo = idx[que[j].first]; hi = l;
                        add(1, 1, cnt, 1);
                    }
                }
                for (int j = 0; j < c; j++)
                    if (p[i][j]) {
                        lo = idx[p[i][j]];
                        pos = 0; get(1, 1, cnt);
                        a[p[i][j]].second = pos;
                    }
            }
            memset(p, 0, sizeof p);
            for (int i = 1; i <= n; i++)
                p[a[i].first][a[i].second] = i;
        } 
        int res = 0, cur = 1;
        for (int i = r - 1; i >= 0; i--)
            for (int j = c - 1; j >= 0; j--) {
                res = add(res, mul(cur, p[i][j]));
                cur = mul(cur, b);
            }
        cout << res << '\n';
    }
}