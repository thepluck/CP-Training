#include <bits/stdc++.h>

using namespace std;

const int MAXN = 605;

vector <int> adj[MAXN], lst[MAXN];
bool vis[MAXN]; int edge[MAXN];

void DFS(int u, vector <int> &res) {
    vis[u] = true; res.back()++;
    for (int v : adj[u])
        if (!vis[v]) DFS(v, res);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, sum = 0; cin >> N;
    for (int i = 1; i <= N; i++) {
        int m; cin >> m;
        for (int u = 1; u <= N; u++) {
            adj[u].clear();
            vis[u] = false;
        }
        sum += m; edge[i] = m;
        while (m--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int u = 1; u < N; u++)
            if (!vis[u]) {
                lst[i].emplace_back();
                DFS(u, lst[i]);
            }
    }
    sum /= (N - 2); size_t siz = N;
    for (int i = 1; i <= N; i++) {
        if (edge[i] == sum) {
            cout << lst[i].size() + 1 << '\n';
            lst[i].push_back(1);
            sort(lst[i].begin(), lst[i].end());
            for (int x : lst[i])
                cout << x << ' ';
            return 0;
        }
        siz = min(siz, lst[i].size());
    }
    vector <int> ans(siz, 0);
    for (int i = 1; i <= N; i++)
        if (lst[i].size() == siz) {
            sort(lst[i].begin(), lst[i].end());
            for (int j = 0; j < siz; j++)
                ans[j] = max(ans[j], lst[i][j]);
        }
    if (accumulate(ans.begin(),
    ans.end(), 0) < N) ans[0]++;
    cout << siz << '\n';
    for (int x : ans) cout << x << ' ';
}