#include <bits/stdc++.h>
using namespace std;

template <class X, class Y>
bool chkmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

#define fi first
#define se second

using ii = pair <int, int>;

const int N = 505;
int dis[N], ans[N][N], n, m;
int p[10][N], ver[N], dep[N];
priority_queue <ii, vector <ii>, greater <ii>> pq;
vector <ii> adj[N]; ii edge[N];

int lca(int u, int v) {
    if (!u || !v) return u | v;
}

void solve(int s) {
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0; pq.emplace(s, 0);
    while (!pq.empty()) {
        ii cur = pq.top(); pq.pop();
        if (dis[cur.fi] < cur.se) continue;
        for (ii e : adj[cur.fi])
            if (chkmin(dis[e.fi], cur.se + e.se))
                pq.emplace(e.fi, dis[e.fi]);
    }
    for (int i = 1; i <= n; i++) ver[i] = i;
    sort(ver + 1, ver + n + 1,
    [&](int x, int y) {
        return dis[x] < dis[y];
    });
    for (int i = 2; i <= n; i++)
        for (ii e : adj[ver[i]])
            if (dis[e.fi] + e.se == dis[ver[i]]) {

            }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

}