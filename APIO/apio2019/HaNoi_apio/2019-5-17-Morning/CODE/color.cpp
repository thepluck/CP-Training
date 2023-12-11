#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 504, M = 1e4 + 4;
int n, m;
vector<int> adj[N];

vector<int> V;
int col[N], vis[N], ore[N], ok[N], Time; 

void DFS(int u, int ban, int ins) {
	if (col[u] != 0 && col[u] != ins) { cout << "NO \n"; exit(0); }
	col[u] = ins; ore[u] = Time;

	for (int v : adj[u]) if (ok[v] && ore[v] != Time) {
		int nIns = -1;
		if (ban == 1 && ins == 2) nIns = 3;
		if (ban == 1 && ins == 3) nIns = 2;

		if (ban == 2 && ins == 3) nIns = 1;
		if (ban == 2 && ins == 1) nIns = 3;
		
		if (ban == 3 && ins == 1) nIns = 2;
		if (ban == 3 && ins == 2) nIns = 1;

		assert(nIns != -1);
		DFS(v, ban, nIns);
	}
}

void sol() {
	V.push_back(1); col[1] = vis[1] = 1;

	while (V.size()) {
		int u = V.back(); V.pop_back();
		if (adj[u].empty()) continue;

		int Start = adj[u][0];
		for (int v : adj[u]) {
			ok[v] = true;
			if (col[v] != 0) Start = v; 
		}

		if (col[Start] == 0) {
			col[Start] = 1;
			if (col[Start] == col[u]) col[Start] = 2;
		} 
		else if (col[Start] == col[u]) { cout << "NO \n"; exit(0); }

		++Time;
		DFS(Start, col[u], col[Start]);

		for (int v : adj[u]) {
			if (!vis[v]) V.push_back(v);
			ok[v] = false; vis[v] = 1;
		}
	}
}

void Last_check() {
	for (int u = 1; u <= n; ++u) {
		for (int v : adj[u]) if (col[u] == col[v]) { cout << "NO \n"; exit(0); }
	}

	cout << "YES \n";
	for (int u = 1; u <= n; ++u) {
		if (col[u] == 1) cout << "R";
		else if (col[u] == 2) cout << "G";
		else cout << "B";
	}
	cout << '\n';
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("color.inp", "r")) {
		freopen("color.inp", "r", stdin);
		freopen("color.out", "w", stdout);
	}

	Read(n); Read(m);
	int u, v;
	for (int i = 1; i <= m; ++i) {
		Read(u); Read(v);
		adj[u].push_back(v); adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) if (!vis[i]) sol(); 
	Last_check();

	return 0;
}