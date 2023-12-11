#include<bits/stdc++.h>
#define int 					long long
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
using namespace std;

const int N = 154;
int n;

int C[N][N], dp[N][N], S[N][N][N];

void sol() {
	FOR(i, 0, n) FOR(j, 0, i) C[i][j] = (i == j || j == 0) ? 1 : C[i-1][j] + C[i-1][j-1];

	FOR(i, 0, n) {
		dp[0][i] = S[0][0][i] = 1;
		dp[1][i] = S[1][1][i] = 1;
	}

	FOR(u, 2, n) {
		FOR(c, 1, n) FOR(v, 1, n) {
			if (v == 1) dp[u][c] += dp[u][c-1];
			if (u-1-v >= 0) dp[u][c] += dp[v][c] * C[u-2][v-1] * S[u-v-1][c-1][c];
		}
		FOR(seg, 1, n) FOR(c, 1, n) FOR(v, 1, n) 
			if (u >= v) S[u][seg][c] += S[u-v][seg-1][c] * dp[v][c] * C[u-1][v-1];
	}

	cout << dp[n][n] << '\n';
}

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("hierarchy.inp", "r")) {
		freopen("hierarchy.inp", "r", stdin);
		freopen("hierarchy.out", "w", stdout);
	}

	cin >> n;

	sol();

	return 0;
}