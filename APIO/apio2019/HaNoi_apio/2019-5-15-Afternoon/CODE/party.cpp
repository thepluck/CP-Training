#include<bits/stdc++.h>
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}
void Write(int val) {
	if (val < 10) putchar('0' + val);
	else Write(val/10), putchar('0' + val%10);
}

const int N = 1e6 + 4, MOD = 1e9 + 7;
int n, Fact[N];

int main() {
	Fact[0] = 1;
	for (int i = 1; i < N; ++i) Fact[i] = (1LL * Fact[i-1] * i) % MOD;

	int T, n;
	cin >> T;
	while (T--) {
		Read(n); 
		Write(Fact[n]); putchar('\n');
	}

	return 0;
}