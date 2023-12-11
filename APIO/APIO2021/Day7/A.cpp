#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;
const int SQ = 300;

int par[MAXN], dep[MAXN], jump[MAXN];


int LCA(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	while (dep[jump[u]] >= dep[v])
		u = jump[u];
	while (dep[par[u]] >= dep[v])
		u = par[u];
	while (jump[u] != jump[v]) {
		u = jump[u]; v = jump[v];
	}
	while (u != v) {
		u = par[u]; v = par[v];
	}
	return u;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	dep[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> par[i];
		dep[i] = dep[par[i]] + 1;
		jump[i] = i;
		for (int j = 0; j < SQ; j++)
			jump[i] = par[jump[i]];
	}
	while (Q--) {
		int u, v; cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
}