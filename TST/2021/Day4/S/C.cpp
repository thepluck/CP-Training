#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int MOD = 1000003271;
const int BASE = 1000004123;

vector <int> adj[N];
map <int, int> cnt[N];

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int hashVector(const vector <int> &v) {
    int res = 0;
    for (int x : v)
        res = add(mul(res, BASE), x);
    return res;
}

int main() {
    freopen("chinaflu.inp", "r", stdin);
    freopen("chinaflu.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    long long res = 0;
    vector <vector <int>> total;
    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
        adj[u].erase(unique(adj[u].begin(),
        adj[u].end()), adj[u].end());
        total.push_back(adj[u]);
        adj[u].push_back(u);
    }
    sort(total.begin(), total.end(),
    [&](const vector <int> &x, const vector <int> &y) {
        return x.size() != y.size() ? x.size() < y.size() : x < y;
    });
    int cur = 1;
    for (int i = 1; i < total.size(); i++) {
        if (total[i] == total[i - 1]) res += cur++;
        else cur = 1;
    }
    total.clear();
    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
        total.push_back(adj[u]);
        adj[u].push_back(u);
    }
    sort(total.begin(), total.end(),
    [&](const vector <int> &x, const vector <int> &y) {
        return x.size() != y.size() ? x.size() < y.size() : x < y;
    });
    cur = 1;
    for (int i = 1; i < total.size(); i++) {
        if (total[i] == total[i - 1]) res += cur++;
        else cur = 1;
    }
    cout << res << '\n';
}