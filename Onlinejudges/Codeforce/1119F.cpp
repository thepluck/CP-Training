#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const long long INF = 1e18;
const int MAXN = 250005;

struct Fenwick {
    vector <int> cnt; int N, LOG;
    vector <long long> sum;

    void init(int N) {
        this->N = N;
        LOG = 32 - __builtin_clz(N);
        cnt.assign(N + 1, 0);
        sum.assign(N + 1, 0);
    }

    void add(int i, int v) {
        for (; i <= N; i += i & -i) {
            cnt[i]++; sum[i] += v;
        }
    }

    long long get(int k) {
        if (k < 0) return 0;
        int p = 0; long long ans = 0;
        for (int l = 1 << LOG; l > 0; l >>= 1)
            if (p + l <= N && k >= cnt[p + l]) {
                k -= cnt[p += l]; ans += sum[p];
            }
        return k > 0 ? INF : ans;
    }
};

int par[MAXN], val[MAXN], ord[MAXN];
vector <pair <int, int>> adj[MAXN];
long long DP[MAXN][2];
int prv[MAXN], nxt[MAXN], ptr, lim;
int tin[MAXN], tout[MAXN], ver[MAXN];
Fenwick BIT[MAXN];

void del(int i) {
    nxt[prv[i]] = nxt[i];
    prv[nxt[i]] = prv[i];
}

void DFS1(int u) {
    ver[tin[u] = ++ptr] = u;
    for (int i = 0; i < adj[u].size(); i++) {
        int v, w; tie(w, v) = adj[u][i];
        if (v != par[u]) {
            par[v] = u; val[v] = w;
            ord[v] = i + 1; DFS1(v);
        }
    }
    tout[u] = ptr;
}

void DFS2(int u) {
    vector <long long> tmp;
    long long sum = 0;
    while (nxt[ptr] <= tout[u]) {
        ptr = nxt[ptr];
        int v = ver[ptr]; DFS2(v);
        if (par[v] == u) {
            sum += DP[v][0];
            tmp.push_back(DP[v][1] - DP[v][0]);
        } else sum += min(DP[v][1], DP[v][0]);
    }
    sort(tmp.begin(), tmp.end());
    int can = adj[u].size() - lim;
    DP[u][0] = min(INF, sum + BIT[u].get(can));
    DP[u][1] = min(INF, sum + BIT[u].get(can - 1));
    for (int i = 0; i < tmp.size(); i++) {
        sum += tmp[i];
        cmin(DP[u][0], sum + BIT[u].get(can - i - 1));
        cmin(DP[u][1], sum + BIT[u].get(can - i - 2));
    }
    if (u) DP[u][1] += val[u];
    else DP[u][1] = INF;
}

long long compute() {
    ptr = 0; long long ans = 0;
    while (nxt[ptr] <= tout[0]) {
        ptr = nxt[ptr];
        int u = ver[ptr]; DFS2(u);
        ans += min(DP[u][0], DP[u][1]);
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector <int> nodes;
    for (int i = 0; i < N; i++) {
        adj[i].clear();
        prv[i + 1] = i; nxt[i + 1] = i + 2;
        nodes.push_back(i);
    }
    prv[N + 1] = N; nxt[0] = 1;
    long long sum = 0;
    for (int i = 0; i + 1 < N; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[--u].emplace_back(w, --v);
        adj[v].emplace_back(w, u);
        sum += w;
    }
    cout << sum;
    for (int i = 0; i < N; i++) {
       BIT[i].init(adj[i].size());
       sort(adj[i].begin(), adj[i].end());
    }
    DFS1(ptr = 0);
    sort(nodes.begin(), nodes.end(),
    [&](int u, int v) {
        return adj[u].size() < adj[v].size();
    });
    for (int i = 1, j = 0; i < N; i++) {
        while (j < N && adj[nodes[j]].size() <= i) {
            int u = nodes[j++];
            if (u && adj[par[u]].size() > i)
                BIT[par[u]].add(ord[u], val[u]);
            del(tin[u]);
        }
        lim = i; cout << ' ' << compute();
    }
}
