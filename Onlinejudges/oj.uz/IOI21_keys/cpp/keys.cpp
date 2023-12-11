#include <bits/stdc++.h>

using namespace std;

namespace {
    struct disjoint_set {
        vector<int> par, siz;

        void init(int n) {
            par.assign(n, -1);
            siz.assign(n, 1);
        }

        int find(int u) {
            if (par[u] < 0) return u;
            return par[u] = find(par[u]);
        }

        bool unite(int u, int v) {
            u = find(u); v = find(v);
            if (u == v) return false;
            par[v] = u; siz[u] += siz[v];
            return true;
        }

        bool same(int u, int v) {
            return find(u) == find(v);
        }
    } roots, forests;

    vector<set<pair<int, int>>> locks;
    vector<vector<int>> unlocks;
    vector<set<int>> keys;
    vector<int> nxt, vis;

    void unite(int u, int v) {
        if (size(unlocks[u]) < size(unlocks[v]))
            swap(unlocks[u], unlocks[v]);
        for (int w : unlocks[v])
            unlocks[u].push_back(w);
        if (size(locks[u]) + size(keys[u])
        < size(locks[v]) + size(keys[v])) {
            swap(locks[u], locks[v]);
            swap(keys[u], keys[v]);
        }
        for (auto edge : locks[v]) {
            if (keys[u].count(edge.first))
                unlocks[u].push_back(edge.second);
            else locks[u].insert(edge);
        }
        for (auto key : keys[v]) {
            auto iter = locks[u].
            lower_bound(make_pair(key, -1));
            while (iter != locks[u].end()
            && iter->first == key) {
                unlocks[u].push_back(iter->second);
                iter = locks[u].erase(iter);
            }
            keys[u].insert(key);
        }
    }

    void dfs(int u) {
        vis[u] = 2;
        if (!vis[nxt[u]]) dfs(nxt[u]);
        else if (vis[nxt[u]] == 2) {
            int v = nxt[u];
            while (u != v) {
                roots.unite(u, v);
                unite(u, v); v = nxt[v];
            }
            while (unlocks[u].size()) {
                int v = unlocks[u].back();
                unlocks[u].pop_back();
                if (forests.unite(v, u)) {
                    nxt[u] = v; break;
                }
                while (!roots.same(u, v)) {
                    unite(u, v = roots.find(v));
                    roots.unite(nxt[v], v);
                }
            }
        }
        vis[u] = 1;
    }
}

vector<int> find_reachable(vector<int> r,
vector<int> u, vector<int> v, vector<int> c) {
    int n = r.size(); locks.resize(n);
    unlocks.resize(n); keys.resize(n);
    nxt.resize(n); vis.resize(n);
    roots.init(n); forests.init(n);
    for (int i = 0; i < u.size(); i++) {
        locks[u[i]].emplace(c[i], v[i]);
        locks[v[i]].emplace(c[i], u[i]);
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
        keys[i].insert(r[i]); nxt[i] = -1;
        auto iter = locks[i].
        lower_bound(make_pair(r[i], -1));
        while (iter != locks[i].end()
        && iter->first == r[i]) {
            unlocks[i].push_back(iter->second);
            nxt[i] = iter->second;
            iter = locks[i].erase(iter);
        }
        if (nxt[i] < 0) flag = true;
        else forests.unite(nxt[i], i);
    }
    if (flag) {
        for (int i = 0; i < n; i++)
            if (nxt[i] < 0) nxt[i] = 1;
            else nxt[i] = 0;
        return nxt;
    }
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfs(i);
    int res = n;
    for (int i = 0; i < n; i++)
        if (forests.par[i] < 0) {
            int j = roots.find(i);
            res = min(res, roots.siz[j]);
        }
    vis.assign(n, 0);
    for (int i = 0; i < n; i++) {
        int j = forests.find(i);
        if (roots.same(i, j)) {
            j = roots.find(i);
            vis[i] = res == roots.siz[j];
        }
    }
    return vis;
}
