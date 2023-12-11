#include<bits/stdc++.h>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
#define FOD(i, a, b)			for (int i = a; i >= (int) b; --i)
using namespace std;

const int N = 304, MOD = 1e9 + 7;
int n;

void Add(int &a, int b) { 
	a %= MOD; b %= MOD;
	a = (a + b) % MOD; 
}

int dp[N][N][N];

void sol() {
	FOR(l, 1, n) FOR(r, l+1, n) dp[1][l][r] = 1;
	FOR(i, 1, n) {
		FOR(l, 1, n) {
			int sum = 0;
			FOR(r, l+1, n) Add(dp[i+1][l][r], sum), Add(sum, dp[i][l][r]);
		}
		FOR(r, 1, n) {
			int sum = 0;
			FOD(l, r-1, 1) Add(dp[i+1][l][r], sum), Add(sum, dp[i][l][r]);
		}

		FOR(l, 0, n) FOR(r, 0, n) {
			if (dp[i][l][r] == 0) continue;

			if (l == 0 && r == 0) Add(dp[i+1][0][0], 2*dp[i][l][r]);
			else if (l != 0 && r != 0) {
				if (l == 1 && r-2 > i-1) Add(dp[i+1][0][r], dp[i][l][r]);
				if (r == n && n-l-1 > i-1) Add(dp[i+1][l][0], dp[i][l][r]);
			}
			else if (l == 0) {
				FOR(nR, r+1, n) Add(dp[i+1][l][nR], dp[i][l][r]);
				if (r == n && r-2 > i-1) Add(dp[i+1][0][0], dp[i][l][r]);

				if (r-2 > i-1) Add(dp[i+1][0][r], dp[i][l][r]);
			}
			else if (r == 0) {
				FOD(nL, l-1, 1) Add(dp[i+1][nL][r], dp[i][l][r]);
				if (l == 1 && n-l-1 > i-1) Add(dp[i+1][0][0], dp[i][l][r]);

				if (n-l-1 > i-1) Add(dp[i+1][l][0], dp[i][l][r]);
			}
			else assert(1 == 0);
		}
	}

	int res = 0;
	FOR(l, 0, n) FOR(r, 0, n) Add(res, dp[n-1][l][r]);
	cout << res << '\n';
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("polymino.inp", "r")) {
		freopen("polymino.inp", "r", stdin);
		freopen("polymino.out", "w", stdout);
	}

	cin >> n;

	sol();

	return 0;
}