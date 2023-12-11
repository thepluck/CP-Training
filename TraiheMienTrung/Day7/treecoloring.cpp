#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int inf = 0x3f3f3f3f;
int dp[N], fi[N], se[N], p[N];

void go(int u) {
    int v = p[u], ls = dp[v];
    if (u == 1) return;
    if (fi[v] != u && se[v] != u) {
        if (dp[se[v]] < dp[u])
            se[v] = u;
    }
    if (dp[se[v]] > dp[fi[v]])
        swap(fi[v], se[v]);
    dp[v] = max(dp[fi[v]] + (v == 1),
                dp[se[v]] + 1);
    if (dp[v] != ls) go(v);
}

int main() {
    freopen("treecoloring.inp", "r", stdin);
    freopen("treecoloring.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n; cin >> n; n++; dp[0] = -1;
    for (int i = 2; i <= n; i++) {
        cin >> p[i]; go(i);
        cout << dp[1] << '\n';
    }
}
