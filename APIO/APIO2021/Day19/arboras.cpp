#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MOD = 1000000007;

struct segment_tree1 {
    int val, sum, tag;
    int l, r, m;
    segment_tree1 *lef, *rig;

    segment_tree1(int l, int r):
    val(0), sum(0), tag(0), l(l), r(r) {
        if (l == r) return;
        m = (l + r) / 2;
        lef = new segment_tree1(l, m);
        rig = new segment_tree1(m + 1, r);
    }

    void apply(int v) {
        if (v) {
            val = tag = v;
            sum = v * (r - l + 1) % MOD;
        }
    }

    void push() {
        lef->apply(tag);
        rig->apply(tag);
        tag = 0;
    }

    void pull() {
        val = min(lef->val, rig->val);
        sum = (lef->sum + rig->sum) % MOD;
    }

    void assign(int x, int y, int v) {
        if (l > y || r < x) return;
        if (l >= x && r <= y)
            return apply(v);
        push();
        lef->assign(x, y, v);
        rig->assign(x, y, v);
        pull();
    }

    int find_pos(int x, int y, int v) {
        if (l > y || r < x || val >= v) return 0;
        if (l == r) return l;
        int p = lef->find_pos(x, y, v);
        if (!p) p = rig->find_pos(x, y, v);
        return p;
    }
};


struct segment_tree2 {
    int val, tag;
    int l, r, m;
    segment_tree2 *lef, *rig;

    segment_tree2(int l, int r):
    val(0), tag(0), l(l), r(r) {
        if (l == r) return;
        m = (l + r) / 2;
        lef = new segment_tree2(l, m);
        rig = new segment_tree2(m + 1, r);
    }

    void apply(int v) {
        val += v; tag += v;
    }

    void push() {
        lef->apply(tag);
        rig->apply(tag);
        tag = 0;
    }

    void pull() {
        val = max(lef->val, rig->val);
    }

    void add(int x, int y, int v) {
        if (l > y || r < x) return;
        if (l >= x && r <= y)
            return apply(v);
        
    }
};

const int MAXN = 100005;

vector <int> adj[MAXN];
int par[MAXN], dep[MAXN], heavy[MAXN];
int tin[MAXN], tout[MAXN], siz[MAXN];
int timer, head[MAXN], N, Q, wpar[MAXN];

void DFS1(int u) {
    for (int v : adj[u]) {
		dep[v] = dep[u] + 1; DFS1(v);
        siz[u] += siz[v];
        if (siz[heavy[u]] < siz[v])
            heavy[u] = v; 
    }
}
 
void DFS2(int u) {
    tin[u] = ++timer;
    if (par[u] && u == heavy[par[u]])
        head[u] = head[par[u]];
    else head[u] = u;
    if (heavy[u]) DFS2(heavy[u]);
    for (int v : adj[u])
        if (v != par[u] && v != heavy[u])
            DFS2(v);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> par[i]; par[i]++;
    }
    for (int i = 2; i <= N; i++)
        cin >> wpar[i];
    
}