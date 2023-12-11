#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

map<int, int> cnt[N];
int par[N], num;

int find(int u) {
    if (!par[u]) return u;
    return par[u] = find(par[u]);
}

bool unite(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    for (auto c : cnt[v])
        cnt[u][c.first] += c.second;
    cnt[v].clear(); par[v] = u; num++;
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int c; cin >> c;
        cnt[i].emplace(c, 1);
    }
    while (q--) {
        int cmd, u, v;
        cin >> cmd >> u >> v;
        if (cmd == 1) unite(u, v);
        else {
            u = find(u);
            auto it = cnt[u].find(v);
            if (it == cnt[u].end())
                cout << "0\n";
            else cout << it->second << '\n';
        }
    }
}

