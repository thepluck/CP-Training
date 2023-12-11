#include <bits/stdc++.h>

using namespace std;

char read_char() {
    static char buf[1000000];
    static char *p = buf, *q = buf;
    return p == q && (q = (p = buf) +
        fread(buf, 1, 1000000, stdin),
        p == q) ? EOF : *p++;
}

int read_int() {
    char c = read_char();
    while (c != '-' && !isdigit(c))
        c = read_char();
    bool neg = 0;
    if (c == '-') {
        neg = 1; c = read_char();
    }
    int res = c - '0';
    while (isdigit(c = read_char()))
        res = res * 10 + c - '0';
    return neg ? -res : res;
}

#define fi first
#define se second

const int MAXN = 10005;
const int MAXQ = 1000005;

short D[MAXN], ans[MAXQ];
bitset <MAXN> B[MAXN];
vector <int> alv, tmp;
int N, M, Q; short deg[MAXN];
vector <pair <int, int>> que[MAXN];

void BFS(int u) {
    alv.clear(); queue <int> que;
    for (int v = 0; v < N; v++)
        if (B[u][v]) {
            D[v] = 1; que.push(v);
        }
        else if (u != v) {
            alv.push_back(v);
            D[v] = -1;
        }
    while (que.size()) {
        int v = que.front(); que.pop();
        tmp.clear();
        for (int w : alv)
            if (B[v][w]) {
                D[w] = D[v] + 1;
                que.push(w);
            } else tmp.push_back(w);
        alv = tmp;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    N = read_int(); M = read_int();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            B[i][j] = i != j;
    for (int i = 1, u, v; i <= M; i++) {
        u = read_int(); v = read_int();
        B[u][v] = B[v][u] = 0;
        deg[u]++; deg[v]++;
    }
    for (int u = 0; u < N; u++)
        if (deg[u] >= N / 2 - 1) BFS(u);
    Q = read_int();
    for (int i = 1, u, v; i <= Q; i++) {
        u = read_int(); v = read_int();
        if (u == v) continue;
        if (deg[u] < deg[v]) swap(u, v);
        if (deg[u] < N / 2 - 1
        && deg[v] < N / 2 - 1)
            ans[i] = B[u][v] ? 1 : 2;
        else que[u].emplace_back(v, i);
    }
    for (int u = 0; u < N; u++)
        if (que[u].size()) {
            BFS(u);
            for (auto q : que[u])
                ans[q.se] = D[q.fi];
        }
    for (int i = 1; i <= Q; i++)
        printf("%d\n", ans[i]);
}