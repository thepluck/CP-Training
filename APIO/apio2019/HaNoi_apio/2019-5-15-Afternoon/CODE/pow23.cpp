#include<bits/stdc++.h>
#define int 				long long
#define FOR(i, a, b)		for (int i = a; i <= (int) b; ++i)
#define FOD(i, a, b)		for (int i = a; i >= (int) b; --i)
using namespace std;

typedef pair<int, int> ii;

const int SZ = 72, upper_limit = 1e18;
int n, TTest;
vector<ii> ques;

int Pow2[SZ], Pow3[SZ];
int dp[SZ][SZ][SZ], ans[1004], best[1004]; 

bool make_product(int lg2, int lg3) {
	if ( lg2 < 0 || lg3 < 0 ) return false;
	if ( Pow2[lg2] == -1 || Pow3[lg3] == -1 ) return false;
	if ( (long double) Pow2[lg2] > (long double) upper_limit / Pow3[lg3] ) return false;
	return true;
}

void minimize(int &a, int b) { a = (a == -1) ? b : min(a, b); }

void update_ans(int sum, int len) {
	int pos = lower_bound(ques.begin(), ques.end(), ii(sum, -1)) - ques.begin();
	best[pos] = max(best[pos], len);
}

void sol() {
	Pow2[0] = Pow3[0] = 1;
	FOR(i, 1, 66) {
		if ( (long double) Pow2[i-1] > (long double) upper_limit / 2 || Pow2[i-1] == -1 ) Pow2[i] = -1;
		else Pow2[i] = Pow2[i-1] * 2; 
		if ( (long double) Pow3[i-1] > (long double) upper_limit / 3 || Pow3[i-1] == -1 ) Pow3[i] = -1;
		else Pow3[i] = Pow3[i-1] * 3;
	}

	memset(dp, -1, sizeof(dp));
	FOR(lg2, 0, 64) FOR(lg3, 0, 64) {
		if ( !make_product(lg2, lg3) ) continue;
		dp[1][lg2][lg3] = Pow2[lg2] * Pow3[lg3];
	}

	FOR(len, 1, 65) FOR(lg2, 0, 64) FOD(lg3, 64, 0) {
		if ( dp[len][lg2][lg3] == -1 ) continue;
		update_ans( dp[len][lg2][lg3], len );

		if ( lg3 < 0 ) continue;
		minimize( dp[len][lg2+1][lg3-1], dp[len][lg2][lg3] );
		
		if ( !make_product(lg2+1, lg3-1) ) continue;
		int nVal = Pow2[lg2+1] * Pow3[lg3-1];
		if ( dp[len][lg2][lg3] <= upper_limit - nVal ) minimize( dp[len+1][lg2+1][lg3-1], dp[len][lg2][lg3] + nVal );
	}

	FOR(i, 0, TTest-1) {
		if (i > 0) best[i] = max(best[i], best[i-1]);
		ans[ques[i].second] = best[i];
	}
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	cin >> TTest;
	FOR(Time, 1, TTest) { cin >> n; ques.push_back( ii(n, Time) ); }
	sort(ques.begin(), ques.end());

	sol();

	FOR(Time, 1, TTest) cout << ans[Time] << '\n';

	return 0;
}