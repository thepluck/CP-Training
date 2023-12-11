#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int N = 105, L = 125;

int dp[N][L], tmp[L], lim;
vector <pair <int, int>> adj[N];

void dfs(int u, int p) {
    memset(dp[u], 0xc0, sizeof dp[u]);
    dp[u][0] = 0;
    for (auto edge : adj[u]) {
        int v, w; tie(v, w) = edge;
        if (v == p) continue;
        dfs(v, u); int d = -(w % 60);
        memset(tmp, 0xc0, sizeof tmp);
        for (int b1 = 0; b1 <= lim; b1++) {
            int a1 = dp[u][b1];
            for (int b2 = 0; b2 <= lim; b2++) {
                int a2 = dp[v][b2];
                if (max(abs(a1 + a2 + d), abs(b1 + b2 + d)) <= lim)
                    cmax(tmp[max(b1, b2 + d)], min(a1, a2 + d));
            }
        }
        d = (60 - w % 60) % 60;
        for (int b1 = 0; b1 <= lim; b1++) {
            int a1 = dp[u][b1];
            for (int b2 = 0; b2 <= lim; b2++) {
                int a2 = dp[v][b2];
                if (max(abs(a1 + a2 + d), abs(b1 + b2 + d)) <= lim)
                    cmax(tmp[max(b1, b2 + d)], min(a1, a2 + d));
            }
        }
        for (int b = 0; b <= lim; b++)
            dp[u][b] = tmp[b];
    }
}

bool check() {
    dfs(1, 0);
    for (int b = 0; b <= lim; b++)
        if (dp[1][b] >= -lim) return true;
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, tc = 0;
    while (cin >> n) {
        if (n == 0) break; tc++;
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        int lo = 0, hi = 120;
        while (lo < hi) {
            lim = (lo + hi) / 2;
            if (check()) hi = lim;
            else lo = lim + 1;
        }
        cout << "Case " << tc << ": " << hi << '\n';
    }
}
