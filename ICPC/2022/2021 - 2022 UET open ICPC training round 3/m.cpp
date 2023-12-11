#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int par[N], nxt[N];

int root(int u) {
    return par[u] ? par[u] = root(par[u]) : u;
}

void join_two(int u, int v) {
    u = root(u); v = root(v);
    if (u != v) par[v] = u;
}

void join_range(int x, int y) {
    while (nxt[x] <= y) {
        join_two(x, nxt[x]);
        tie(x, nxt[x]) = make_pair(nxt[x], nxt[y]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        nxt[i] = i + 1;
    while (q--) {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if (cmd == 1) join_two(u, v);
        else if (cmd == 2) join_range(u, v);
        else cout << (root(u) == root(v) ? "YES\n" : "NO\n");
    }
}