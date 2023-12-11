#include<bits/stdc++.h>
#define lim_u 		ore_u
#define lim_v		ore_v
using namespace std;

void Read(int &val) {	
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 2e5 + 4, LOG = 20;
int n, Q;
vector<int> adj[N];

int hei[N], par[N][LOG+3], L[N], R[N], numET;

void Build_ET(int dad, int u) {
	hei[u] = hei[dad] + 1; par[u][0] = dad;
	
	L[u] = ++numET; 
	for (int v : adj[u]) if (v != dad) Build_ET(u, v);
	R[u] = numET;
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

struct Interval_Tree {
	int node[4*N], lazy[4*N];

	Interval_Tree() {
		for (int i = 0; i < 4*N; ++i) node[i] = 1, lazy[i] = -1;
	}

	void Down(int i) {
		node[2*i] = max(node[2*i], lazy[i]); node[2*i+1] = max(node[2*i+1], lazy[i]);
		lazy[2*i] = max(lazy[2*i], lazy[i]); lazy[2*i+1] = max(lazy[2*i+1], lazy[i]);
		lazy[i] = -1;
	}

	void update(int i, int l, int r, int x, int y, int val) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) {
			node[i] = max(node[i], val); lazy[i] = max(lazy[i], val);
			return;
		}
		Down(i);
		int mid = (l + r) / 2;
		update(2*i, l, mid, x, y, val);
		update(2*i+1, mid+1, r, x, y, val);
		node[i] = max(node[2*i], node[2*i+1]); 
	}

	int get(int i, int l, int r, int x, int y) {
		if (l > y || x > r) return -1;
		if (x <= l && r <= y) return node[i];
		Down(i);
		int mid = (l + r) / 2;
		int tmp1 = get(2*i, l, mid, x, y), tmp2 = get(2*i+1, mid+1, r, x, y);
		return max(tmp1, tmp2);
	}
} IT;
	
void sol() {
	Build_ET(0, 1);
	Build_LCA();

	int u, v, type;
	while (Q--) {
		Read(u); Read(v); Read(type);
		if (type == 0) {
			int dad = LCA(u, v);
			int lim_u = IT.get(1, 1, n, L[u], L[u]), lim_v = IT.get(1, 1, n, L[v], L[v]);

			if (lim_u > hei[dad] || lim_v > hei[dad]) puts("NO"); 
			else puts("YES");
		} 
		else {
			int dad = LCA(u, v);
			int lim_u = IT.get(1, 1, n, L[u], L[u]), lim_v = IT.get(1, 1, n, L[v], L[v]);

			if (lim_u > hei[dad] || lim_v > hei[dad]) {
				IT.update(1, 1, n, L[v], R[v], hei[v]);
				puts("NO"); 
			}
			else {
				IT.update(1, 1, n, L[u], R[u], hei[u]);
				puts("YES");
			}
		}
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("treepath.inp", "r")) {
		freopen("treepath.inp", "r", stdin);
		freopen("treepath.out", "w", stdout);
	}

	Read(n); Read(Q);
	for (int v = 2; v <= n; ++v) {
		int u; Read(u); 
		adj[u].push_back(v); adj[v].push_back(u);
	}

	sol();

	return 0;
}