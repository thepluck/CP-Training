#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 300005;

vector <int> g[N];
vector <int> st, path;
int n, a, b, dp[N];

void dfs1(int u, int p) {
    st.eb(u);
    if (u == b) path = st;
    for (int v : g[u])
        if (v != p) dfs1(v, u);
    st.pop_back();
}

void dfs2(int u, int p, int exc) {
    for (int v : g[u])
        if (v != p && v != exc)
            dfs2(v, u, exc);
    dp[u] = 0; st.clear();
    for (int v : g[u])
        if (v != p && v != exc)
            st.eb(dp[v]);
    sort(rall(st));
    for (int i = 0; i < st.size(); i++)
        dp[u] = max(dp[u], st[i] + i + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    dfs1(a, 0); dfs2(a, 0, 0);
    int res = dp[a];
    int lo = 0, hi = path.size() - 2;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        dfs2(a, 0, path[mi + 1]);
        dfs2(b, 0, path[mi]);
        res = min(res, max(dp[a], dp[b]));
        if (dp[a] < dp[b]) lo = mi + 1;
        else hi = mi - 1;
    }
    cout << res << '\n';
}