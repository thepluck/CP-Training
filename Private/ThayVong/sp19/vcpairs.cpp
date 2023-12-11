#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().
time_since_epoch().count());
 
struct custom_hash {
    static int splitmix64(int x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    int operator()(int x) const {
        static const int FIXED_RANDOM = rng();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int N = 1e5 + 5;

unordered_map <int, int, custom_hash> mp[N];
long long res = 0; int p[N];

int fin(int u) {
    return u == p[u] ? u : p[u] = fin(p[u]);
}

void mer(int u, int v) {
    u = fin(u); v = fin(v);
    if (u == v) return;
    if (mp[u].size() < mp[v].size()) swap(u, v);
    for (auto p : mp[v]) {
        res += 1ll * p.second * mp[u][p.first];
        mp[u][p.first] += p.second;
    }
    p[v] = u; mp[v].clear();
}

int main() {
    freopen("vcpairs.inp", "r", stdin);
    freopen("vcpairs.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    iota(p + 1, p + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        int c; cin >> c; mp[i][c]++;
    }
    while (m--) {
        int u, v; cin >> u >> v;
        mer(u, v); cout << res << '\n';
    }
}