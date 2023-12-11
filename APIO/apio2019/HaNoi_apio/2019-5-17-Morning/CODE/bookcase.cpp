#include<bits/stdc++.h>
#define FOR(i, a, b)		for (int i = a; i <= (int) b; ++i)
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

typedef pair<int, int> ii;

const int N = 74, S = 2104;
int T, n;
ii a[N];

int dp[2][S][S], sumT[N];

void minimize(int &a, int b) { a = (a == -1) ? b : min(a, b); }

void sol() {
	sort(a+1, a+n+1); reverse(a+1, a+n+1);
	FOR(i, 1, n) sumT[i] = sumT[i-1] + a[i].second;

	memset(dp, -1, sizeof(dp));
	dp[1][ sumT[1] ][ 0 ] = a[1].first;

	int type = 0, res = -1;
	FOR(i, 1, n) {
		type = 1 - type; int h = a[i+1].first, t = a[i+1].second;
		FOR(s1, 0, sumT[i+1]) FOR(s2, 0, sumT[i+1]-s1) dp[1-type][s1][s2] = -1;

		FOR(s1, 0, sumT[i]) FOR(s2, 0, sumT[i]-s1) {
			if (dp[type][s1][s2] == -1) continue; 
			int s3 = sumT[i] - s1 - s2;

			if (i == n && s1 != 0 && s2 != 0 && s3 != 0) {
				minimize( res, dp[type][s1][s2] * max({ s1, s2, s3 }) );
				continue;
			}

			/// Add to s1
			minimize( dp[1-type][s1+t][s2], dp[type][s1][s2] );

			/// Add to s2 
			int val2 = (s2 == 0) ? h : 0;
			minimize( dp[1-type][s1][s2+t], dp[type][s1][s2] + val2 );

			/// Add to s3
			int val3 = (s3 == 0) ? h : 0;
			if (s2 != 0) minimize( dp[1-type][s1][s2], dp[type][s1][s2] + val3 );
		}
	}
	cout << res << '\n';
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("bookcase.inp", "r")) {
		freopen("bookcase.inp", "r", stdin);
		freopen("bookcase.out", "w", stdout);
	}

	Read(T);
	while (T--) {
		Read(n);
		for (int i = 1; i <= n; ++i) Read(a[i].first), Read(a[i].second);

		sol();
	}

	return 0;	
}