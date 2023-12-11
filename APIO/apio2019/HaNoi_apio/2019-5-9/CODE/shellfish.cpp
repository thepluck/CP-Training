#include<bits/stdc++.h>
#define FOR(i, a, b)			for (int i = a; i <= (int) b; ++i)
#define FOD(i, a, b) 			for (int i = a; i >= (int) b; --i)
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c) && c != '-');
	bool Minus = false; if (c == '-') { Minus = true; c = getchar(); }
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
	if (Minus) val = -val;
}
void Read(char &c) {
	do { c = getchar(); } while (c != 'U' && c != 'D');
}
void Write(int val) {
	if (val < 0) putchar('-'), Write(-val);
	else if (val < 10) putchar('0' + val);
	else Write(val/10), putchar('0' + val%10);
}

const int N = 1504;
int n, a[N][N];

int dp[N][N];

struct Binary_Indexed_Tree {
	int node[N];

	void update(int pos, int val) {
		for (int i = pos; i < N; i += i & (-i)) node[i] += val;
	}
	int get(int pos) {
		int ans = 0;
		for (int i = pos; i > 0; i -= i & (-i)) ans += node[i];
		return ans;
	}
} BIT[N];

void Build_org_dp() {
	FOR(i, 1, n) FOR(j, 1, n) {
		dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + a[i][j];
		BIT[i].update(j, dp[i][j]); 
	}
	Write(dp[n][n]); putchar('\n');
}

void let_s_update(int u, int v, int Add) {
	int l = u, r = u;
	FOR(i, u, n) {
		while (r+1 <= n) {
			int val = BIT[i].get(r+1) - BIT[i].get(r);
			if (val <= BIT.get())
		}
	}
}

void Answer_Query() {
	FOR(Time, 1, n) {
		Read(type); Read(u); Read(v);
		int Add = (type == 'U') ? 1 : -1;
		let_s_update(u, v, Add);
	}
}

void sol() {
	Build_org_dp();
	Answer_Query();
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("shellfish.inp", "r")) {
		freopen("shellfish.inp", "r", stdin);
		freopen("shellfish.out", "w", stdout);
	}

	Read(n);
	FOR(i, 1, n) FOR(j, 1, n) Read(a[i][j]);

	sol();

	return 0;
}
