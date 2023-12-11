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
int N, M, add; bool bri[MAXM];
int num[MAXN], low[MAXN], timer;
bitset <MAXN> knap;

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

int DFS3(int u, int p) {
    int siz = low[u];
    for (int v : tree[u])
        if (v != p) {
            int tmp = DFS3(v, u);
            siz += tmp;
            add += low[u] * tmp;
        }
    return siz;
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
        knap.reset(); knap[0] = 1;
        add = 0;
        for (int v : tree[u]) {
            int siz = DFS3(v, u);
            knap |= knap << siz;
        }
        for (int i = 0; i <= N; i++)
            if (knap[i]) {
                int j = N - low[u] - i;
                cmax(res, add + i * j
                + low[u] * (i + j));    
            }
    }
    for (int u = 1; u <= timer; u++)
        res += low[u] * low[u];
    cout << res << '\n';
}
