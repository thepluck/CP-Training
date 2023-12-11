#include "stations.h"
#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int p, bool d, int &cnt, const vector <vector <int>> &adj, vector <int> &label) {
    if (!d) label[u] = cnt++;
    for (int v : adj[u])
        if (v != p) dfs(v, u, !d, cnt, adj, label);
    if (d) label[u] = cnt++; 
}

vector <int> label(int n, int k, vector <int> u, vector <int> v) {
    vector <vector <int>> adj(n);
    vector <int> label(n);
    for (int i = 0; i + 1 < n; i++) {
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    int cnt = 0;
    dfs(0, -1, 0, cnt, adj, label);
    return label;
}

int find_next_station(int s, int t, vector <int> c) {
    if (s < c[0]) {
        int lo = s, hi = c.size() > 1 ? c[c.size() - 2] : s;
        if (lo <= t && t <= hi) {
            for (int u : c)
                if (u >= t) return u;
        }
        return c[c.size() - 1];
    } else {
        int hi = s, lo = c.size() > 1 ? c[1] : s;
        if (lo <= t && t <= hi) {
            reverse(c.begin(), c.end());
            for (int u : c)
                if (u <= t) return u;
        }
        return c[0];
    }
}
