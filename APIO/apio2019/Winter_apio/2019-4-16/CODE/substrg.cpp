#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

const int N = 2e5 + 4, bs = 137;
int n, m;
string A, B;

ULL Pow[N], HashA[N][200], HashB[200];

ULL get_Hash(int Time, int l, int r) {
	return HashA[r][Time] - HashA[l-1][Time] * Pow[r-l+1];
}

int ok[N], First_Pos[200];
bool visA[200], visB[200];
vector<char> lsCharA, lsCharB;

void sol() {
	for (int i = 1; i <= n; ++i) if (!visA[A[i]]) lsCharA.push_back(A[i]), visA[A[i]] = true;
	for (int i = 1; i <= m; ++i) if (!visB[B[i]]) lsCharB.push_back(B[i]), visB[B[i]] = true;

	for (int i = 1; i <= m; ++i) if (!First_Pos[B[i]]) First_Pos[B[i]] = i;
	for (int i = 0; i <= n; ++i) Pow[i] = (i == 0) ? 1 : Pow[i-1] * bs;

	for (char Char : lsCharB) {
		int Time = (int) Char;
		for (int i = 1; i <= m; ++i) HashB[Time] = HashB[Time] * bs + 1 + (int) (B[i] == Char);
	}

	for (char Char : lsCharA) {
		int Time = (int) Char;
		for (int i = 1; i <= n; ++i) HashA[i][Time] = HashA[i-1][Time] * bs + 1 + (int) (A[i] == Char);
	}

	for (int i = 1; i <= n; ++i) {
		char c = A[i];
		for (char Char : lsCharB) {
			// Char -> c
			int l = i - First_Pos[Char] + 1, r = l + m - 1;
			if (r > n || l < 1) continue;  
			if (HashB[Char] == get_Hash(c, l, r)) ok[l]++;
		}
	}

	int res = 0;
	for (int i = 1; i <= n-m+1; ++i) res += ( ok[i] == (int) lsCharB.size() );
	cout << res << '\n'; 
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("substrg.inp", "r")) {
		freopen("substrg.inp", "r", stdin);
		freopen("substrg.out", "w", stdout);
	}

	cin >> A >> B;
	n = (int) A.length(); m = B.length();
	A = " " + A; B = " " + B;

	sol();

	return 0;
}