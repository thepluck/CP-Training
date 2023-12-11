#include <bits/stdc++.h>
using namespace std;

int n, k;
typedef vector <int> vi;
vector <vi> g;
vi siz;

void dfs(int u, int par = 0){
	siz[u] = 1;
	for (auto v : g[u]) if (v != par)
		dfs(v, u), siz[u] += siz[v];
	if (siz[u] >= k) siz[0]++, siz[u] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> n;
	g.resize(n + 1); siz.resize(n + 1);
	for (int i = 2, p; i <= n; i++){
		cin >> p; g[p].push_back(i);
	}
	dfs(1); cout << siz[0];
	return 0;
}