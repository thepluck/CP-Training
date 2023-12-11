#include<bits/stdc++.h>
using namespace std;

const int N = 2e7 + 4, MOD = 1e9 + 7;
int n;
string S;

int Convert(char c) {
	return ('a' <= c && c <= 'z') ? (c-'a') : (c-'0' + 26);
}

int Pow[N], Hash[N];

int getHash(int l, int r) { 
	long long res = ( Hash[r] - 1LL * Hash[l-1] * Pow[r-l+1] % MOD + MOD ) % MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("period.inp", "r")) {
		freopen("period.inp", "r", stdin);
		freopen("period.out", "w", stdout);
	}

	cin >> S;
	n = S.length(); S = " " + S;

	Pow[0] = 1;
	for (int i = 1; i <= n; ++i) {
		Pow[i] = ( 1LL * Pow[i-1] * 31 ) % MOD;
		Hash[i] = ( 1LL * Hash[i-1] * 31 % MOD + Convert(S[i]) ) % MOD;
	}

	for (int i = 1; i <= n; ++i) {
		if ( n % i != 0 ) continue;

		int tmp1 = getHash(1, n-i);
		int tmp2 = getHash(i+1, n);

		if (tmp1 == tmp2) { cout << i << '\n'; exit(0); }
	}

	return 0;
}