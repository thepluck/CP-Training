#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

vector <int> adj[N], in[N];

void dfs(int u, int p, int d) {
    in[d].push_back(u);
    for (int v : adj[u])
        if (v != p) {
            dfs(v, u, d + 1);
        }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        in[i].clear();
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "? " << n << ' ';
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << endl;
    int root, dis; cin >> root >> dis;
    dfs(root, 0, 0); int u = root;
    int l = dis / 2, r = dis;
    while (l <= r) {
        int m = (l + r) / 2;
        if (in[m].empty()) {
            r = m - 1; continue;
        }
        cout << "? " << in[m].size() << ' ';
        for (int v : in[m])
            cout << v << ' ';
        cout << endl;
        int v, d; cin >> v >> d;
        if (d > dis) r = m - 1;
        else {
            l = m + 1; u = v;
        }
    }
    for (int i = 1; i <= n; i++)
        in[i].clear();
    dfs(u, 0, 0);
    cout << "? " << in[dis].size() << ' ';
    for (int v : in[dis])
        cout << v << ' ';
    cout << endl;
    int v; cin >> v >> dis;
    cout << "! " << u << ' ' << v << endl;
    string cc; cin >> cc;
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}
