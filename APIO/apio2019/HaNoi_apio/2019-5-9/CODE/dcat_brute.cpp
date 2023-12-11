#include<bits/stdc++.h>
using namespace std;

const int N = 1004;
int n, m;
vector<int> adj[N];

bool Disable[N], vis[N];

void DFS(int u) {
	vis[u] = true;
	for (int v : adj[u]) 
		if (!vis[v] && !Disable[v]) DFS(v);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("answer.txt", "w", stdout);

	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		Disable[i] = true;
		memset(vis, false, sizeof(vis));

		int res = 0; 
		for (int u = 1; u <= n; ++u) {
			if (vis[u] || Disable[u]) continue;
			DFS(u); res++;
		}
		cout << res << '\n';

		Disable[i] = false;
	}

	return 0;
}