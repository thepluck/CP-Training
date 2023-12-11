#include "pgamelib.h"
#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> adj[N];
int cnt[N], grd[N], vis[N], tim;
int good[N][N];

void prepare() {
    for (int i = 4; i < N; i++) {
        tim++;
        for (int j = 3; j <= i - 3; j++)
            vis[grd[j + 1] ^ grd[i - j + 1]] = tim;
        while (vis[grd[i]] == tim) grd[i]++;
    }
}

int main() {
    prepare();
    int total = 0;
    int n, m; get(n, m);
    while (m--) {
        int u, v; get_uv(u, v);
        if (u > v) swap(u, v);
        adj[u - 1].push_back(v - 1);
    }
    for (int i = 0; i + 1 < n; i++)
        adj[i].push_back(i + 1);
    adj[0].push_back(n - 1);
    for (int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int u = 0; u < n; u++) {
        int pre = -1;
        for (int v : adj[u]) {
            int w = pre, ver = 2; pre = v;
            if (v - u < 2) continue;
            while (w != v) {
                w = *prev(upper_bound
                (adj[w].begin(), adj[w].end(), v));
                ver++;
            }
            cnt[ver]++; total ^= grd[ver];
        }
    }
    if (total == 0) {
        int u, v; play(0, 0, u, v);
        if (u == 0) return 0;
        if (u > v) swap(u, v);
        adj[u - 1].push_back(v - 1);
    }
    for (int x = 4; x < N; x++)
        for (int y = x; x + y < N; y++)
            good[x + y - 2][grd[x] ^ grd[y]] = x;
    while (true) {
        total = 0;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i + 1 < n; i++)
            adj[i].push_back(i + 1);
        adj[0].push_back(n - 1);
        for (int i = 0; i < n; i++)
            sort(adj[i].begin(), adj[i].end());
        for (int u = 0; u < n; u++) {
            int pre = -1;
            for (int v : adj[u]) {
                int w = pre, ver = 2; pre = v;
                if (v - u < 2) continue;
                while (w != v) {
                    w = *prev(upper_bound
                    (adj[w].begin(), adj[w].end(), v));
                    ver++;
                }
                cnt[ver]++; total ^= grd[ver];
            }
        }
        int siz;
        for (siz = 4; siz <= n; siz++)
            if (cnt[siz] && good[siz][total ^ grd[siz]]) break;
        for (int u = 0; u < n; u++) {
            int pre = -1;
            for (int v : adj[u]) {
                int w = pre, ver = 2;
                if (v - u < 2) {
                    pre = v; continue;
                }
                while (w != v) {
                    w = *prev(upper_bound
                    (adj[w].begin(), adj[w].end(), v));
                    ver++;
                }
                if (ver == siz) {
                    w = pre; ver = 2;
                    siz = good[siz][total ^ grd[siz]];
                    while (ver != siz) {
                        w = *prev(upper_bound
                        (adj[w].begin(), adj[w].end(), v));
                        ver++;
                    }
                    adj[u].push_back(w);
                    play(u + 1, w + 1, u, v);
                    if (u == 0) return 0;
                    if (u > v) swap(u, v);
                    adj[u - 1].push_back(v - 1);
                    goto gg;
                }
                pre = v;
            }
        }
        gg:;
    }
}
