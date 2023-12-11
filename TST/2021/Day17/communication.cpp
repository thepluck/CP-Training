#include <bits/stdc++.h>

using namespace std;

struct segTree {
    int val, tag, l, r, m;
    segTree *lef, *rig;

    segTree(int l, int r): l(l), r(r) {
        val = tag = 0;
        if (l + 1 < r) {
            m = (l + r) / 2;
            lef = new segTree(l, m);
            rig = new segTree(m, r); 
        }
    }

    void apply(int v) {
        val += v; tag += v;
    }

    void push() {
        lef->apply(tag);
        rig->apply(tag);
        tag = 0;
    }

    void add(int x, int y, int v) {
        if (l >= x && r <= y)
            return apply(v);
        push();
        if (m > x) lef->add(x, y, v);
        if (m < y) rig->add(x, y, v);
        val = min(lef->val, rig->val);
    }
};

const int N = 100005;

vector <int> adj[N];
pair <int, int> node[2][N];
pair <int, int> range[2][N];
int lef[N], rig[N], par[N];
bool mark[N];
pair <int, int> ans[N];

int root(int u) {
    return par[u] ? par[u] = root(par[u]) : u;
}

void unite(int u, int v) {
    u = root(u); v = root(v);
    if (u == v) return;
    lef[u] = min(lef[u], lef[v]);
    rig[u] = max(rig[u], rig[v]);
    par[v] = u;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m[2], q;
    cin >> n >> m[0] >> m[1] >> q;
    for (int idx = 0; idx < 2; idx++) {
        for (int i = 1; i <= m[idx]; i++) {
            cin >> node[idx][i].first;
            cin >> node[idx][i].first;
            node[idx][i].second = i;
            if (idx) node[idx][i].first *= -1;
            lef[i] = INT_MAX; rig[i] = INT_MIN;
            mark[i] = false; par[i] = 0;
            adj[i].clear();
        }
        sort(node[idx] + 1, node[idx] + m[idx] + 1);
        for (int i = 1; i < n + m[idx]; i++) {
            int cmd, u, v;
            cin >> cmd >> u >> v;
            if (cmd == 1) {   
                lef[v] = min(lef[v], u);
                rig[v] = max(rig[v], u);
            }
            else {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        for (int i = 1; i <= m[idx]; i++) {
            int u = node[idx][i].second;
            for (int v : adj[u])
                if (mark[v]) unite(u, v);
            mark[u] = true; u = root(u);
            range[idx][i] = {lef[u], rig[u]};
        }
    }
    segTree ST(1, n);
    for (int i = 1, l, r; i <= m[0]; i++) {
        tie(l, r) = range[0][i];
        if (l < r) ST.add(l, r, 1);
    }
    for (int i = m[0], j = 0, l, r; i >= 0; i--) {
        while (!ST.val) {
            tie(l, r) = range[1][++j];
            if (l < r) ST.add(l, r, 1);
        }
        ans[i] = {node[0][i].first, -node[1][j].first};
        tie(l, r) = range[0][i];
        if (l < r) ST.add(l, r, -1);
    }
    while (q--) {
        int val; cin >> val;
        cout << (upper_bound(ans + 1, ans + m[0] + 1,
        make_pair(val, INT_MAX)) - 1)->second << '\n';
    }
}
