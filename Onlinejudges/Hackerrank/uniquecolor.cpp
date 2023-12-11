
// Problem : Unique Colors
// Contest : HackerRank
// URL : https://www.hackerrank.com/contests/may-world-codesprint/challenges/unique-colors/problem
// Memory Limit : 512 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back

using ii = pair <int, int>;

const int N = 1e5 + 5;

int a[N], sz[N];
int cnt[N], has[N];
vector <ii> last[N];
vector <int> g[N];
long long ans[N];

void dfs1(int u, int p = 0) {
    last[a[u]].eb(u, 0);
    sz[u] = 1;
    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u); sz[u] += sz[v];
    }
    last[a[u]].pop_back();
    if (last[a[u]].size())
        last[a[u]].back().se += sz[u];
    else {
        cnt[a[u]] += sz[u];
        ans[1] += sz[u];
    }
    if (p) {
        has[u] = last[a[p]].back().se;
        last[a[p]].back().se = 0;
    }
}

void dfs2(int u, int p = 0) {
    int cur, pcur;
    if (p) {
        ans[u] = ans[p];
        if (a[u] != a[p]) {
            cur = cnt[a[u]];
            pcur = cnt[a[p]];
            cnt[a[u]] = sz[1];
            cnt[a[p]] -= sz[u] - has[u];
            ans[u] += cnt[a[u]] - cur;
            ans[u] += cnt[a[p]] - pcur;
        }
    }
    for (int v : g[u])
        if (v != p) dfs2(v, u);
    if (p && a[u] != a[p]) {
        cnt[a[u]] = cur;
        cnt[a[p]] = pcur;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].eb(v); g[v].eb(u);
    }
    dfs1(1); dfs2(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
}