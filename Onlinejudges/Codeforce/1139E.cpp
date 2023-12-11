#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 5005;

int n, m, q, que[N], ans[N];
int mat[N], vis[N], tim;
bool rmv[N]; int p[N], c[N];
vector <int> adj[N];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> que[i];
        rmv[que[i]] = 1;
    }
}

bool dfs(int u) {
    if (!cmax(vis[u], tim)) return 0;
    for (int v : adj[u]) {
        if (mat[v] < 0 || dfs(mat[v])) {
            mat[v] = u; return 1;
        }
    }
    return 0;
}

void process() {
    for (int i = 1; i <= m; i++)
        mat[i] = -1;
    for (int i = 1; i <= n; i++)
        if (!rmv[i])
            adj[p[i]].eb(c[i]);
    int cur = 0;
    for (int i = q; i > 0; i--) {
        tim++;
        while (dfs(cur)) {
            cur++; tim++;
        }
        ans[i] = cur;
        adj[p[que[i]]].eb(c[que[i]]);
    }
}

void output() {
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    input(); process(); output();
}