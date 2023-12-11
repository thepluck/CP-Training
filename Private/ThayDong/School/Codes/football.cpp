#include <bits/stdc++.h>
using namespace std;

#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define parity __builtin_parityll

using ll = long long;

const int N = 505;

int n, m, k, p[N], dp[N][N], deg[N];
ll ms[N], res; bool vs[N], in[N];
vector <int> adj[N], spec;

void rec(ll rem, ll cur) {
    if (popcnt(cur) + popcnt(rem) < popcnt(res)) return;
    if (!rem) {
        if (!parity(cur) && popcnt(cur) > popcnt(res))
            res = cur;
        return;
    }
    int u = ctz(rem);
    rec((rem ^ (1ll << u)) & ms[u], cur | (1ll << u));
    rec(rem ^ (1ll << u), cur);
}



void solve() {
    spec.clear();
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i]; adj[i].clear();
    }
    int l = k & 1 ? k + 1 : k + 2;
    if (n <= 50) {
        res = 0;
        for (int i = 0; i < n; i++)
            ms[i] = (1ll << n) - 1;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            u--; v--;
            ms[u] &= ~(1ll << v);
            ms[v] &= ~(1ll << u);
        }
        if (count(p, p + n, 1) == n)
            rec((1ll << n) - 1, 0);
        else {
            int ans = 0;
            for (int x = 0; x < (1ll << n); x++) {
                if (popcnt(x) < l || parity(x))
                    continue;
                int y = (1ll << n) - 1, s = 0;
                for (int i = 0; i < n; i++)
                    if (x >> i & 1) {
                        y &= ms[i]; s += p[i];
                    }
                if ((y | x) == y && ans < s) {
                    ans = s; res = x;
                }
            }
        }
        if (popcnt(res) < l) {
            cout << "-1\n"; return;
        }
        vector <int> cur;
        for (int i = 0; i < n; i++)
            if (res >> i & 1)
                cur.push_back(i);
        cout << cur.size() << '\n';
        for (int x : cur)
            cout << x + 1 << ' ';
        cout << '\n';
        while (k--) {
            for (int i = 0; i < cur.size() / 2; i++)
                cout << cur[i] + 1 << ' ' <<
                cur[cur.size() - i - 1] + 1 << ' ';
            cout << '\n';
            rotate(cur.begin() + 1,
            cur.begin() + 2, cur.end());
        }
    }
    
}

int main() {
    //freopen("football.inp", "r", stdin);
    //freopen("football.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}