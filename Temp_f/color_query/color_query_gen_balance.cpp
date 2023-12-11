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

struct compare {
    bool operator () (int i, int j) const {
        return cmp[i].size() < cmp[j].size() ||
        (cmp[i].size() == cmp[j].size() && i < j);
    }
};

int main(int argc, char **argv) {
    registerGen(argc, argv, 1);
    int n = rnd.wnext(1, 100000, 20);
    int q = rnd.wnext(1, 200000, 20);
    cout << n << ' ' << q << '\n';
    vector<int> color = rnd.perm(n, 1);
    color.resize(rnd.next(2) ?
    rnd.next(1, 5000) : rnd.next(1, n));
    for (int i = 1; i <= n; i++) {
        col[i] = rnd.any(color);
        par[i] = i; cmp[i].push_back(i);
        cout << col[i] << " \n"[i == n];
    }
    set<int, compare> s;
    for (int i = 1; i <= n; i++)
        s.emplace(i);
    while (q--) {
        if (s.size() > 1 && rnd.next(2)) {
            cout << "1 ";
            int u, v;
            if (rnd.next(20)) {
                u = *next(s.begin());
                v = *s.begin();
            } else {
                while (true) {
                    int step = rnd.next(s.size());
                    auto it = s.begin();
                    while (step--) it = next(it);
                    u = *it;
                    step = rnd.next(s.size());
                    it = s.begin();
                    while (step--) it = next(it);
                    v = *it;
                    if (u != v) break;
                }
            }
            int x = rnd.any(cmp[u]);
            int y = rnd.any(cmp[v]);
            if (rnd.next(2))
                cout << x << ' ' << y << '\n';
            else cout << y << ' ' << x << '\n';
            s.erase(u); s.erase(v);
            for (int p : cmp[v])
                cmp[u].push_back(p);
            cmp[v].clear(); par[v] = u;
            s.insert(u);
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