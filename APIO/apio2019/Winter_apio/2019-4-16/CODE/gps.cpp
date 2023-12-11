#include<bits/stdc++.h>
#define FOR(i, a, b)		for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b)		for (int i = a; i <  (int) b; ++i)
using namespace std;

const int N = 504, oo = 1e9 + 7;
int T, Time, m, n;
string A, B;

int dp[N][N][2][2], vis[N][N][2][2];

bool BIT(int n, int k) { return n & (1<<k); }

void update(int i, int j, int bitA, int bitB, int val) {
	if (vis[i][j][bitA][bitB] != Time) dp[i][j][bitA][bitB] = val, vis[i][j][bitA][bitB] = Time;
	else dp[i][j][bitA][bitB] = max(dp[i][j][bitA][bitB], val);
}

void sol() {
	dp[0][0][1][1] = 0; vis[0][0][1][1] = Time;

	FOR(i, 0, n) FOR(j, 0, m) FOR(mask, 1, 3) {
		int bitA = BIT(mask, 0), bitB = BIT(mask, 1), val = dp[i][j][bitA][bitB];
		if (vis[i][j][bitA][bitB] != Time) continue; 

		FOR(nMask, 1, 3) {
			int nA = BIT(nMask, 0), nB = BIT(nMask, 1);
			if (nA == 1 && nB == 1) {
				int cost = (A[i+1] == B[j+1]) ? 2 : -1;
				update(i+1, j+1, 1, 1, val+cost);
			}
			else {
				int cost = 0;
				if (nA == 0 && bitA == 1) cost -= 5;
				if (nA == 0 && bitA == 0) cost --;
				if (nB == 0 && bitB == 1) cost -= 5;
				if (nB == 0 && bitB == 0) cost --;

				int nI = (nA == 1) ? i+1 : i, nJ = (nB == 1) ? j+1 : j;
				update(nI, nJ, nA, nB, val + cost);
			}
		}
	}

	int res = -oo;
	FOR(mask, 1, 3) {
		int bitA = BIT(mask, 0), bitB = BIT(mask, 1);
		res = max( res, dp[n][m][bitA][bitB] );
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("gps.inp", "r")) {
		freopen("gps.inp", "r", stdin);
		freopen("gps.out", "w", stdout);
	}

	cin >> T;
	for (Time = 1; Time <= T; ++Time) {
		cin >> A >> B;
		n = A.length(); m = B.length(); 
		A = " " + A; B = " " + B;

		sol();
	}

 	return 0;
}