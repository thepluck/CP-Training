#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
struct data {
	int u, v, w, l;
	data() {}; data(int u, int v, int w, int l) : u(u), v(v), w(w), l(l) {};
};

const int N = 1e5 + 4, oo = 1e9 + 7;
int n, m, c[N];
vector<ii> adj[N];
vector<data> Edge;

int d[N], minDist[2][N], cost[N];
priority_queue<ii, vector<ii>, greater<ii> > pq;

void Dijkstra() {
	while (pq.size()) {
		int du = pq.top().first, u = pq.top().second; pq.pop();
		if (du != d[u]) continue;

		for (ii foo : adj[u]) {
			int v = foo.second, uv = foo.first;
			if (d[v] > du + uv) { d[v] = du + uv; pq.push(ii(d[v], v)); }
		}
	}
}

void sol() {
	for (int i = 1; i <= n; ++i) d[i] = oo; 
	pq.push(ii(0, 1)); d[1] = 0;
	Dijkstra();
	for (int i = 1; i <= n; ++i) minDist[0][i] = d[i];

	for (int i = 1; i <= n; ++i) d[i] = oo; 
	pq.push(ii(0, n)); d[n] = 0;
	Dijkstra();
	for (int i = 1; i <= n; ++i) minDist[1][i] = d[i];

	for (int i = 1; i <= n; ++i) {
		d[i] = c[i];
		pq.push(ii(d[i], i));
		adj[i].clear();
	}
	for (data edge : Edge) {
		int u = edge.u, v = edge.v, w = edge.w, l = edge.l;
		adj[u].push_back(ii(w+l, v));
		adj[v].push_back(ii(w+l, u));
	}
	Dijkstra();
	for (int i = 1; i <= n; ++i) cost[i] = d[i];

	int res = oo;
	for (int i = 1; i <= n; ++i) res = min( res, minDist[0][i] + minDist[1][i] + cost[i] );
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> c[i];

	int u, v, w, l;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w >> l;
		Edge.push_back(data(u, v, w, l));
		adj[u].push_back(ii(w, v));
		adj[v].push_back(ii(w, u));
	}

	sol();

	return 0;
}