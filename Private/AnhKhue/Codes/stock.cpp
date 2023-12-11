#include <bits/stdc++.h>

using namespace std;

const int N = 305;

vector <int> adj[N];
bool vs[N]; queue <int> q;

int main() {
    freopen("stock.in", "r", stdin);
    freopen("stock.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, t, cnt = 0;
    cin >> n >> t;
    while (t--) {
        int u, v; cin >> u >> v;
        memset(vs, 0, sizeof vs);
        vs[v] = 1; q.push(v);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : adj[x])
                if (!vs[y]) {
                    vs[y] = 1; q.push(y);
                }
        }
        if (vs[u]) cnt++;
        else adj[u].push_back(v);
    }
    cout << cnt << '\n';
}
