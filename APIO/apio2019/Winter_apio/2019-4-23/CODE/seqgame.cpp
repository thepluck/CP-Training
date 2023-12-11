#include<bits/stdc++.h>
#define int 				long long
using namespace std;

const int N = 1004;
int n, d, a[N], b[N];

void sol() {
	int res = -1;
	for (int save = 1; save <= n; ++save) {
		b[save] = a[save];
		for (int i = save-1; i >= 1; --i) b[i] = b[i+1] - d;
		for (int i = save+1; i <= n; ++i) b[i] = b[i-1] + d;

		int val = 0;
		for  (int i = 1; i <= n; ++i) val += abs(b[i] - a[i]);
		res = (res == -1) ? val : min(res, val);
	}
	cout << res << '\n';
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("seqgame.inp", "r")) {
		freopen("seqgame.inp", "r", stdin);
		freopen("seqgame.out", "w", stdout);
	}

	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	sol();

	return 0;
}