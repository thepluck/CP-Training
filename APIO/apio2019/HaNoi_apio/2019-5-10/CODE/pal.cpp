#include<bits/stdc++.h>
using namespace std;

const int N = 2e7 + 4, SZ = 102;
const long long MOD = 1e9 + 17;
int n;
long long rev, Hash, Pow = 1;

void sol() {
	char c;
	while (c = getchar()) {
		if (c < 'a' || c > 'z') break;
		long long code = (c - 'a');
		Hash = (Hash * 31 + code) % MOD;
		rev = (code * Pow + rev) % MOD;
		Pow = (Pow * 31) % MOD;
	}
	if (Hash == rev) cout << "TAK \n";
	else cout << "NIE \n";
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	scanf("%d ", &n);
	sol();

	return 0;
}