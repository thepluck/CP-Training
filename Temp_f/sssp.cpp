#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

template <class X, class Y>
bool cmin(X &a, const Y &b) {
	return a > b ? a = b, 1 : 0;
}

using ll = long long;

const ll inf = 1e18;

namespace st_val {
	using ii = pair <ll, int>;
	int n, lo, hi; ll v;
	vector <ii> val;
	vector <ll> tag;
	vector <int> cnt;

	void build(int i, int l, int r) {
		val[i] = {tag[i] = inf, l};
		cnt[i] = r - l + 1;
		if (l < r) {
			int m = (l + r) / 2;
			build(i * 2, l, m);
			build(i * 2 + 1, m + 1, r);
		}
	}

	void push_up(int i) {
		val[i] = min(val[i * 2], val[i * 2 + 1]);
		cnt[i] = cnt[i * 2] + cnt[i * 2 + 1];
	}

	void push_tag(int i, ll tg) {
		if (cnt[i]) {
			cmin(val[i].fi, tg);
			cmin(tag[i], tg);
		}
	}

	void push_down(int i) {
		push_tag(i * 2, tag[i]);
		push_tag(i * 2 + 1, tag[i]);
		tag[i] = inf;
	}

	void init(int n = 0){
		st_val::n = n;
		val.resize(4 * n);
		tag.resize(4 * n);
		cnt.resize(4 * n);
		build(1, 1, n);
	}

	void update(int i, int l, int r) {
		if (l > hi || r < lo) return;
		if (l >= lo && r <= hi)
			return push_tag(i, v);
		push_down(i);
		int m = (l + r) / 2;
		update(i * 2, l, m);
		update(i * 2 + 1, m + 1, r);
		push_up(i);
	}

	void update(int l, int r, ll w) {
		lo = l; hi = r; v = w;
		update(1, 1, n);
	}

	void remove(int i, int l, int r) {
		if (l > lo || r < lo) return;
		if (l == r) {
			val[i].fi = inf;
			cnt[i] = 0; return;
		}
		push_down(i);
		int m = (l + r) / 2;
		remove(i * 2, l, m);
		remove(i * 2 + 1, m + 1, r);
		push_up(i);
	}

	void remove(int p) {
		lo = p; remove(1, 1, n);
	}
};

namespace st_edge {
	using ii = pair <int, ll>;

	int n, lo, hi, v; ll w;
	vector <vector <ii>> tr;

	void init(int n = 0){
		st_edge::n = n;
		tr.resize(4 * n);
	}

	void add(int i, int l, int r) {
		if (l > hi || r < lo) return;
		if (l >= lo && r <= hi)
			return tr[i].emplace_back(v, w);
		int m = (l + r) / 2;
		add(i * 2, l, m);
		add(i * 2 + 1, m + 1, r);
	}

	void remove(int i, int l, int r) {
		if (l > lo || r < lo) return;
		for (ii e : tr[i])
			st_val::update(e.fi, e.fi, w + e.se);
		tr[i].clear();
		if (l == r) return;
		int m = (l + r) / 2;
		remove(i * 2, l, m);
		remove(i * 2 + 1, m + 1, r);
	}

	void add(int l, int r, int v, ll w) {
		st_edge::v = v; lo = l;
		st_edge::w = w;	hi = r;
		add(1, 1, n);
	}

	void remove(int p, ll w) {
		lo = p; st_edge::w = w;
		remove(1, 1, n);
	}
};

vector <vector <tuple <int, int, ll>>> adj;
vector <ll> dis;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, s;
	cin >> n >> m >> s;
	st_val::init(n);
	st_val::update(s, s, 0ll);
	st_edge::init(n);
	adj.resize(n + 1);
	dis.resize(n + 1, -1);
	for (int i = 1; i <= m; i++) {
		int t; cin >> t;
		if (t == 1) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].emplace_back(v, v, w);
		}
		if (t == 2) {
			int u, l, r, w;
			cin >> u >> l >> r >> w;
			adj[u].emplace_back(l, r, w);
		}
		if (t == 3) {
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			st_edge::add(l, r, v, w);
		}
	}
	while (true) {
		int u, l, r; ll d, w;
		tie(d, u) = st_val::val[1];
		if (d == inf) break;
		dis[u] = d;
		st_val::remove(u);
		st_edge::remove(u, d);
		for (auto e : adj[u]) {
			tie(l, r, w) = e;
			st_val::update(l, r, d + w);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
}