#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}
void Write(int val) {
	if (val < 0) putchar('-'), Write(-val);
	else if (val < 10) putchar('0' + val);
	else Write(val/10), putchar('0' + val%10);
}

typedef pair<int, int> ii;

const int N = 1e5 + 4;
int n, m;
vector<ii> Edge;

queue<int> Q;
vector<int> adj[N];
int deg[N], vis[N], Time;

void process(int l, int r, int k) {
	for (int i = l; i <= r; ++i) adj[i].clear(), deg[i] = 0;
	for (int i = 0; i < m; ++i) {
		int u = Edge[i].first, v = Edge[i].second;
		if (u > r || u < l) continue;
		if (v > r || v < l) continue;
		adj[u].push_back(v); adj[v].push_back(u);
		deg[u]++; deg[v]++;
	}

	++Time;
	for (int u = l; u <= r; ++u) if (deg[u] < k) Q.push(u), vis[u] = Time; 
	
	int res = r-l+1;
	while (Q.size()) {
		int u = Q.front(); Q.pop();
		res--;
		for (int v : adj[u]) {
			deg[v]--;
			if (deg[v] < k && vis[v] != Time) Q.push(v), vis[v] = Time; 
		}
	}
	Write(res); putchar('\n');
}	

void sol() {
	int T, l, r, k;

	Read(T);
	while (T--) {
		Read(l); Read(r); Read(k);
		process(l, r, k);
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("group.inp", "r")) {
		freopen("group.inp", "r", stdin);
		freopen("group.out", "w", stdout);
	}

	Read(n); Read(m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		Read(u); Read(v);
		Edge.push_back(ii(u, v));
	}

	sol();

	return 0;
}