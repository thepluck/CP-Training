#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
const int INF = 0x3f3f3f3f;

int val[MAXN][MAXN], nxt[MAXN];
int vis[MAXN], timer; int M, N, Q;

int add(int x, int y, int m) {
    return (x += y) >= m ? x - m : x < 0 ? x + m : x;
}

int move(int i, int j) {
    int tmp = -INF; j = add(j, 1, N);
    for (int k = -1; k <= 1; k++)
        tmp = max(tmp, val[add(i, k, M)][j]);
    for (int k = -1; k <= 1; k++)
        if (tmp == val[add(i, k, M)][j])
            return add(i, k, M);
    return 0;
}

void recalc(int i, int j) {
    int x = j, l = i, r = i;
    while (x > 0) {
        int nl = INF, nr; x--;
        if (l <= r) {
            for (int k = -1; k <= 1; k++) {
                int t = move(add(l, k, M), x);
                if (l <= t && t <= r) {
                    nl = l + k; break;
                }
            }
            if (nl == INF) return;
            for (int k = 1; k >= -1; k--) {
                int t = move(add(r, k, M), x);
                if (l <= t && t <= r) {
                    nr = r + k; break;
                }
            }
            if (nr - nl + 1 >= M) {
                l = 0; r = M - 1;
            } else {
                l = nl; r = nr;
            }
        } else {
            for (int k = -1; k <= 1; k++) {
                int t = move(add(l, k, M), x);
                if (l <= t || t <= r) {
                    nl = l + k; break;
                }
            }
            if (nl == INF) return;
            for (int k = 1; k >= -1; k--) {
                int t = move(add(r, k, M), x);
                if (l <= t || t <= r) {
                    nr = r + k; break;
                }
            }
            if (nl < nr) {
                l = 0; r = M - 1;
            } else {
                l = nl; r = nr;
            }
        }
        l = add(l, 0, M); r = add(r, 0, M);
    }
    for (int t = j; t < N; t++) {
        i = move(i, j); j = add(j, 1, N);
    }
    while (true) {
        nxt[l] = i; if (l == r) break;
        l = add(l, 1, M);
    }
}

void change(int i, int j, int v) {
    val[i][j] = v;
    for (int k = -2; k <= 2; k++)
        recalc(add(i, k, M), add(j, -1, N));
}

void move(int &x, int &y, int k) {
    if (k <= N) {
        while (k--) {
            x = move(x, y); y = add(y, 1, N);
        }
        return;
    }
    while (y > 0) {
        x = move(x, y); y = add(y, 1, N); k--;
    }
    int len = 0; timer++;
    while (vis[x] != timer && k >= N) {
        vis[x] = timer; x = nxt[x]; k -= N;
    }
    if (k < N) {
        while (k--) {
            x = move(x, y); y = add(y, 1, N);
        }
        return;
    }
    timer++;
    while (vis[x] != timer) {
        vis[x] = timer; x = nxt[x]; len++;
    }
    k %= len * N;
    while (k >= N) {
        x = nxt[x]; k -= N;
    }
    while (k--) {
        x = move(x, y); y = add(y, 1, N);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> val[i][j];
    for (int i = 0; i < M; i++) {
        int x = i, y = 0;
        for (int t = 0; t < N; t++) {
            x = move(x, y); y = add(y, 1, N);
        }
        nxt[i] = x;
    }
    int x = 0, y = 0; cin >> Q;
    while (Q--) {
        string cmd; cin >> cmd;
        if (cmd[0] == 'c') {
            int i, j, v;
            cin >> i >> j >> v;
            change(i, j, v);
        } else {
            int k; cin >> k; move(x, y, k);
            cout << x << ' ' << y << '\n';
        }
    }
}