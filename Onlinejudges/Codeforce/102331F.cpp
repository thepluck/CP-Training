#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct edge {
    int u, v; ll s, ctfu, ctfv;
};

const int N = 300005;

set <pair <ll, int>> ctf[N];
int par[N]; ll val[N];
edge lst[N]; set <int> brk;

int root(int u) {
    if (u != par[u])
        par[u] = root(par[u]);
    return par[u];
}

bool unite(int u, int v) {
    if (u == v) return false;
    if (ctf[u].size() < ctf[v].size())
        swap(u, v);
    for (auto pp : ctf[v])
        ctf[u].emplace(pp);
    val[u] += val[v]; par[v] = u;
    while (ctf[u].size()) {
        auto it = ctf[u].begin();
        if (it->first <= val[u]) {
            int i = it->second;
            brk.emplace(i);
            ctf[root(lst[i].u)].
            erase({lst[i].ctfu, i});
            ctf[root(lst[i].v)].
            erase({lst[i].ctfv, i});
        }
        else break;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int u = 1; u <= n; u++) {
        cin >> val[u]; par[u] = u;
    }
    vector <int> ans;
    for (int i = 1; i <= m; i++) {
        int u, v, s; cin >> u >> v >> s;
        lst[i] = {u, v, s, s / 2, s / 2};
        if (max(val[u], val[v]) >= s / 2)
            brk.emplace(i);
        else {
            ctf[u].emplace(s / 2, i);
            ctf[v].emplace(s / 2, i);
        }
    }
    while (brk.size()) {
        int i = *brk.begin();
        brk.erase(i); ll s = lst[i].s;
        int u = lst[i].u, v = lst[i].v;
        int x = root(u), y = root(v);
        if (val[x] + val[y] >= s) {
            if (unite(x, y))
                ans.push_back(i);
        }
        else {
            lst[i].ctfu = val[x] +
            (s - val[x] - val[y]) / 2;
            lst[i].ctfv = val[y] +
            (s - val[x] - val[y]) / 2;
            ctf[x].emplace(lst[i].ctfu, i);
            ctf[y].emplace(lst[i].ctfv, i);
        }
    }
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
}