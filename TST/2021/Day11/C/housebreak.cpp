#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

vector <int> adj[N];
bool mark[N]; int ver[N], tim[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i <= n; i++) {
            cin >> ver[i]; tim[ver[i]] = i;
        }
        for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            int u = ver[i];
            int bestv, bestt = n + 1;
            for (int v : adj[u])
                if (tim[v] > i && tim[v] < bestt) {
                    bestt = tim[v]; bestv = v;
                }
            if (bestt == n + 1) continue;
            for (int v : adj[bestv]) mark[v] = 1;
            for (int v : adj[u])
                if (tim[v] > i && !mark[v] && v != bestv) {
                    flag = 1; break;
                }
            for (int v : adj[bestv]) mark[v] = 0;
            if (flag) break;
        }
        cout << (flag ? "NO\n" : "YES\n");
    }
}