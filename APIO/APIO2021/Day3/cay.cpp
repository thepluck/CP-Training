#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e6 + 5;

int cnt[MAXN], N;
vector <int> adj[MAXN];


int DFS(int u) {
	int siz = 1;
	for (int v : adj[u]) {
		int sub = DFS(v);
		cnt[__gcd(sub, N - sub)]++;
		siz += sub;
	}
	return siz;
}

int main() {
	freopen("cay.inp", "r", stdin);
	freopen("cay.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	DFS(1);
	for (int k = 1; k <= N; k++) {
		if (N % k) continue;
		int edge = 0;
		for (int t = N / k; t <= N; t += N / k)
			edge += cnt[t];
		if (edge == k - 1) cout << k << ' ';
	}
}
