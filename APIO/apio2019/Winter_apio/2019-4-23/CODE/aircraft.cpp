#include<bits/stdc++.h>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
using namespace std;

const int N = 54;
int m, n;
long double p, a[N];

long double cost[N], dp[N][N];
int Trace[N][N], ans[N];

void sol() {
	FOR(i, 0, m) cost[i] = (i == 0) ? (long double) 1 : (1-p) * cost[i-1];  

	dp[0][0] = (long double) 0;
	FOR(i, 1, n) FOR(j, 0, m) {
		FOR(use_i, 0, j) {
			long double val = (1 - cost[use_i]) * a[i];
			if (dp[i][j] < val + dp[i-1][j-use_i]) {
				dp[i][j] = val + dp[i-1][j-use_i];
				Trace[i][j] = use_i;
			}
		}
	}

	int u = n, num = m;
	while (u > 0) {
		int use_u = Trace[u][num];
		ans[u] = use_u;
		--u; num -= use_u;
	}

	for (int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("aircraft.inp", "r")) {
		freopen("aircraft.inp", "r", stdin);
		freopen("aircraft.out", "w", stdout);
	}

	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	sol();

	return 0;
}