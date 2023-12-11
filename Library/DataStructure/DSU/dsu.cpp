#include <bits/stdc++.h>
using namespace std;

struct DisjointSet {
    vector <int> par, siz;
    
       DisjointSet(int N):
       par(N + 5, -1), siz(N + 5, 1) {}
    
    int root(int u) {
        return par[u] < 0 ? u :
        par[u] = root(par[u]);
    }
    
    bool unite(int u, int v) {
        u = root(u); v = root(v);
        if (u == v) return false;
        if (siz[u] < siz[v]) swap(u, v);
        siz[u] += siz[v]; par[v] = u;
        return true;
    }
};
