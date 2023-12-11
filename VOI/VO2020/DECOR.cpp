#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, m, k, sz[N], id[N];
vector <int> adj[N];
int num, cnt[N], col[N];
bool vs[N]; queue <int> q;

void bfs() {
    for (int i = 1; i <= n; i++) {
        if (vs[i]) continue;
        vs[i] = 1; num++; q.push(i);
        while (q.size()) {
            int u = q.front(); q.pop();
            sz[id[u] = num] += col[u];
            for (int v : adj[u])
                if (!vs[v]) {
                    vs[v] = 1; q.push(v);
                }
        }
    }
}

int check(int l) {
    int cur = 0;
    for (int i = 1; i <= num; i++)
        cnt[i] = 0;
    for (int i = 1; i < l; i++)
        cur += cnt[id[i]]++ < sz[id[i]];
    for (int i = l; i <= n; i++) {
        cur += cnt[id[i]]++ < sz[id[i]];
        if (cur >= l - k) return i;
        cur -= --cnt[id[i - l + 1]]
        < sz[id[i - l + 1]];
    }
    return 0;
}

int main() {
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        col[i] = c - '0';
    }
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(); int lo = 0, hi = n;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (check(mi)) lo = mi;
        else hi = mi - 1;
    }
    if (lo == 0) cout << -1;
    else {
        int r = check(lo);
        cout << r - lo + 1 << ' ' << r;
    }
}