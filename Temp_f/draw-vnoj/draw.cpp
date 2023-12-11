#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int N = 2005;
const int M = 4000005;

vector<int> adj[M], odd;
bool vis1[M], vis2[M];
int U[M], V[M];

int id(int x, int y) {
    return (x + 1000) * N + (y + 1000);
}

void dfs1(int u) {
    vis1[u] = true;
    if (adj[u].size() & 1)
        odd.push_back(u);
    for (int i : adj[u]) {
        int v = u ^ U[i] ^ V[i];
        if (!vis1[v]) dfs1(v);
    }
}

void dfs2(int u) {
    while (adj[u].size()) {
        int i = adj[u].back();
        adj[u].pop_back();
        if (vis2[i]) continue;
        int v = u ^ U[i] ^ V[i];
        if (u != U[i]) swap(U[i], V[i]);
        vis2[i] = true; dfs2(v);
        odd.push_back(i);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m = 0; cin >> n;
    vector<int> src;
    for (int i = 0; i < n; i++) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if (x > u || y > v) {
            swap(x, u); swap(y, v);
        }
        if (x == u) {
            for (int k = y; k < v; k++) {
                U[m] = id(x, k);
                V[m] = id(x, k + 1);
                adj[U[m]].push_back(m);
                adj[V[m]].push_back(m);
                m++;
            }
        }
        else {
            for (int k = x; k < u; k++) {
                U[m] = id(k, y);
                V[m] = id(k + 1, y);
                adj[U[m]].push_back(m);
                adj[V[m]].push_back(m);
                m++;
            }
        }
        src.push_back(id(x, y));
    }
    int edge = m;
    vector<vector<int>> ans;
    for (int u : src) {
        if (vis1[u]) continue;
        odd.clear(); dfs1(u);
        for (int i = 0; i < odd.size(); i += 2) {
            adj[odd[i]].push_back(edge);
            adj[odd[i + 1]].push_back(edge);
            U[edge] = odd[i];
            V[edge++] = odd[i + 1];
        }
        odd.clear(); dfs2(u);
        reverse(odd.begin(), odd.end());
        for (int i = 0; i < odd.size(); i++)
            if (odd[i] >= m) {
                rotate(odd.begin(),
                odd.begin() + i, odd.end());
                break;
            }
        for (int i = 0; i < odd.size(); i++) {
            if (odd[i] >= m) continue;
            vector<int> cur(1, U[odd[i]]);
            while (i < odd.size() && odd[i] < m)
                cur.push_back(V[odd[i++]]);
            ans.push_back(cur);
        }
    }
    cout << ans.size() << '\n';
    for (auto cur : ans) {
        cout << cur.size() << '\n';
        for (int u : cur)
            cout << u / N - 1000 << ' ' << u % N - 1000 << '\n';
        cout << '\n';
    }
}