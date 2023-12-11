#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector <int> vals, adj[N * 2];
int a[N], b[N], deg[N * 2];
bool vs[N * 2]; queue <int> q;

int bfs(int u) {
    vs[u] = 1; q.push(u);
    int edges = 0, nodes = 0;
    int fi = -1, se = -1;
    while (q.size()) {
        u = q.front(); q.pop();
        if (u > fi) {
            se = fi; fi = u;
        }
        else if (u > se) se = u;
        edges += deg[u]; nodes++;
        for (int v : adj[u])
            if (!vs[v]) {
                vs[v] = 1; q.push(v);
            }
    }
    edges /= 2;
    if (nodes == 1) return 0;
    if (edges > nodes) return -1;
    if (edges < nodes) return vals[se];
    return vals[fi];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n, res = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        vals.push_back(a[i]);
        vals.push_back(b[i]);
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(),
    vals.end()), vals.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vals.begin(),
        vals.end(), a[i]) - vals.begin();
        b[i] = lower_bound(vals.begin(),
        vals.end(), b[i]) - vals.begin();
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
        deg[a[i]]++; deg[b[i]]++;
    }
    n = vals.size();
    for (int u = 0; u < n; u++) {
        if (vs[u]) continue;
        int cur = bfs(u);
        if (cur < 0) {
            cout << "-1\n"; return 0;
        }
        res = max(res, cur);
    }
    cout << res << '\n';
}