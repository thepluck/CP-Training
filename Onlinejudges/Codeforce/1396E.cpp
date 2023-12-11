#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> adj[N];
int siz[N], n, dis[N], ptr[N];
long long need, low, high;
vector<int> vec[N];
bool used[N];
vector<int> rem;

void dfs1(int u, int p) {
    siz[u] = 1;
    for (int v : adj[u])
        if (v != p) {
            dfs1(v, u);
            siz[u] += siz[v];
        }
}

void dfs2(int u, int p) {
    adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
    ptr[u] = adj[u].size();
    siz[u] = 1;
    for (int v : adj[u]) {
        dfs2(v, u);
        siz[u] += siz[v];
    }
    low += siz[u] & 1;
    high += siz[u];
}

void dfs3(int u, int p) {
    if (!used[u])
        rem.push_back(u);
    for (int v : adj[u])
        if (v != p) dfs3(v, u);
}

int find_centroid() {
    int u = 1;
    while (true) {
        bool flag = 0;
        for (int v : adj[u])
            if (siz[v] < siz[u] && siz[v] * 2 >= n) {
                u = v; flag = 1; break;
            }
        if (!flag) break;
    }
    return u;
}

void bfs(int u, vector<int> &vec) {
    vec.push_back(u); dis[u] = 1;
    for (int i = 0; i < vec.size(); i++) {
        u = vec[i];
        for (int v : adj[u])
            if (siz[v] < siz[u]) {
                dis[v] = dis[u] + 1;
                vec.push_back(v);
            }
    }
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> need;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    int root = find_centroid();
    siz[root] = n;
    set<pair<int, int>> cur;
    for (int u : adj[root]) {
        dfs2(u, root);
        bfs(u, vec[u]);
        cur.emplace(siz[u], u);
    }
    if (need < low || need > high || (need - low) & 1)
        return cout << "NO\n", 0;
    cout << "YES\n";
    while (high > need) {
        int u = cur.rbegin()->second;
        cur.erase(make_pair(siz[u], u));
        for (int i = vec[u].size() - 1; i >= 0; i--) {
            int v = vec[u][i];
            while (ptr[v] && used[adj[v][ptr[v] - 1]])
                ptr[v]--;
            if (!ptr[v] || high - need < dis[v] * 2) {
                vec[u].pop_back();
                continue;
            }
            high -= dis[v] * 2;
            siz[u] -= 2;
            int x = adj[v][--ptr[v]];
            while (ptr[v] && used[adj[v][ptr[v] - 1]])
                ptr[v]--;
            int y = ptr[v] ? adj[v][--ptr[v]] : v;
            cout << x << ' ' << y << '\n';
            used[x] = used[y] = 1;
            break;
        }
        cur.emplace(siz[u], u);
    }
    dfs3(root, 0);
    for (int i = 0; i < rem.size() / 2; i++)
        cout << rem[i] << ' ' << rem[i + rem.size() / 2] << '\n';
}