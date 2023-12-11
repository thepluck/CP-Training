#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k, a[N];
vector <int> g[N];

pair <int, int> dfs(int u, int p) {
	pair <int, int> res(0, a[u]);
	vector <int> rem;
	for (int v : g[u]) {
		if (v == p) continue;
		pair <int, int> tmp = dfs(v, u);
		res.first += tmp.first;
		rem.push_back(tmp.second);
	}
	sort(rem.begin(), rem.end());
	for (int w : rem)
		if (res.second + w <= k)
			res.second += w;
		else res.first++;
	return res;
}

void input() {
	cin >> n >> k;
	for_each(a + 1, a + n + 1,
	[](int &x) {cin >> x;});
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void output() {
	cout << dfs(1, 0).first << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input(); output();
}