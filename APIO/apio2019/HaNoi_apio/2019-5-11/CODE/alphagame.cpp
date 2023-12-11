#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 4;
int TTest;
string S;

int dp[N][28], Count[28];

int calc(int pair, int remain) {
	int &foo = dp[pair][remain];
	if (foo != -1) return foo; foo = 0;
	if (pair == 0) return foo = 0; 

	if (remain > 0) foo |= ( 1 - calc(pair, remain-1) );
	if (remain < 26) foo |= ( 1 - calc(pair-1, remain+1) );

	return foo;
}

void sol() {
	for (int c = 0; c < 26; ++c) Count[c] = 0;
	for (int i = 0; i < (int) S.length(); ++i) Count[S[i]-'a']++;

	int ore_pair = 0, ore_remain = 0;
	for (int c = 0; c < 26; ++c) {
		ore_pair += Count[c] / 2; ore_remain += (Count[c] % 2);
	}

	memset(dp, -1, sizeof(dp));
	for (int remain = 0; remain < 26; ++remain) dp[0][remain] = 0;
	for (int pair = 0; pair < N-2; ++pair) for (int remain = 0; remain < 26; ++remain) {
		if (dp[pair][remain] == -1) continue;

		if (pair > 0) { 
			if (dp[pair][remain+1] == -1) dp[pair][remain+1] = 0;
			dp[pair][remain+1] |= (1 - dp[pair][remain]);
		}

		if (remain >= 1) {
			if (dp[pair+1][remain-1] == -1) dp[pair+1][remain-1] = 0;
			dp[pair+1][remain-1] |= (1 - dp[pair][remain]);
		}
	}

	if (dp[ore_pair][ore_remain] == 1) cout << "G"; else cout << "D";
}	 

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("alphagame.inp", "r")) {
		freopen("alphagame.inp", "r", stdin);
		freopen("alphagame.out", "w", stdout);
	}

	cin >> TTest;
	while (TTest--) {
		cin >> S;
		sol();
	}

	return 0;
}