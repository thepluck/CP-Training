#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

typedef pair<int, int> ii; 
struct data {
	int u, type, val, root;
	data() {}; data(int u, int type, int val, int root) : u(u), type(type), val(val), root(root) {};
	bool operator > (const data &a) const {
		return val > a.val || (val == a.val && root > a.root);
	}
};

const int N = 1e5 + 4, oo = 1e9 + 7;
int n, m, k, p[N];
vector<ii> adj[N];

int d[N][2], Trace[N][2];
priority_queue<data, vector<data>, greater<data> > pq;

void update(int v, int val, int root) {
	if ( d[v][0] > val || (d[v][0] == val && root < Trace[v][0]) ) {
		if (Trace[v][0] != root) { 
			d[v][1] = d[v][0]; Trace[v][1] = Trace[v][0]; 
			pq.push( data(v, 1, d[v][1], Trace[v][1]) ); 
		}
		d[v][0] = val; Trace[v][0] = root;
		pq.push( data(v, 0, d[v][0], Trace[v][0]) );
	}
	if ( d[v][1] > val || (d[v][1] == val && root < Trace[v][1]) ) {
		if (root == Trace[v][0]) return;
		d[v][1] = val; Trace[v][1] = root;
		pq.push( data(v, 1, d[v][1], Trace[v][1]) );
	}
}

void Dijkstra() {
	for (int u = 1; u <= n; ++u) d[u][0] = d[u][1] = Trace[u][0] = Trace[u][1] = oo;
	for (int i = 1; i <= k; ++i) {
		int u = p[i];
		update(u, 0, i);
	}

	while (pq.size()) {
		int u = pq.top().u, type = pq.top().type, val = pq.top().val, root = pq.top().root; pq.pop();
		if (d[u][type] != val || Trace[u][type] != root) continue;

		for (ii foo : adj[u]) {
			int v = foo.second, cost = foo.first;
			update(v, val+cost, root);
		}
	}

	for (int i = 1; i <= k; ++i) {
		int u = p[i];
		if (Trace[u][0] != i) cout << Trace[u][0] << " ";
		else cout << Trace[u][1] << " "; 
	}
	cout << '\n';
}

void sol() {
	Dijkstra();
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) cin >> p[i];
	
	int u, v, w;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back(ii(w, v));
		adj[v].push_back(ii(w, u));
	}

	sol();

	return 0;
}