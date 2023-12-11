#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

struct edge {
    int u, v, w;
};

const int N = 4e5 + 5;

edge E[N]; long long D[N];
vector<int> adj[N];
priority_queue<pair<long long, int>,
vector<pair<long long, int>>,
greater<pair<long long, int>>> pq; 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < m; i++) {
        cin >> E[i].u >> E[i].v >> E[i].w;
        E[i + m].u = E[i].v;
        E[i + m].v = E[i].u;
        E[i + m].w = E[i].w;
        adj[E[i].u].push_back(i);
        adj[E[i].v].push_back(i + m);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end(),
        [&](int x, int y) {
            return E[x].w < E[y].w;
        });
    memset(D, 0x3f, sizeof D);
    for (int i : adj[1])
        pq.emplace(D[i] = E[i].w, i);
    while (pq.size()) {
        int i; long long w;
        tie(w, i) = pq.top(); pq.pop();
        if (E[i].v == n) {
            cout << w; return 0;
        }
        if (w > D[i]) continue;
        while (adj[E[i].v].size()) {
            int j = adj[E[i].v].back();
            if (E[j].w >= E[i].w + l) {
                if (cmin(D[j], w + E[j].w))
                    pq.emplace(D[j], j);
                adj[E[i].v].pop_back();
            } else break;
        }
    }
    cout << -1;
}
