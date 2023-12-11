#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back

template <class X, class Y>
bool cmin(X &a, const Y &b){
    return a > b ? a = b, 1 : 0;
}

const int N = 1e5 + 5;
const int inf = 0x3f3f3f3f;

struct seg_tree {
	int t[4 * N], n;

	seg_tree() {
		memset(t, 0x3f, sizeof t);
	}

	void update(int i, int l, int r, int p) {
		if (l > p || r < p) return;
		if (l == r) {
			t[i] = t[i] == inf ? p : inf;
			return;
		}
		int m = (l + r) / 2;
		update(i * 2, l, m, p);
		update(i * 2 + 1, m + 1, r, p);
		t[i] = min(t[i * 2], t[i * 2 + 1]);
	}

	int query(int i, int l, int r, int lo, int hi) {
		if (l > hi || r < lo) return inf;
		if (l >= lo && r <= hi) return t[i];
		int m = (l + r) / 2;
		return min(query(i * 2, l, m, lo, hi),
		query(i * 2 + 1, m + 1, r, lo, hi));
	}

	void update(int p) {
		update(1, 1, n, p);
	}

	int query(int l, int r) {
		return query(1, 1, n, l, r);
	}
} st;

vector <int> adj[N];
int head[N], in[N], out[N];
int dep[N], par[N], tim, ver[N];

int dfs_init(int u) {
	int u_sz = 1, maxv_sz = 0, v_sz;
	for (int &v : adj[u]) {
		if (v == par[u]) continue;
		par[v] = u;
		dep[v] = dep[u] + 1;
		u_sz += v_sz = dfs_init(v);
		if (v_sz > maxv_sz) {
			maxv_sz = v_sz;
			swap(v, adj[u][0]);
		}
	}
	return u_sz;
}

void dfs_hld(int u) {
	in[u] = ++tim; ver[in[u]] = u;
    if (par[u] && u == adj[par[u]][0])
        head[u] = head[par[u]];
    else head[u] = u;
    for (int v : adj[u])
        if (v != par[u]) dfs_hld(v);
    out[u] = tim;
}

void update(int u) {
	st.update(in[u]);
}

int query(int u, int v) {
	int res = inf;
    while (head[u] != head[v]){
        if (dep[head[u]] < dep[head[v]])
            swap(u, v);
        cmin(res, st.query(in[head[u]], in[u]));
        u = par[head[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    cmin(res, st.query(in[v], in[u]));
    return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, q; cin >> n >> q; st.n = n;
	for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
	}
	dfs_init(1); dfs_hld(1);
	while (q--) {
        int cmd, u; cin >> cmd >> u;
        if (cmd) {
            int x = query(1, u);
            if (x == inf) cout << "-1\n";
            else cout << ver[x] << '\n';
        }
        else update(u);
	}
}
