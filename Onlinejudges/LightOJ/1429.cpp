#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

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

const int N = 1005;

vector <int> adj[N], rev[N];
int n, m, x[N], y[N], d[N];
queue <int> q; int vs[N], p[N];
vector <int> ext; int tim;

bool bfs() {
    for (int u = 1; u <= n; u++)
        if (!x[u]) {
            d[u] = 0; q.emplace(u);
        }
        else d[u] = -1;
    bool flag = 0;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (!y[v]) flag = 1;
            else if (d[y[v]] < 0) {
                d[y[v]] = d[u] + 1;
                q.emplace(y[v]);
            }
    }
    return flag;
}

bool dfs(int u) {
    for (int v : adj[u])
        if (!y[v] || (d[y[v]] ==
        d[u] + 1 && dfs(y[v]))) {
            x[u] = v; y[v] = u;
            return 1;
        }
    d[u] = -1; return 0;
}

int max_matching() {
    int match = 0;
    for (int u = 1; u <= n; u++)
        x[u] = y[u] = 0;
    while (bfs())
        for (int u = 1; u <= n; u++)
            if (!x[u]) match += dfs(u);
    return match;
}

void dfs1(int u) {
    vs[u] = tim;
    for (int v : adj[u])
        if (vs[v] < tim) dfs1(v);
    ext.eb(u);
}

void dfs2(int u, int r) {
    vs[u] = tim; p[u] = r;
    for (int v : rev[u])
        if (vs[v] < tim) dfs2(v, r);
}

void dfs3(int u, int r) {
    vs[u] = tim;
    for (int v : rev[u])
        if (vs[v] < tim) {
            adj[r].push_back(v);
            dfs3(v, r);
        }
}

int process() {
    n = read_int(); m = read_int();
    for (int i = 1; i <= n; i++) {
        adj[i].clear(); rev[i].clear();
    }
    ext.clear(); int scc = 0;
    for (int i = 1; i <= m; i++) {
        int u = read_int(), v = read_int();
        adj[u].eb(v); rev[v].eb(u);
    }
    tim++;
    for (int u = 1; u <= n; u++)
        if (vs[u] < tim) dfs1(u);
    reverse(ext.begin(), ext.end());
    tim++;
    for (int u : ext)
        if (vs[u] < tim) dfs2(u, ++scc);
    for (int i = 1; i <= scc; i++)
        rev[i].clear();
    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
            if (p[u] != p[v])
                rev[p[u]].push_back(p[v]);
    for (int i = 1; i <= scc; i++)
        adj[i].clear();
    tim++;
    for (int i = 1; i <= scc; i++) {
        tim++; dfs3(i, i);
    }
    return (n = scc) - max_matching();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int t = read_int();
    for (int i = 1; i <= t; i++) {
        printf("Case %d: %d\n", i, process());
    }
}