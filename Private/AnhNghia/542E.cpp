#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int M = 100005;

int n, m, d[N], cmp, cur;
vector <int> g[N], cc[N];
queue <int> q;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

bool check() {
    fill(d + 1, d + n + 1, -1);
    bool flag = 0;
    for (int i = 1; i <= n; i++)
        if (d[i] < 0) {
            d[i] = 0; cmp++; q.push(i);
            while (q.size()) {
                int u = q.front(); q.pop();
                cc[cmp].push_back(u);
                for (int v : g[u])
                    if (d[v] < 0) {
                        d[v] = d[u] ^ 1;
                        q.push(v);
                    }
                    else if (d[u] == d[v])
                        flag = 1;
            }
        }
    return flag;
}

void bfs(int u) {
    fill(d + 1, d + n + 1, -1);
    d[u] = 0; q.push(u);
    while (q.size()) {
        u = q.front(); q.pop();
        cur = max(cur, d[u]);
        for (int v : g[u])
            if (d[v] < 0) {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }
}

void process() {
    if (check()) {
        cout << "-1\n"; return;
    }
    int tot = 0;
    for (int i = 1; i <= cmp; i++) {
        cur = 0;
        for (int u : cc[i]) bfs(u);
        tot += cur;
    }
    cout << tot << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    cin.tie(0)->sync_with_stdio(0);
    input(); process();
}