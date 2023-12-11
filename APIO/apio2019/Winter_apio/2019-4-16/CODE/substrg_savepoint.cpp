#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

const int N = 2e5 + 4, bs = 137;
int n, m;
string A, B;

ULL Pow[N], HashA[N], HashB;
unordered_map<ULL, bool> Map; 
bool check[N];

ULL get_Hash(int l, int r) {
	return HashA[r] - HashA[l-1] * Pow[r-l+1];
}

bool vis[200];
vector<char> lsChar;

void sol() {
	for (int i = 1; i <= n; ++i) if (!vis[A[i]]) lsChar.push_back(A[i]);
	for (int i = 1; i <= m; ++i) if (!vis[B[i]]) lsChar.push_back(B[i]);

	for (int i = 0; i <= n; ++i) {
		Pow[i] = (i == 0) ? 1 : Pow[i-1] * bs;
		if (i <= n-m+1) check[i] = true;
	}

	for (char Char : lsChar) {
		for (int i = 0; i <= m; ++i) HashB = (i == 0) ? 0 : HashB * bs + (B[i] == Char);
		Map[HashB] = true;
	}
	for (char Char : lsChar) {
		for (int i = 1; i <= n; ++i) HashA[i] = HashA[i-1] * bs + (A[i] == Char);

		for (int i = 1; i <= n-m+1; ++i) {
			ULL code = get_Hash(i, i+m-1);
			if (!Map.count(code)) check[i] = false; 
		}
	}

	int res = 0;
	for (int i = 1; i <= n-m+1; ++i) res += (int) check[i];
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