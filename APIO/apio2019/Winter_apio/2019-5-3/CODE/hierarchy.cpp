#include<bits/stdc++.h>
#define int 					long long
#define BIG 					vector<int>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
#define REP(i, a, b) 			for (int i = a; i <  (int) b; ++i)
using namespace std;

const int BASE = 1e5;

void fix(BIG &a) {
	a.push_back(0);
	for (int i = 0; i < (int) a.size()-1; ++i) {
		a[i+1] += a[i] / BASE; a[i] %= BASE;
		if (a[i] < 0) { a[i] += BASE; a[i+1]--; }
	}
	while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

BIG to_BIG(int x) { 
	BIG tmp = BIG(1, x);
	fix(tmp);
	return tmp; 
}

void operator += (BIG &a, BIG &b) {
	a.resize(max(a.size(), b.size()));
	for (int i = 0; i < (int) a.size(); ++i) a[i] += b[i];
	fix(a);
}
BIG operator + (BIG a, BIG b) { a += b; return a; }

BIG operator * (const BIG a, const BIG b) {
	BIG c; c.resize(a.size() + b.size());
	REP(i, 0, a.size()) REP(j, 0, b.size()) 
		c[i+j] += a[i] * b[j];
	fix(c);
	return c;
}

bool operator < (const BIG &a, const BIG &b){
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = (int) a.size()-1; i >= 0; i--)
    if (a[i] != b[i]) return a[i] < b[i];
    return false;
}

void Print(BIG a) {
	cout << a.back();
	for (int i = (int) a.size()-2; i >= 0; --i) cout << setfill('0') << setw(5) << a[i];
	cout << '\n'; 
}

const int N = 154;
int n;

BIG C[N][N], dp[N][N], S[N][N][N];

void sol() {
	FOR(i, 0, n) FOR(j, 0, i) C[i][j] = (i == j || j == 0) ? to_BIG(1) : C[i-1][j] + C[i-1][j-1];

	FOR(i, 0, n) {
		dp[0][i] = S[0][0][i] = to_BIG(1);
		dp[1][i] = S[1][1][i] = to_BIG(1);
	}

	FOR(u, 2, n) {
		FOR(c, 1, n) FOR(v, 1, n) {
			if (v == 1) dp[u][c] += dp[u][c-1];
			if (u-1-v >= 0) {
				BIG cc = dp[v][c] * C[u-2][v-1];
				cc = cc * S[u-v-1][c-1][c];
				dp[u][c] += cc; //dp[v][c] * C[u-2][v-1] * S[u-v-1][c-1][c];
			}
		}
		FOR(seg, 1, n) FOR(c, 1, n) FOR(v, 1, n) 
			if (u >= v) {
				BIG cc = S[u-v][seg-1][c] * dp[v][c];
				cc = cc * C[u-1][v-1];
				S[u][seg][c] += cc; //S[u-v][seg-1][c] * dp[v][c] * C[u-1][v-1];
			}
	}

	// cout << dp[n][n] << '\n';
	Print(dp[n][n]);
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