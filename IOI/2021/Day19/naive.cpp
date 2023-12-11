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
            c.mid = add(a.mid, add(a.rig, add(op ? neg(b.lef) : b.lef, b.mid)));
            c.rig = b.rig;
        }
    }
    return c;
}

const int MAXN = 500005;
const int LOG = 19;

vector <pair <int, int>> adj[MAXN];

int oper[MAXN], par[MAXN][LOG], cost[MAXN];
int dep[MAXN], len[MAXN];

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = 18; ~k; k--)
        if (dep[par[u][k]] >= dep[v])
            u = par[u][k];
    if (u == v) return u;
    for (int k = 18; ~k; k--)
        if (par[u][k] != par[v][k]){
            u = par[u][k];
            v = par[v][k];
        }
    return par[u][0];

}

void DFS(int u) {
    dep[u] = dep[par[u][0]] + 1;
    len[u] = len[par[u][0]] + cost[u];
    for (int i = 1; i < LOG; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto e : adj[u]) {
        int v, o; tie(v, o) = e;
        if (v != par[u][0]) {
            par[v][0] = u; DFS(v);
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
        int r = LCA(u, v);
        cout << len[u] + len[v] - len[r] - len[par[r][0]] << '\n';
    }
}