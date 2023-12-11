#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int a[N], dep[N], par[N];
vector <int> adj[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, sum = 0; cin >> n;
    for (int u = 2; u <= n; u++) {
        cin >> par[u] >> a[u];
        adj[par[u]].push_back(u);
    }
    queue <int> que; que.push(1);
    while (que.size()) {
        int u = que.front(); que.pop();
        if (dep[u] & 1) sum ^= a[u];
        for (int v : adj[u]) {
            dep[v] = dep[u] ^ 1;
            que.push(v);
        }
    }
    if (!sum) return cout << 0, 0;
    int res = 0;
    for (int u = 2; u <= n; u++)
        if (dep[u] & 1) {
            if ((a[u] ^ sum) < a[u]) res++;
        }
        else {
            int need = a[par[u]] ^ sum;
            if (need > a[par[u]] &&
            a[u] >= need - a[par[u]]) res++;
        }
    cout << res << '\n';
}