#include "server.h"
#include <vector>
#include <iostream>

namespace {
    using namespace std;
    
    const int N = 505;

    vector<int> adj[N], bit;
    int ptr, mark[N], par[N];

    int dfs(int u, vector<int> &a, vector<int> &b, vector<int> &c, int d) {
        int hei = -1;
        for (int e : adj[u]) {
            int v = u ^ a[e] ^ b[e];
            if (v != par[u]) {
                par[v] = u;
                hei = max(hei, dfs(v, a, b, c, d + c[e]));
            }
        }
        hei++;
        if (hei == 11 || u == 0) {
            mark[u] = ptr;
            int e = d;
            for (int i = ptr + 8; i >= ptr; i--) {
                bit[i] = e & 1; e >>= 1;
            }
            ptr += 9; return -1;
        }
        return hei;
    }
}


vector<int> server(int n, vector<int> a, vector<int> b, vector<int> c) {
    bit.assign(1000, 0);
    ptr = n - 1;
    for (int i = 0; i < n; i++) {
        adj[i].clear(); mark[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        adj[a[i]].push_back(i);
        adj[b[i]].push_back(i);
        bit[i] = c[i];
    }
    par[0] = -1; dfs(0, a, b, c, 0);
    return bit;
}
