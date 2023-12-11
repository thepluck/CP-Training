#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

vector <int> adj[N];
pair <int, int> que[N];
char ans[N]; string str;

void DFS(int u) {
    if (que[u].first == 0)
        str.push_back(char(que[u].second));
    else if (que[u].first == 2)
        ans[u] = str[que[u].second - 1];
    for (int v : adj[u]) DFS(v);
    if (que[u].first == 0) str.pop_back();
}

int main() {
    freopen("scrivener.inp", "r", stdin);
    freopen("scrivener.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q >> q;
    vector <int> cur;
    cur.push_back(0); que[0].first = 1;
    for (int i = 1; i <= q; i++) {
        char cmd; cin >> cmd;
        if (cmd == 'T') {
            char c; cin >> c; que[i] = {0, c};
            adj[i - 1].push_back(i);
            cur.push_back(i);
        }
        else if (cmd == 'U') {
            int k; cin >> k; que[i] = {1, k};
            adj[cur[cur.size() - k - 1]].push_back(i);
            cur.push_back(i);
        }
        else {
            int p; cin >> p; que[i] = {2, p};
            adj[i - 1].push_back(i);
        }
    }
    DFS(0);
    for (int i = 1; i <= q; i++)
        if (que[i].first == 2) cout << ans[i];
}