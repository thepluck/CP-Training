#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e4 + 5;
const int K = 205;
 
struct item {
    int v, p, w;
 
    item(int v, int p, int w):
    v(v), p(p), w(w) {}
};
 
int dis[N]; bool vs[N][K];
vector <int> adj[N];
queue <item> q;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int s, t, n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, p; cin >> v >> p;
        adj[v].push_back(p);
        if (!i) s = v;
        if (i == 1) t = v;
    }
    memset(dis, -1, sizeof dis);
    q.emplace(s, 0, 0);
    while (!q.empty()) {
        item h = q.front(); q.pop();
        if (h.v < 0 || h.v >= n) continue;
        if (abs(h.p) < K) {
            if (vs[h.v][abs(h.p)]) continue;
            vs[h.v][abs(h.p)] = 1;
        }
        if (dis[h.v] == -1) {
            dis[h.v] = h.w;
            for (int p : adj[h.v]) {
                q.emplace(h.v + p, p, h.w + 1);
                q.emplace(h.v - p, -p, h.w + 1);
            }
        }
        q.emplace(h.v + h.p, h.p, h.w + 1);
    }
    cout << dis[t] << '\n';
}