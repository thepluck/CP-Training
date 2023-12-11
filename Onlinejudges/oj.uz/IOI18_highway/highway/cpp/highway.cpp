#include "highway.h"
#include <bits/stdc++.h>

using namespace std;

void find_pair(int N, vector<int> U,
vector<int> V, int A, int B) {
    int M = U.size();
    int lo = 0, hi = M - 1;
    vector<int> w(M);
    long long init = ask(w);
    int root[2], ans[2];
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        for (int i = 0; i < M; i++)
            w[i] = i <= mi;
        if (ask(w) > init) {
            root[0] = U[mi];
            root[1] = V[mi];
            hi = mi - 1;
        } else lo = mi + 1;
    }
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; i++) {
        adj[U[i]].push_back(i);
        adj[V[i]].push_back(i);
    }
    vector<int> dis[2], vis[2];
    queue<int> que;
    for (int i = 0; i < 2; i++) {
        dis[i].assign(N, -1);
        vis[i].resize(N);
        que.push(root[i]);
        dis[i][root[i]] = 0;
        ans[i] = root[i];
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int e : adj[u]) {
                int v = u ^ U[e] ^ V[e];
                if (dis[i][v] < 0) {
                    dis[i][v] = dis[i][u] + 1;
                    que.push(v);
                }
            }
        }
    }
    vector<int> ord, idx(N);
    for (int i = 0; i < 2; i++) {
        que.push(root[i]);
        vis[i][root[i]] = 1;
        ord.assign(M, -1);
        int cnt = 0;
        while (que.size()) {
            int u = que.front(); que.pop();
            for (int e : adj[u]) {
                int v = u ^ U[e] ^ V[e];
                if (dis[i][v] < dis[i ^ 1][v]) {
                    if (!vis[i][v]) {
                        idx[ord[e] = cnt++] = e;
                        vis[i][v] = 1; que.push(v);
                    } else if (dis[i][v] == dis[i][u] + 1)
                        ord[e] = N;
                } else if (root[0] != U[e] || root[1] != V[e])
                    ord[e] = N;
            }
        }
        lo = 0; hi = cnt - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            for (int j = 0; j < M; j++)
                w[j] = ord[j] >= mi;
            if (ask(w) > init) {
                int e = idx[mi];
                if (dis[i][U[e]] > dis[i][V[e]])
                    ans[i] = U[e];
                else ans[i] = V[e];
                lo = mi + 1;
            } else hi = mi - 1;
        }
    }
    answer(ans[0], ans[1]);
}
