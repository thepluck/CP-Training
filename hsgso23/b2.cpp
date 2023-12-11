#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5+5;
int sub, t, n, q, mod;
string s;

int pi[N];
void kmp() {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    for (int i = n; i >= 1; i--) {
        pi[i] = pi[i-1];
    }
}

int val[N];
vector<int> adj[N];

int up[N][20], ln[N][20];
int timer = 0, tin[N], tout[N];

void dfs(int u, int pr) {
    tin[u] = ++timer;
    up[u][0] = pr; ln[u][0] = val[pr];
    for (int i = 1; i <= 18; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
        ln[u][i] = max(ln[u][i-1], ln[up[u][i-1]][i-1]);
    }
    for (auto v : adj[u]) {
        if (v == pr) continue;
        dfs(v, u);
    }
    tout[u] = timer;
}

bool isAnc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;
    for (int i = 18; i >= 0; i--) {
        if (!isAnc(up[v][i], u)) 
            v = up[v][i];
    }
    return up[v][0];
}

int get(int u, int v) {
    if (u == v) return 0;
    int ans = val[u];
    for (int i = 18; i >= 0; i--) {
        if (!isAnc(up[u][i], v)) {
            ans = max(ans, ln[u][i]);
            u = up[u][i];
        }
    }
    return ans;
}

void solve() {
    timer = 0;
    cin >> n >> q >> mod >> s;
    kmp(); s = " " + s; 
    val[0] = 1;
    for (int i = 1; i <= n; i++) {
        val[i] = val[i-1] * (s[i] - 'a' + 1) % mod;
    }
    for (int i = 0; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) {
        adj[i].push_back(pi[i]);
        adj[pi[i]].push_back(i);
    }
    dfs(0, 0);
    while (q--) {
        int a, b; cin >> a >> b;
        int d = lca(a, b);
        cout << max(get(a, d), get(b, d)) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> sub >> t;
    while (t--) {
        solve();
    }
}