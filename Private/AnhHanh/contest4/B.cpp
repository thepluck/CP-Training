#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int MAXN = 2005;
const int MAXM = 2000005;

vector <pair <int, int>> adj[MAXN];
vector <int> tree[MAXN];
int N, M, siz[MAXN];
int num[MAXN], low[MAXN], timer;
bool bri[MAXM], DP[MAXN];

void DFS1(int u, int e) {
    num[u] = low[u] = ++timer;
    for (auto pp : adj[u]) {
        int v, i; tie(v, i) = pp;
        if (!num[v]) {
            DFS1(v, i);
            cmin(low[u], low[v]);
            if (low[v] > num[u])
                bri[i] = true;
        } else if (i != e)
            cmin(low[u], num[v]);
    }
}

void DFS2(int u) {
    num[u] = timer; low[timer]++;
    for (auto pp : adj[u]) {
        int v, i; tie(v, i) = pp;
        if (!num[v] && !bri[i])
            DFS2(v);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    DFS1(1, -1); timer = 0;
    memset(num, 0, sizeof num);
    memset(low, 0, sizeof low);
    for (int u = 1; u <= N; u++)
        if (!num[u]) {
            timer++; DFS2(u);
        }
    for (int u = 1; u <= N; u++)
        for (auto pp : adj[u]) {
            int v, i; tie(v, i) = pp;
            if (bri[i])
                tree[num[u]].
                push_back(num[v]);
        }
    int res = 0;
    for (int u = 1; u <= timer; u++) {
        memset(DP, 0, sizeof DP);
        DP[0] = 1;
        for (int v : tree[u]) {
            int x = low[v];
            for (int i = N; i >= x; i--)
                DP[i] |= DP[i - x];
        }
        for (int i = 0; i <= N; i++)
            if (DP[i]) {
                cerr << u << ' ' << i << '\n';
                int j = N - i - low[u];
                res = max(res, i * j
                + low[u] * (i + j));
            }
    }
    cout << res << '\n';
}
