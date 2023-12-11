#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

int n, numEdge;
bool mark[N * N];
vector<array<int, 2>> adj[N * N];

void euler(int u, vector<array<int, 2>> &path) {
    while (!adj[u].empty()) {
        int v = adj[u].back()[0];
        int ind = adj[u].back()[1];
        adj[u].pop_back();
        if (mark[ind]) {
            continue;
        }
        mark[ind] = true;
        euler(v, path);
        path.push_back({u, ind});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        x += 1000;
        y += 1000;
        u += 1000;
        v += 1000;
        if (x > u || y > v) {
            swap(x, u);
            swap(y, v);
        }
        int dx = (u - x > 0);
        int dy = (v - y > 0);
        while (x != u || y != v) {
            int a = x * N + y;
            int b = (x + dx) * N + (y + dy);
            adj[a].push_back({b, numEdge});
            adj[b].push_back({a, numEdge});
            ++numEdge;
            x += dx;
            y += dy;
        }
    }
    vector<int> oddDegVex;
    for (int i = 0; i < N * N; ++i) {
        if (adj[i].size() % 2) {
            oddDegVex.push_back(i);
        }
    }
    int added = 0;
    for (int i = 0; i < (int) oddDegVex.size(); i += 2) {
        int a = oddDegVex[i];
        int b = oddDegVex[i + 1];
        adj[a].push_back({b, numEdge + added});
        adj[b].push_back({a, numEdge + added});
        ++added;
    }
    vector<vector<int>> ans;
    for (int u = 0; u < N * N; ++u) {
        vector<array<int, 2>> path;
        euler(u, path);
        reverse(path.begin(), path.end());
        if (path.size() > 1) {
            int s = 0;
            vector<int> tmp;
            bool cycle = true;
            for (int i = 0; i < (int) path.size(); ++i) {
                if (path[i][1] >= numEdge) {
                    s = (i + 1) % path.size();
                    cycle = false;
                }
            }
            for (int i = 0; i < (int) path.size() + cycle; ++i) {
                tmp.push_back(path[s][0]);
                if (path[s][1] >= numEdge) {
                    ans.push_back(tmp);
                    tmp.clear();
                }
                s = (s + 1) % path.size();
            }
            if (!tmp.empty()) {
                ans.push_back(tmp);
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto path : ans) {
        cout << path.size() << '\n';
        for (auto p : path) {
            cout << p / N - 1000 << ' ' << p % N - 1000 << '\n';
        }
    }
    return 0;
}

/*

4
0 0 0 1
0 1 1 1
1 1 1 0
1 0 0 0

1
-1000 -1000 -1000 -998

6
2 1 2 4
2 4 6 4
6 4 6 1
6 1 2 1
4 -1 4 6
3 2 5 2
*/


