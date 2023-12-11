#include<bits/stdc++.h>
#define int 				long long
using namespace std;

void Read(int &val) {
	val = 0; char c;
	do { c = getchar(); } while (!isdigit(c));
	while (isdigit(c)) { val = val * 10 + c - '0'; c = getchar(); }
}

typedef pair<long double, int> fi;

const int N = 5e5 + 4;
const long double oo = (long double) 1e17;
int L, A, B, T, R, n, coff[N];
vector<int> ans;

struct Interval_Tree {
	long double node[4*N];
	int Pos[4*N];

	Interval_Tree() {
		for (int i = 0; i < 4*N; ++i) node[i] = oo;
	}

	void update(int i, int l, int r, int x, int y, long double val, int id) {
		if (l > y || x > r) return;
		if (x <= l && r <= y) {
			node[i] = val; Pos[i] = id;
			return;
		}
		int mid = (l + r) / 2;
		update(2*i, l, mid, x, y, val, id);
		update(2*i+1, mid+1, r, x, y, val, id);
		node[i] = min(node[2*i], node[2*i+1]);
		Pos[i] = (node[2*i] < node[2*i+1]) ? Pos[2*i] : Pos[2*i+1];
	}

	fi get(int i, int l, int r, int x, int y) {
		if (l > y || x > r) return fi(oo, -1);
		if (x <= l && r <= y) return fi(node[i], Pos[i]);
		int mid = (l + r) / 2;
		fi tmp1 = get(2*i, l, mid, x, y), tmp2 = get(2*i+1, mid+1, r, x, y);
		if (tmp2.first <= tmp1.first) return tmp2;
		return tmp1;
		// return min(tmp1, tmp2);
	}
} IT[2];

long double dp[N];
int Trace[N];

void sol() {
	int point = 1;
	for (int i = 1; i <= n+1; ++i) {
		dp[i] = (long double) coff[i] / (long double) A;
		Trace[i] = 0;

		while (point <= i && coff[i] - coff[point] > B*R + T*A) ++point; 

		fi tmp0 = IT[0].get(1, 1, n, point, i-1);
		fi tmp1 = IT[1].get(1, 1, n, 1, point-1);

		long double val0 = tmp0.first + T - (long double) T*A/ (long double) B + (long double) coff[i] / (long double) B; 
		// long double val1 = tmp1.first + T + R + (long double) (coff[i] - B*R - T*A) / (long double) A;
		long double val1 = tmp1.first + R + (long double) (coff[i] - B*R) / (long double) A;

		if (val0 <= val1) {
			if (dp[i] > val0) { dp[i] = val0; Trace[i] = tmp0.second; }
		} 
		else {
			if (dp[i] > val1) { dp[i] = val1; Trace[i] = tmp1.second; }
		}

		IT[0].update( 1, 1, n, i, i, dp[i] - (long double) coff[i] / (long double) B, i );
		IT[1].update( 1, 1, n, i, i, dp[i] - (long double) coff[i] / (long double) A, i );
	}

		// cerr << "# " << dp[4] << '\n';

	int u = n+1;
	while (u > 0) {
		if (u != n+1) ans.push_back(u); 
		u = Trace[u];
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int u : ans) cout << u-1 << " "; cout << '\n';
}

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}

	Read(L); Read(A); Read(B); Read(T); Read(R);
	Read(n);
	for (int i = 1; i <= n; ++i) Read(coff[i]); coff[n+1] = L;

	sol();

	return 0;
}