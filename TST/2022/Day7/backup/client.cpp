#include "client.h"
#include <vector>
#include <iostream>

namespace {
    using namespace std;
    
    const int N = 505;

    vector<int> adj[N];
    int ptr, mark[N], par[N];

    int dfs(int u, vector<int> &a, vector<int> &b) {
        int hei = -1;
        for (int e : adj[u]) {
            int v = u ^ a[e] ^ b[e];
            if (v != par[u]) {
                par[v] = u;
                hei = max(hei, dfs(v, a, b));
            }
        }
        hei++;
        if (hei == 11 || u == 0) {
            mark[u] = ptr; ptr += 9; return -1;
        }
        return hei;
    }
}

int client(int n, vector<int> a, vector<int> b, int u) {
    ptr = n - 1;
    for (int i = 0; i < n; i++) {
        adj[i].clear(); mark[i] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        adj[a[i]].push_back(i);
        adj[b[i]].push_back(i);
    }
    par[0] = -1; dfs(0, a, b);
    int p = 0, q = 0;
    while (!mark[u]) {
        int v = par[u];
        for (int e : adj[v])
            if (u == (v ^ a[e] ^ b[e]))
                p += get_bit(e);
        u = v;
    }
    for (int i = mark[u]; i < mark[u] + 9; i++)
        q = (q << 1) + get_bit(i);
    return p + q;
}
