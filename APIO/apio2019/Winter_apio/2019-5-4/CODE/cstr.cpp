#include<bits/stdc++.h>
#define FOR(i, a, b)		for (int i = a; i <= (int) b; ++i)
using namespace std;

const int N = 204;
string A, B;

int n, m, dp[N][N];

void sol() {
	int n = A.length(), m = B.length(); 
	A = " " + A; B = " " + B;

	FOR(i, 1, n) FOR(j, 1, m) {
		if (A[i] == B[j]) dp[i][j] = dp[i-1][j-1] + 1;
		dp[i][j] = max( dp[i][j], max(dp[i-1][j], dp[i][j-1]) );
	}

	int len = dp[n][m];
	FOR(Time, 1, 10000) {
		if (len >= (m+1)/2) { 
			int Bonus = 0;
			while (len < (n+1)/2) { n = (n+1)/2; Bonus++; }
			cout << Time + Bonus << '\n';
			exit(0); 
		}
		if ( n <= (m+1)/2-len ) {
			len += n; n *= 2;
		}
		else {
			len = (m+1)/2; n = (n+1)/2 + (m+1)/2 - len;
			
		}
	}
	assert(1 == 0);
	cout << -1 << '\n';
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("cstr.inp", "r")) {
		freopen("cstr.inp", "r", stdin);
		freopen("cstr.out", "w", stdout);
	}

	cin >> A >> B;

	sol();

	return 0;
}