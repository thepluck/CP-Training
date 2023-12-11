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

struct dynamic_array {
    static const int BLOCK_SIZE = 450;
    vector<vector<int>> blocks; int n;
 
    dynamic_array(vector<int> a) {
        n = a.size();
        for (int i = 0; i < n; i += BLOCK_SIZE) {
            blocks.emplace_back();
            for (int j = i; j < min(i + BLOCK_SIZE, n); j++)
                blocks.back().push_back(a[j]);
        }
    }
 
    int& operator [] (int i) {
        for (auto &block : blocks)
            if (i >= block.size())
                i -= block.size();
            else return block[i];
    }
 
    void erase(int i) {
        for (auto &block : blocks)
            if (i >= block.size())
                i -= block.size();
            else {
                block.erase(block.begin() + i);
                break;
            }
        n--;
    }
 
    int size() const {
        return n;
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
    dynamic_array root(rnd.perm(n, 1));
    bool dir = rnd.next(2);
    while (q--) {
        if (rnd.next(2)) {
            cout << "1 ";
            if (root.size() > 2 && !rnd.next(20)) {
                int i = rnd.next(1, int(root.size()) - 2);
                int j = rnd.next(i + 1, int(root.size()) - 1);
                int u = root[i], v = root[j];
                if (cmp[u].size() < cmp[v].size()) {
                    swap(u, v); swap(i, j);
                }
                int x = rnd.any(cmp[u]);
                int y = rnd.any(cmp[v]);
                if (dir)
                    cout << x << ' ' << y << '\n';
                else cout << y << ' ' << x << '\n';
                for (int p : cmp[v])
                    cmp[u].push_back(p);
                cmp[v].clear(); par[v] = u;
                root.erase(j);
            } else if (root.size() > 1) {
                int i = 0, j = rnd.next(1, int(root.size()) - 1);
                int u = root[i], v = root[j];
                int x = rnd.any(cmp[u]);
                int y = rnd.any(cmp[v]);
                if (dir)
                    cout << x << ' ' << y << '\n';
                else cout << y << ' ' << x << '\n';
                for (int p : cmp[v])
                    cmp[u].push_back(p);
                cmp[v].clear(); par[v] = u;
                root.erase(j);
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