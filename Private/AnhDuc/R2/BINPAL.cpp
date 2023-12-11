#include <bits/stdc++.h>

using namespace std;

struct Trie {
    vector <array <int, 2>> nxt;
    vector <int> link, label, leaf, par;

    Trie() {
        nxt.emplace_back();
        link.emplace_back();
        label.emplace_back();
        leaf.emplace_back();
        par.emplace_back();
    }
    
    struct state {
        int u, v, t;
    
        state(int u, int v, int t): u(u), v(v), t(t) {}
    };

    void add(const string &s) {
        int u = 0;
        for (char c : s) {
            if (!nxt[u][c - '0']) {
                nxt[u][c - '0'] = nxt.size();
                nxt.emplace_back();
                link.emplace_back();
                label.emplace_back(c - '0');
                leaf.emplace_back();
                par.push_back(u);
            }
            u = nxt[u][c - '0'];
        }
        leaf[u] = 1;
    }

    void build() {
        queue <int> que; que.push(0);
        while (que.size()) {
            int u = que.front(); que.pop();
            leaf[u] |= leaf[link[u]];
            for (int c = 0; c < 2; c++) {
                int v = nxt[u][c];
                if (v) {
                    link[v] = u ? nxt[link[u]][c] : 0;
                    que.push(v);
                }
                else nxt[u][c] = nxt[link[u]][c];
            }
        }
    }
} tr1, tr2;

const int MOD = 1e9 + 7;
const int ST = 10005;

int dp[2][2][ST];
pair <int, int> state[ST];
vector <int> adj[2][ST];
map <pair <int, int>, int> idx;

void add(int &x, int y) {
    if ((x += y) >= MOD) x -= MOD;
}

bool match(int u1, int u2) {
    if (tr1.leaf[u1]) return true;
    while (u2) {
        u1 = tr1.nxt[u1][tr2.label[u2]];
        if (tr1.leaf[u1]) return true;
        u2 = tr2.par[u2];
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        string s; cin >> s; tr1.add(s);
        reverse(s.begin(), s.end()); tr2.add(s);
    }
    tr1.build(); tr2.build();
    int cnt = 1, cur = 1, res = 0;
    idx[{0, 0}] = 1; state[1] = {0, 0};
    while (cur <= cnt) {
        int u1, u2; tie(u1, u2) = state[cur];
        for (int c = 0; c < 2; c++) {
            int v1 = tr1.nxt[u1][c];
            int v2 = tr2.nxt[u2][c];
            if (!tr1.leaf[v1] && !tr2.leaf[v2]) {
                if (!idx.count({v1, v2})) {
                    idx[{v1, v2}] = ++cnt;
                    state[cnt] = {v1, v2};
                }
                adj[0][cur].push_back(idx[{v1, v2}]);
            }
            if (tr1.leaf[v1] ^ tr2.leaf[v2]) {
                if (tr1.leaf[v1]) v1 = 0;
                else v2 = 0;
                if (!idx.count({v1, v2})) {
                    idx[{v1, v2}] = ++cnt;
                    state[cnt] = {v1, v2};
                }
                adj[1][cur].push_back(idx[{v1, v2}]);
            }
        }
        cur++;
    }
    dp[0][0][1] = 1;
    for (int i = 1; i <= n / 2; i++) {
        memset(dp[i & 1], 0, sizeof dp[i & 1]);
        for (int x = 1; x <= cnt; x++) {
            for (int y : adj[0][x]) {
                add(dp[i & 1][0][y], dp[~i & 1][0][x]);
                add(dp[i & 1][1][y], dp[~i & 1][1][x]);
            }
            for (int y : adj[1][x])
                add(dp[i & 1][1][y], dp[~i & 1][0][x]);
        }
    }
    if (n & 1) {
        for (int x = 1; x <= cnt; x++) {
            int u1, u2; tie(u1, u2) = state[x];
            for (int c = 0; c < 2; c++)
                if (match(tr1.nxt[u1][c], u2))
                    add(res, dp[(n / 2) & 1][0][x]);
                else {
                    add(res, dp[(n / 2) & 1][0][x]);
                    add(res, dp[(n / 2) & 1][1][x]);
                }
        }
    }
    else {
        for (int x = 1; x <= cnt; x++) {
            int u1, u2; tie(u1, u2) = state[x];
            if (match(u1, u2))
                add(res, dp[(n / 2) & 1][0][x]);
            else {
                add(res, dp[(n / 2) & 1][0][x]);
                add(res, dp[(n / 2) & 1][1][x]);
            }
        }
    }
    cout << res << '\n';
}