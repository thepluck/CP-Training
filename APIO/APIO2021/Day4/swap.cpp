#include "swap.h"
#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100005;
 
struct node {
    int endP[2], par, size, val;
} comp[MAXN];
 
int wpar[MAXN], depth[MAXN];
vector <int> adj[MAXN];
 
int root(int u) {
    while (comp[u].par >= 0) u = comp[u].par;
    return u;
}
 
bool join(int u, int v, int w) {
    int x = root(u), y = root(v);
    if (x == y) {
        if (comp[x].val < 0) comp[x].val = w;
        return false;
    }
    if (comp[x].size < comp[y].size) {
        swap(x, y); swap(u, v);
    }
    comp[x].size += comp[y].size; comp[y].par = x;
    wpar[y] = w; adj[x].push_back(y);
    if (comp[x].val < 0 && comp[y].val < 0 &&
    (u == comp[x].endP[0] || u == comp[x].endP[1]) &&
    (v == comp[y].endP[0] || v == comp[y].endP[1])) {
        if (u == comp[x].endP[0])
            comp[x].endP[0] = comp[x].endP[1];
        if (v == comp[y].endP[0])
            comp[x].endP[1] = comp[y].endP[1];
        else comp[x].endP[1] = comp[y].endP[0];
    } else if (comp[x].val < 0) comp[x].val = w;
    return true;
}
 
void DFS(int u) {
    for (int v : adj[u]) {
        depth[v] = depth[u] + 1; DFS(v);
    }
}
 
void init(int N, int M, vector <int> U,
vector <int> V, vector <int> W) {
    vector <int> sorted(M);
    iota(sorted.begin(), sorted.end(), 0);
    sort(sorted.begin(), sorted.end(),
    [&](int i, int j) {return W[i] < W[j];});
    for (int i = 0; i < N; i++) {
        comp[i].endP[0] = comp[i].endP[1] = i;
        comp[i].par = -1; comp[i].size = 1;
        comp[i].val = -1;
    }
    for (int i : sorted) join(U[i], V[i], W[i]);
    for (int i = 0; i < N; i++)
        if (comp[i].par < 0) DFS(i);
}
 
int getMinimumFuelCapacity(int u, int v) {
    if (root(u) != root(v)) return -1;
    int res = 0;
    while (u != v) {
        if (depth[u] < depth[v]) swap(u, v);
        res = max(res, wpar[u]); u = comp[u].par;
    }
    while (u >= 0 && comp[u].val < 0) {
        res = max(res, wpar[u]); u = comp[u].par;
    }
    if (u < 0) return -1;
    return max(res, comp[u].val);
}
