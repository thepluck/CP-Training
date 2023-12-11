#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

struct DSU {
    vector <int> par, siz;
    vector <int> tim, ver;

    DSU(int N): par(N + 5, 0), siz(N + 5, 1) {}

    int root(int u) {
        while (par[u]) u = par[u];
        return u;
    }

    void join(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return;
        if (siz[u] < siz[v]) swap(u, v);
        par[v] = u; siz[u] += siz[v]; 
        ver.push_back(v);
    } 

    void push(int u, int v) {
        tim.push_back(ver.size());
        join(2 * u - 1, 2 * v);
        join(2 * u, 2 * v - 1);
    }

    void pop() {
        while (ver.size() > tim.back()) {
            int v = ver.back();
            ver.pop_back();
            siz[par[v]] -= siz[v];
            par[v] = 0;
        }
        tim.pop_back();
    }

    bool check(int u, int v) {
        return root(2 * u) == root(2 * v);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    DSU dsu(N * 2);
    vector <pair <int, int>> E(M);
    for (int i = 0; i < M; i++)
        cin >> E[i].fi >> E[i].se;
    vector <pair <int, int>> buc, tmp[2];
    auto pop = [&]() {
        if (buc.back().se) {
            while (buc.size()) {
                auto p = buc.back();
                buc.pop_back(); dsu.pop();
                tmp[p.se].push_back(p);
                if (tmp[0].size() == tmp[1].size())
                    break;
            }
            if (tmp[0].empty()) {
                for (auto &p : tmp[1]) {
                    dsu.push(E[p.fi].fi, E[p.fi].se);
                    p.se = 0;
                }
                swap(tmp[1], buc);
            } else {
                while (tmp[1].size()) {
                    auto p = tmp[1].back();
                    tmp[1].pop_back();
                    buc.push_back(p);
                    dsu.push(E[p.fi].fi, E[p.fi].se);
                }
                while (tmp[0].size()) {
                    auto p = tmp[0].back();
                    tmp[0].pop_back();
                    buc.push_back(p);
                    dsu.push(E[p.fi].fi, E[p.fi].se);
                }
            }
        }
        dsu.pop(); buc.pop_back();
    };
    auto push = [&](int i) {
        buc.emplace_back(i, 1);
        dsu.push(E[i].fi, E[i].se);
    };
    vector <int> lim(2 * M);
    for (int i = 0, j = 0; i < 2 * M; i++) {
        int u, v; tie(u, v) = E[i % M];
        while (dsu.check(u, v)) {
            pop(); j++;
        }
        lim[i] = j; push(i % M);
    }
    while (Q--) {
        int l, r; cin >> l >> r;
        if (lim[l + M - 2] <= r)
            cout << "NO\n";
        else cout << "YES\n";
    }
}