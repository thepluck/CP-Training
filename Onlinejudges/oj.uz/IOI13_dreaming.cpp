#include "dreaming.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

vector <pair <int, int>> adj[N];
int par[N], dis[N];
queue <int> que;

void BFS(int u, int &diam, int &dist) {
    int far = u; diam = dis[u] = 0;
    par[u] = -1; que.push(u); 
    while (que.size()) {
        u = que.front(); que.pop();
        if (dis[u] > diam) {
            diam = dis[u]; far = u;
        }
        for (auto e : adj[u]) {
            int v, w; tie(v, w) = e;
            if (v != par[u]) {
                dis[v] = dis[u] + w;
                par[v] = u; que.push(v);
            }
        }
    }
    que.push(u = far);
    diam = dis[u] = 0; par[u] = -1;
    while (que.size()) {
        u = que.front(); que.pop();
        if (dis[u] > diam) {
            diam = dis[u]; far = u;
        }
        for (auto e : adj[u]) {
            int v, w; tie(v, w) = e;
            if (v != par[u]) {
                dis[v] = dis[u] + w;
                par[v] = u; que.push(v);
            }
        }
    }
    dist = INT_MAX; u = far;
    while (u >= 0) {
        dist = min(dist, max
        (dis[u], dis[far] - dis[u]));
        u = par[u];
    }
    
}

int travelTime(int n, int m, int l,
int a[], int b[], int t[]) {
    for (int i = 0; i < m; i++) {
        adj[a[i]].emplace_back(b[i], t[i]);
        adj[b[i]].emplace_back(a[i], t[i]);
    }
    memset(dis, -1, sizeof dis);
    vector <int> tmp; int res = 0;
    for (int i = 0; i < n; i++)
        if (dis[i] < 0) {
            int diam, dist;
            BFS(i, diam, dist);
            res = max(res, diam);
            tmp.push_back(dist);
        }
    int pos = max_element(tmp.begin(),
    tmp.end()) - tmp.begin();
    for (int i = 0; i < n - m; i++)
        if (i != pos) tmp[i] += l;
    pos = max_element(tmp.begin(),
    tmp.end()) - tmp.begin();
    for (int i = 0; i < n - m; i++)
        if (i != pos)
            res = max(res, tmp[i] + tmp[pos]);
    return res;
}
