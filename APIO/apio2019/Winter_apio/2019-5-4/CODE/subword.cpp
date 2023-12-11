#include<bits/stdc++.h>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
using namespace std;

typedef pair<int, int> ii;

const int N = 2004, oo = 1e8 + 4;
int m, n;
string X, S, orgX, orgS;

bool canErase(char a, char b) {
	if (a == 'a' && b == 'A') return true;
	if (a == 'A' && b == 'a') return true;
	if (a == 'b' && b == 'B') return true;
	if (a == 'B' && b == 'b') return true;
	return false;
}

void compress(string &A) {
	while (true) {
		bool isEnd = true;
		for (int i = 0; i < (int) A.length()-1; ++i) 
			if (canErase(A[i], A[i+1])) { A.erase(i, 2); isEnd = false; break; }
		if (isEnd) break;
	}
}

string AddL, AddR;
int dp[N][N];

void sol() {
	compress(X); compress(S);
	n = (int) X.length(); m = (int) S.length();
	X = " " + X; S = " " + S;

	ii point = ii(0, 0); int maxLen = 0;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		if (X[i] == S[j]) dp[i][j] = dp[i-1][j-1] + 1;
		else dp[i][j] = 0; 

		if (dp[i][j] > maxLen) { maxLen = dp[i][j]; point = ii(i, j); }
	}
	// assert( point != ii(-1, -1) );

	int l = point.second - maxLen + 1, r = point.second;
	for (int i = l-1; i >= 1; --i) {
		if (S[i] == 'a') AddL += "A";	
		if (S[i] == 'A') AddL += "a";
		if (S[i] == 'b') AddL += "B";
		if (S[i] == 'B') AddL += "b";
	}
	for (int i = m; i > r; --i) {
		if (S[i] == 'a') AddR += "A";
		if (S[i] == 'A') AddR += "a";
		if (S[i] == 'b') AddR += "B";
		if (S[i] == 'B') AddR += "b";	
	}

	/// Print();
	l = point.first - maxLen + 1; r = point.first;
	for (int i = 1; i < l; ++i) cout << X[i];
	cout << AddL;
	cout << orgS;
	cout << AddR;
	for (int i = r+1; i <= n; ++i) cout << X[i];

		string cc = "";
		for (int i = 1; i < l; ++i) cc += X[i];
		cc += AddL + orgS + AddR;
		for  (int i = r+1; i <= n; ++i) cc += X[i];
		compress(cc); cc = " " + cc;
		assert( cc == X );
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("subword.inp", "r")) {
		freopen("subword.inp", "r", stdin);
		freopen("subword.out", "w", stdout);
	}

	cin >> orgX >> orgS; X = orgX; S = orgS;

	sol();

	return 0;
}