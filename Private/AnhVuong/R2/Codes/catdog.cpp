#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}

const int INF = 1e9;

struct Tp {
    int val[2][2];

    Tp operator + (const Tp &o) const {
        Tp res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                res.val[i][j] = min({INF,
                val[i][0] + o.val[1][j] + 1,
                val[i][1] + o.val[0][j] + 1,
                val[i][0] + o.val[0][j],
                val[i][1] + o.val[1][j]});
            }
        return res;
    }
};

struct segTree {
private:
    vector <Tp> tr; int n, lo, hi;

    void build(int i, int l, int r) {
        if (l == r) {
            tr[i].val[0][0] = tr[i].val[1][1] = 0;
            tr[i].val[0][1] = tr[i].val[1][0] = INF;
        }
        else {
            int m = (l + r) / 2;
            build(i * 2, l, m);
            build(i * 2 + 1, m + 1, r);
            tr[i] = tr[i * 2] + tr[i * 2 + 1];
        }
    }

    void update(int i, int l, int r, int v0, int v1) {
        if (l == r) {
            tr[i].val[0][0] += v0;
            tr[i].val[1][1] += v1;
            return;
        }
        int m = (l + r) / 2;
        if (m >= lo) update(i * 2, l, m, v0, v1);
        else update(i * 2 + 1, m + 1, r, v0, v1);
        tr[i] = tr[i * 2] + tr[i * 2 + 1];
    }

public:
    void init(int n) {
        this->n = n; tr.resize(n * 4); build(1, 1, n);
    }

    void update(int p, int v0, int v1) {
        lo = p; update(1, 1, n, v0, v1);
    }

    void query(int &v0, int &v1) {
        int t0 = min(tr[1].val[0][0], tr[1].val[0][1]);
        int t1 = min(tr[1].val[1][0], tr[1].val[1][1]);
        v0 = min(t0, t1 + 1); v1 = min(t0 + 1, t1);
    }
};

const int N = 100005;

vector <int> adj[N]; segTree ST[N];
int hv[N], head[N], par[N], col[N];
int pos[N], grpID[N], grpSz[N], cntGrp;

int DFS1(int u) {
    int siz = 1, maxSiz = 0, tmp;
    for (int v : adj[u]) if (v != par[u]) {
        par[v] = u; siz += tmp = DFS1(v);
        if (maxSiz < tmp) {
            maxSiz = tmp; hv[u] = v;
        }
    }
    return siz;
}

void DFS2(int u) {
    if (u == hv[par[u]]) {
        grpID[u] = grpID[par[u]];
        head[u] = head[par[u]];
    }
    else {
        grpID[u] = ++cntGrp;
        head[u] = u;
    }
    pos[u] = ++grpSz[grpID[u]];
    for (int v : adj[u])
        if (v != par[u]) DFS2(v);
}

int change(int u, int v0, int v1) {
    while (u) {
        int id = grpID[u];
        int cur0, cur1, nxt0, nxt1;
        ST[id].query(cur0, cur1);
        ST[id].update(pos[u], v0, v1);
        ST[id].query(nxt0, nxt1);
        v0 = nxt0 - cur0;
        v1 = nxt1 - cur1;
        u = par[head[u]];
    }
    ST[1].query(v0, v1);
    return min(v0, v1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    fill(col + 1, col + n + 1, 3);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS1(1); DFS2(1);
    for (int i = 1; i <= cntGrp; i++)
        ST[i].init(grpSz[i]);
    int q; cin >> q;
    while (q--) {
        int t, u; cin >> t >> u;
        if (col[u] == 1)
            cout << change(u, 0, -N) << '\n';
        else if (col[u] == 2)
            cout << change(u, -N, 0) << '\n';
        else {
            if (t == 1)
                cout << change(u, 0, N) << '\n';
            else cout << change(u, N, 0) << '\n';
        }
        col[u] = t;
    }
}