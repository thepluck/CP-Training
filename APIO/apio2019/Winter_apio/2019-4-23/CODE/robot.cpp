#include<bits/stdc++.h>
#define int 					long long
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}

const int N = 1e5 + 4, oo = 1e17;
int m, n, h[N], s[N];

int id(int i, int j) { return (i-1) * n + j; }

int r[4] = { 0, 0, -1, 1 }, c[4] = { -1, 1, 0, 0 };
int vis[N], res;

void DFS(int u, int v) {
	int best = 0;
	for (int dir = 0; dir < 4; ++dir) {
		int x = u + r[dir], y = v + c[dir];
		if (x < 1 || x > m || y < 1 || y > n || h[id(x, y)] <= h[id(u, v)]) continue;
		if (vis[id(x, y)] == -oo) DFS(x, y);
		best = max(best, vis[id(x, y)]);
	}
	vis[id(u, v)] = best + s[id(u, v)];
	res = max(res, vis[id(u, v)]);
}

void sol() {
	for (int i = 0; i < N; ++i) vis[i] = -oo;
	res = -oo;

	FOR(i, 1, m) FOR(j, 1, n) {
		if (vis[id(i, j)] != -oo) continue;
		DFS(i, j);
	}
	cout << res << '\n';
}	

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("robot.inp", "r")) {
		freopen("robot.inp", "r", stdin);
		freopen("robot.out", "w", stdout);
	}

	Read(m); Read(n);
	FOR(i, 1, m) FOR(j, 1, n) Read(h[id(i, j)]);
	FOR(i, 1, m) FOR(j, 1, n) Read(s[id(i, j)]);

	sol();

	return 0;
}