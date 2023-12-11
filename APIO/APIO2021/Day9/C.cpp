#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ll = long long;

const int MAXN = 100005;

struct edge {
    int v, s, c;

    edge(int v, int s, int c):
    v(v), s(s), c(c) {}
};

map <ll, ll> A[MAXN];
ll S[MAXN], D[MAXN], T[MAXN];
vector <edge> adj[MAXN];

void DFS(int u, int p) {
    for (auto e : adj[u]) if (e.v != p) {
        T[e.v] = min(T[u], ll(e.s));
        D[e.v] = D[u] + e.c; DFS(e.v, u);
        A[e.v][D[e.v]] += T[e.v];
        S[e.v] += T[e.v];
        while (S[e.v] > T[e.v]) {
            auto pp  = *A[e.v].rbegin();
            A[e.v].erase(pp.fi);
            ll s = min(pp.se, S[e.v] - T[e.v]);
            S[e.v] -= s; pp.se -= s;
            if (pp.se > 0) A[e.v].insert(pp);
        }
        if (A[u].size() < A[e.v].size())
            A[u].swap(A[e.v]);
        for (auto pp : A[e.v])
            A[u][pp.fi] += pp.se;
        A[e.v].clear(); S[u] += T[e.v];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N; T[1] = LLONG_MAX;
    for (int i = 1; i < N; i++) {
        int u, v, s, c;
        cin >> u >> v >> s >> c;
        adj[u].emplace_back(v, s, c);
        adj[v].emplace_back(u, s, c);
    }
    DFS(1, 0);
    long long cost = 0;
    for (auto pp : A[1])
        cost += pp.fi * pp.se;
    cout << S[1] << ' ' << cost << '\n';
}