#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool chkmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 1e5 + 5;

int fi[N], se[N], p[N];
int tim, ver[N], ans[N];
vector <int> adj[N];

void dfs(int u) {
    ver[++tim] = u;
    for (int v : adj[u]) {
        if (v == p[u]) continue;
        p[v] = u; dfs(v);
    }
}

void cal(int k) {
    for (int i = 1; i <= tim; i++)
        fi[i] = se[i] = 0;
    for (int i = tim; i > 0; i--) {
        int u = ver[i];
        if (fi[u] + se[u] + 1 >= k) {
            ans[k]++; fi[u] = 0;
        }
        else fi[u]++;
        chkmax(se[p[u]], fi[u]);
        if (se[p[u]] > fi[p[u]])
            swap(se[p[u]], fi[p[u]]);
    }
}

void solve(int l, int r,
            int vl, int vr) {
    if (l > r || vl > vr) return;
    if (vl == vr) {
        for (int i = l; i <= r; i++)
            ans[i] = vl;
        return;
    }
    int m = (l + r) / 2; cal(m);
    solve(l, m - 1, ans[m], vr);
    solve(m + 1, r, vl, ans[m]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1); solve(1, n, 0, n);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}