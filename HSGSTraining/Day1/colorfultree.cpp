//https://codeforces.com/gym/102253/problem/C
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb pop_back

using ll = long long;

const int N = 2e5 + 5;
int n, sz[N], c[N], sub[N], cnt[N], last[N];
vector <int> adj[N]; ll res[N];

void dfs(int u, int p) {
    sz[u] = 1; ll tmp = 0;
    int pre = last[c[u]], ssub = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        last[c[u]] = v; dfs(v, u);
        res[c[u]] += tmp * (sz[v] - sub[v]);
        sz[u] += sz[v]; ssub += sub[v];
        tmp += sz[v] - sub[v];
    }
    cnt[c[u]] += sz[u] - ssub;
    res[c[u]] += 1ll * (sz[u] - ssub) *
                (n - cnt[c[u]] + 1);
    sub[pre] += sz[u]; last[c[u]] = pre;
}

ll solve() {
    for (int i = 1; i <= n; i++) {
        cin >> c[i]; 
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }
    dfs(1, 0); ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += res[i];
        res[i] = sz[i] = c[i] = 0;
        sub[i] = cnt[i] = last[i] = 0;
        adj[i].clear();
    }
    return ans - n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 0;
    while (cin >> n) {
        cout << "Case #" << ++tc << ": ";
        cout << solve() << '\n';
    }
}