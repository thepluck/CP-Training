#include<bits/stdc++.h>
#define REP(i, a, b)		for (int i = a; i <  (int) b; ++i)
#define FOR(i, a, b)		for (int i = a; i <= (int) b; ++i)
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

const int N = 3e4 + 4, MASK = 2050;
int n, a[N][12];

bool BIT(int n, int k) { return n & (1<<k); }
void maximize(long long &a, long long b) { a = max(a, b); } 

int First_bit[N];
long long cost[MASK], dp[3][MASK];

void sol() {
	REP(mask, 1, (1<<11)) REP(bit, 0, 11) 
		if (BIT(mask, bit)) { First_bit[mask] = bit; break; }

	FOR(i, 1, n) {
		REP(mask, 1, (1<<11)) {
			int bit = First_bit[mask], fake = mask - (1<<bit);
			cost[mask] = cost[fake] + a[i][bit];
			maximize(dp[1][mask], cost[mask]);
		}
	}

	REP(mask1, 0, (1<<11)) REP(mask2, 0, (1<<11)) {
		if ( (mask1 & mask2) != 0 ) continue;
		maximize(dp[2][mask1|mask2], dp[1][mask1] + dp[1][mask2]);
	}

	long long res = 0;
	REP(mask1, 0, (1<<11)) REP(mask2, 0, (1<<11)) {
		if ( (mask1 & mask2) != 0 ) continue;
		maximize(res, dp[2][mask2] + dp[1][mask1]);
	}
	cout << res << '\n';
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("acm.inp", "r")) {
		freopen("acm.inp", "r", stdin);
		freopen("acm.out", "w", stdout);
	}

	Read(n);
	FOR(i, 1, n) REP(bit, 0, 11) Read(a[i][bit]);

	sol();

	return 0;
}