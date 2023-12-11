#include <bits/stdc++.h>
#include "escape_route.h"

namespace {
    using namespace std;
    using ll = long long;

    template<class X, class Y>
    bool cmin(X& a, const Y &b) {
        return a > b ? a = b, 1 : 0;
    }

    const int N = 95;

    using item = pair<ll, int>;

    ll dis1[N][N][N];
    vector<int> adj[N];
}

vector<ll> calculate_necessary_time(
int n, int m, ll s, int q, vector<int> A,
vector<int> B, vector<ll> L, vector<ll> C,
vector<int> U, vector<int> V, vector<ll> T) {
    memset(dis1, 0x3f, sizeof dis1);
    for (int i = 0; i < m; i++) {
        adj[A[i]].push_back(i);
        adj[B[i]].push_back(i);
    }
    priority_queue<item, greater <item>, vector<item>> pq;
    memset(dis1, 0x3f, sizeof dis1);
    for (int i = 0; i < m; i++) {
        auto dis = dis1[A[i]][B[i]];
        pq.emplace(A[i], dis[A[i]] = C[i] - L[i]);
        int u; ll cur;
        while (pq.size()) {
            tie(cur, u) = pq.top(); pq.pop();
            if (dis[u] < cur) continue;
            for (int j : adj[u]) {
                ll nxt = 
            }
        }
    }
}
