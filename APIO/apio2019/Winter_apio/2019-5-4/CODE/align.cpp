#include<bits/stdc++.h>
#define int 					long long
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
using namespace std;

const int N = 1010;
int n, a[N];

int sum[N], dp[N][N];

void minimize(int &a, int b) { a = (a == -1) ? b : min(a, b); }

void sol() {
	FOR(i, 1, n) sum[i] = sum[i-1] + a[i];
	int atLeast = sum[n] / n, remain = sum[n] % n;

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;

	FOR(i, 0, n) FOR(j, 0, n) {
		if (dp[i][j] == -1) continue;

		int block = (i-j) * atLeast + j * (atLeast+1);
		int cost = abs(sum[i] - block);
		
		/// a[i+1] == atLeast
		minimize( dp[i+1][j], dp[i][j] + cost ); 

		/// a[i+1] != atLeast 
		minimize( dp[i+1][j+1], dp[i][j] + cost ); 
	}
	cout << dp[n][remain] << '\n';
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("align.inp", "r")) {
		freopen("align.inp", "r", stdin);
		freopen("align.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	sol();

	return 0;
}