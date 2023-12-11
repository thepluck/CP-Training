#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int par[N], col[N];
vector<int> cmp[N];

int find(int u) {
    if (u == par[u]) return u;
    return par[u] = find(par[u]);
}



int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int n = rnd.wnext(1, 100000, 20);
    int q = rnd.wnext(1, 200000, 20);
    cout << n << ' ' << q << '\n';
    vector<int> color = rnd.perm(n, 1);
    color.resize(rnd.next(2) ?
    rnd.next(1, 500) : rnd.next(1, n));
    for (int i = 1; i <= n; i++) {
        col[i] = rnd.any(color);
        par[i] = i; cmp[i].push_back(i);
        cout << col[i] << " \n"[i == n];
    }
    vector<int> root = rnd.perm(n, 1);
    vector<pair<int, int>> edges;
    for (int i = 500; i < n; i++) {
        int u = root[rnd.next(i)];
        int v = root[i];
        edges.emplace_back(u, v);
    }
    shuffle(edges.begin(), edges.end());
    while (edges.size() && q--) {
        if (rnd.next(3)) {
            cout << "1 ";
            if (rnd.next(20)) {
                int u, v;
                tie(u, v) = edges.back();
                if (rnd.next(2))
                    cout << u << ' ' << v << '\n';
                else cout << v << ' ' << u << '\n';
                if (cmp[u].size() < cmp[v].size())
                    cmp[u].swap(cmp[v]);
                for (int p : cmp[v])
                    cmp[u].push_back(p);
                cmp[v].clear(); par[v] = u;
                edges.pop_back();
            } else {
                int u = rnd.next(1, n);
                int v = rnd.any(cmp[find(u)]);
                cout << u << ' ' << v << '\n';
            }
        } else {
            cout << "2 ";
            int u = rnd.next(1, n), c;
            if (rnd.next(10))
                c = col[rnd.any(cmp[find(u)])];
            else c = rnd.any(color);
            cout << u << ' ' << c << '\n';
        }
    }
    root.resize(500);
    if (q <= 0) return 0;
    while (q--) {
        if (rnd.next(2)) {
            cout << "1 ";
            if (root.size() > 1 && rnd.next(10)) {
                int i = rnd.next(root.size() - 1);
                int j = rnd.next(i + 1, int(root.size()) - 1);
                int u = root[i], v = root[j];
                if (cmp[u].size() < cmp[v].size()) {
                    swap(u, v); swap(i, j);
                }
                int x = rnd.any(cmp[u]);
                int y = rnd.any(cmp[v]);
                if (rnd.next(2))
                    cout << x << ' ' << y << '\n';
                else cout << y << ' ' << x << '\n';
                for (int p : cmp[v])
                    cmp[u].push_back(p);
                cmp[v].clear(); par[v] = u;
                root.erase(root.begin() + j);
            } else {
                int u = rnd.next(1, n);
                int v = rnd.any(cmp[find(u)]);
                cout << u << ' ' << v << '\n';
            }
        } else {
            cout << "2 ";
            int u = rnd.next(1, n), c;
            if (rnd.next(10))
                c = col[rnd.any(cmp[find(u)])];
            else c = rnd.any(color);
            cout << u << ' ' << c << '\n';
        }
    }
}