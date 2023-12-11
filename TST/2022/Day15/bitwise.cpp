#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int LOG = 14;
const int MOD = 1e9 + 7;

pair<int, int> que[N];
vector<int> adj[N];
int ans[N]; int* dp[N];

int add(int x, int y) {
    return (x += y) >= MOD ? x - MOD : x;
}

void dfs(int u) {
    for (int v : adj[u]) {
        if (que[v].first == 4) {
            ans[v] = dp[u][que[v].second]; continue;
        }
        dp[v] = new int[1 << LOG];
        for (int i = 0; i < (1 << LOG); i++)
            dp[v][i] = dp[u][i];
        if (que[v].first == 0) {
            for (int i = 0; i < (1 << LOG); i++)
                dp[v][i & que[v].second] = add
                (dp[v][i & que[v].second], dp[u][i]);
        } else if (que[v].first == 1) {
            for (int i = 0; i < (1 << LOG); i++)
                dp[v][i | que[v].second] = add
                (dp[v][i | que[v].second], dp[u][i]);
        } else if (que[v].first == 2) {
            for (int i = 0; i < (1 << LOG); i++)
                dp[v][i ^ que[v].second] = add
                (dp[v][i ^ que[v].second], dp[u][i]);
        }
    }
    free(dp[u]);
    for (int v : adj[u])
        if (que[v].first != 4) dfs(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    bool flag = true;
    vector<int> cur(1, 0);
    for (int i = 1; i <= q; i++) {
        string cmd; cin >> cmd;
        if (cmd == "AND") {
            que[i].first = 0;
            flag = false;
        } else if (cmd == "OR") {
            que[i].first = 1;
            flag = false;
        } else if (cmd == "XOR") {
            que[i].first = 2;
        } else if (cmd == "REMOVE") {
            que[i].first = 3;
        } else {
            que[i].first = 4;
        }
        if (cmd != "REMOVE") {
            adj[cur.back()].push_back(i);
            cin >> que[i].second;
        } else cur.pop_back();
        if (que[i].first <= 2)
            cur.push_back(i);
    }
    dp[0] = new int[1 << LOG];
    dp[0][0] = 1; dfs(0);
    for (int i = 1; i <= q; i++)
        if (que[i].first == 4)
            cout << ans[i] << '\n';

}