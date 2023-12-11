#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 4e5 + 5;

vector <int> adj[N]; int sz[N];
int val[N], n, k, dp[N];
int lim, res, maxC[N], full[N];


void DFS0(int u, int p) {
    adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
    for (int v : adj[u])
        if (v != p) DFS0(v, u);
}

void DFS1(int u) {
    sz[u] = 1;
    dp[u] = full[u] = maxC[u] = 0;
    for (int v : adj[u]) {
        DFS1(v); sz[u] += sz[v];
    }
    if (val[u] < lim) return;
    dp[u] = 1;
    for (int v : adj[u]) {
        if (dp[v] == sz[v])
            full[u] += sz[v];
        else cmax(maxC[u], dp[v]);
    }
    dp[u] += full[u] + maxC[u];
}

void DFS2(int u, int p) {
    res = max(res, dp[u]);
    int sum = 0, mx1 = 0, mx2 = 0, vmax = 0;
    for (int v : adj[u]) {
        if (dp[v] == sz[v]) sum += sz[v];
        else if (mx1 < dp[v]) {
            mx2 = mx1; mx1 = dp[v]; vmax = v;
        }
        else cmax(mx2, dp[v]);
    }
    for (int v : adj[u]) {
        int dpu = 0;
        if (val[u] >= lim) {
            int maxcu = 0, fullu = sum;
            dpu = 1;
            if (dp[v] == sz[v]) fullu -= sz[v];
            else if (vmax == v) maxcu = mx2;
            else maxcu = mx1;
            if (p) {
                if (dp[p] == n - sz[u])
                    fullu += dp[p];
                else cmax(maxcu, dp[p]);
            }
            dpu += fullu + maxcu;

        }
        swap(dp[u], dpu); int dpv = dp[v];
        if (val[v] >= lim) {
            dp[v] = full[v] + 1;
            if (dp[u] == n - sz[v])
                dp[v] += dp[u];
            else dp[v] += max(maxC[v], dp[u]);
        }
        else dp[v] = 0;
        DFS2(v, u);
        swap(dpu, dp[u]);
        swap(dpv, dp[v]);
    }

}

bool check() {
    res = 0; DFS1(1); DFS2(1, 0);
    if (res >= k) return true;
    return false;
}

int main() {
    // freopen("dfs.inp", "r", stdin);
    // freopen("dfs.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    adj[1].push_back(0); DFS0(1, 0);
    int lo = 0, hi = 1e6;
    while (lo < hi) {
        lim = (lo + hi + 1) / 2;
        if (check()) lo = lim;
        else hi = lim - 1; 
    }
    cout << lo << '\n';
}