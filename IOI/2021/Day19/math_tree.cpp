#include <bits/stdc++.h>

using namespace std;


const int MOD = 1000000007;

int add(int x, int y) {
    if ((x += y) >= MOD) x -= MOD;
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0) x += MOD;
    return x;
}

int mul(int x, int y) {
    return (long long)x * y % MOD;
}

int neg(int x) {
    return sub(0, x);
}

struct node {
    int lef, mid, rig; bool full;

    node(int x = 0) {
        lef = x;
        rig = mid = 0; full = true;
    }

    int val() {
        return add(lef, add(mid, rig));
    }
};


node merge(const node &a, const node &b, int op) {
    node c;
    if (a.full) {
        if (b.full) {
            if (op == 2) {
                c.lef = mul(a.lef, b.lef);
            } else {
                c.full = false;
                c.lef = a.lef;
                c.rig = op ? neg(b.lef) : b.lef;
            }
        } else {
            c.full = false;
            if (op == 2) {
                c.lef = mul(a.lef, b.lef);
                c.mid = b.mid; c.rig = b.rig;
            } else {
                c.lef = a.lef;
                c.mid = add(op ? neg(b.lef) : b.lef, b.mid);
                c.rig = b.rig;
            }
        }
    } else {
        c.full = false;
        if (b.full) {
            if (op == 2) {
                c.lef = a.lef; c.mid = a.mid;
                c.rig = mul(a.rig, b.lef);
            } else {
                c.lef = a.lef;
                c.mid = add(a.mid, a.rig);
                c.rig = op ? neg(b.lef) : b.lef;
            }
        } else {
            c.lef = a.lef;
            c.rig = b.rig;
            if (op == 2) {
                c.mid = add(a.mid, add(mul(a.rig, b.lef), b.mid));
            } else {
                c.mid = add(a.mid, add(a.rig, add(op ? neg(b.lef) : b.lef, b.mid)));
            }
        }
    }
    return c;
}

const int MAXN = 500005;
const int LOG = 19;

vector <pair <int, int>> adj[MAXN];

int oper[MAXN], par[MAXN][LOG], cost[MAXN];
node up[MAXN][LOG], dn[MAXN][LOG]; int dep[MAXN];

void DFS(int u) {
    dep[u] = dep[par[u][0]] + 1;
    for (int i = 1; i < LOG; i++) {
        up[u][i] = merge(up[u][i - 1], up[par[u][i - 1]][i - 1], oper[par[u][i - 1]]);
        dn[u][i] = merge(dn[par[u][i - 1]][i - 1], dn[u][i - 1], oper[par[u][i - 1]]);
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto e : adj[u]) {
        int v, o; tie(v, o) = e;
        if (v != par[u][0]) {
            oper[v] = o; par[v][0] = u;
            up[v][0] = dn[v][0] = cost[u]; DFS(v);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> cost[i];
    for (int i = 1; i < N; i++) {
        int u, v; char c;
        cin >> u >> v >> c;
        int o = c == '+' ? 0 : c == '-' ? 1 : 2;
        adj[u].emplace_back(v, o);
        adj[v].emplace_back(u, o);
    }
    DFS(1);
    while (Q--) {
        int u, v; cin >> u >> v;
        node x(cost[u]), y(cost[v]);
        if (dep[u] < dep[v]) {
            for (int i = LOG - 1; i >= 0; i--)
                if (dep[par[v][i]] >= dep[u]) {
                    y = merge(dn[v][i], y, oper[v]);
                    v = par[v][i]; 
                }
            if (u == v) {
                cout << y.val() << '\n'; continue;
            }
        } else {
            for (int i = LOG - 1; i >= 0; i--)
                if (dep[par[u][i]] >= dep[v]) {
                    x = merge(x, up[u][i], oper[u]);
                    u = par[u][i];
                }
            if (u == v) {
                cout << x.val() << '\n'; continue;
            }
        }
        for (int i = LOG - 1; i >= 0; i--)
            if (par[u][i] != par[v][i]) {
                x = merge(x, up[u][i], oper[u]);
                y = merge(dn[v][i], y, oper[v]);
                u = par[u][i]; v = par[v][i];
            }
        cout << merge(x, merge(up[u][0], y, oper[v]), oper[u]).val() << '\n';
    }
}