#include<bits/stdc++.h>
#define int 				long long
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

typedef pair<int, int> ii;
struct dataPath {
	int u, v, w;
	dataPath() {}; dataPath(int u, int v, int w) : u(u), v(v), w(w) {};
	bool operator < (const dataPath &a) const { return w > a.w; }
};

const int N = 2e5 + 4, LOG = 20, oo = 1e12 + 7, MOD = 1e9 + 21;
int n, Q;
vector<int> adj[N];
vector<dataPath> path;

void Add(int &a, int b) { a = (a + b) % MOD; if (a < 0) a += MOD; }

int hei[N], numChild[N], par[N][LOG+4];

void DFS(int dad, int u) {
	hei[u] = hei[dad] + 1; par[u][0] = dad;
	numChild[u] = 1 ;
	for (int v : adj[u]) if (v != dad) {
		DFS(u, v);
		numChild[u] += numChild[v];
	}
}

void Build_LCA() {
	for (int j = 1; j <= LOG; ++j) for (int i = 1; i <= n; ++i)
		par[i][j] = par[par[i][j-1]][j-1];
}
int LCA(int u, int v) {
	if (hei[u] < hei[v]) swap(u, v);
	for (int i = LOG; i >= 0; --i) 
		if (hei[u] - (1<<i) >= hei[v]) u = par[u][i];
	if (u == v) return u;
	for (int i = LOG; i >= 0; --i) 
		if (par[u][i] != 0 && par[v][i] != 0 && par[u][i] != par[v][i]) {
			u = par[u][i]; v = par[v][i];
		}
	return par[u][0];
}
int getDist(int u, int v) {
	int dad = LCA(u, v);
	return hei[u] + hei[v] - 2*hei[dad];
}

int belong[N], headChain[N], pos[N], numChain, numArr;

void HLD(int dad, int u) {
	if (!headChain[numChain]) headChain[numChain] = u; 
	belong[u] = numChain; pos[u] = ++numArr;

	int big = -1;
	for (int v : adj[u]) if (v != dad) 
		big = (big == -1 || numChild[v] > numChild[big]) ? v : big;

	if (big != -1) HLD(u, big);

	for (int v : adj[u]) if (v != dad && v != big) {
		++numChain; HLD(u, v);
	}
}

struct Interval_Tree {
	int minNode[4*N], maxNode[4*N], lazy[4*N];

	void Down(int i) {
		Add(minNode[2*i], lazy[i]);
		Add(maxNode[2*i], lazy[i]);

		Add(minNode[2*i+1], lazy[i]);
		Add(maxNode[2*i+1], lazy[i]);

		Add(lazy[2*i], lazy[i]);
		Add(lazy[2*i+1], lazy[i]);
		lazy[i] = 0;
 	}

	void update(int i, int l, int r, int x, int y, int val) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) { 
			Add(minNode[i], val);
			Add(maxNode[i], val);
			Add(lazy[i], val);
			return; 
		}
		Down(i);
		int mid = (l + r) / 2;
		update(2*i, l, mid, x, y, val);
		update(2*i+1, mid+1, r, x, y, val);
		minNode[i] = min(minNode[2*i], minNode[2*i+1]);
		maxNode[i] = max(maxNode[2*i], maxNode[2*i+1]);
	}

	ii get(int i, int l, int r, int x, int y) {
		if (l > y || x > r) return ii(oo, -oo);
		if (x <= l && r <= y) return ii(minNode[i], maxNode[i]);
		Down(i);
		int mid = (l + r) / 2;
		ii tmp1 = get(2*i, l, mid, x, y), tmp2 = get(2*i+1, mid+1, r, x, y);
		return ii( min(tmp1.first, tmp2.first), max(tmp1.second, tmp2.second) );
	}	
} IT;

ii get_HLD(int u, int dad) {
	long long minVal = oo, maxVal = -oo;
	while (true) {
		if (belong[u] != belong[dad]) {
			int anc = headChain[belong[u]];
			ii foo = IT.get(1, 1, n, pos[anc], pos[u]);
			minVal = min(minVal, foo.first); maxVal = max(maxVal, foo.second);
			u = par[anc][0];
		}
		else {
			ii foo = IT.get(1, 1, n, pos[dad], pos[u]);
			minVal = min(minVal, foo.first); maxVal = max(maxVal, foo.second);
			break;
		}
	}
	return ii(minVal, maxVal);
}

void update_HLD(int u, int dad, int val) {
	while (true) {
		if (belong[u] != belong[dad]) {
			int anc = headChain[belong[u]];
			IT.update(1, 1, n, pos[anc], pos[u], val);
			u = par[anc][0];
		}
		else {
			IT.update(1, 1, n, pos[dad], pos[u], val);
			break;
		}
	}
}

void process() {
	int code = 0;
	for (int i = 0; i < Q; ++i) {
		int u = path[i].u, v = path[i].v, dad = LCA(u, v);

		ii ore_u = get_HLD(u, dad);
		ii ore_v = get_HLD(v, dad);

		if (ore_u.first != ore_v.first) { cout << "No \n"; exit(0); }
		if (ore_u.second != ore_v.second) { cout << "No \n"; exit(0); }
		if (ore_u.first != ore_u.second) { cout << "No \n"; exit(0); }

		code = (code * N + i+1) % MOD;
		update_HLD(u, dad, code);
		update_HLD(v, dad, code);
		update_HLD(dad, dad, -code);
	}
	cout << "Yes \n";
}

void sol() {
	DFS(0, 1);	
	Build_LCA();

	++numChain; HLD(0, 1);

	int u, v;
	for (int i = 0; i < Q; ++i) {
		Read(u); Read(v);
		path.push_back(dataPath(u, v, getDist(u, v)));
	}
	sort(path.begin(), path.end());

	process();
}

#undef int
int main() {
#define int 				long long
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
	}

	Read(n); Read(Q);
	int u, v;
	for (int i = 1; i < n; ++i) {
		Read(u); Read(v);
		adj[u].push_back(v); adj[v].push_back(u);
	}

	sol();

	return 0;
}