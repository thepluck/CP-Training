#include<bits/stdc++.h>
using namespace std;

struct data {
	int i, j, k, t;
	data() {}; data(int i, int j, int k, int t) : i(i), j(j), k(k), t(t) {};
};

const int N = 24;
int n, a[N], b[N];
vector<data> ans;

void sol(int l, int r) {
	while (true) {
		bool isEnd = true;
		for (int i = l; i <= r; ++i) if (a[i] != 0) { isEnd = false; break; }
		if (isEnd) break;

		ans.push_back( data(l, l+1, l+2, l+3) );
		for (int i = l; i <= r; ++i) b[i] = (i == r) ? abs(a[r]-a[l]) : abs(a[i]-a[i+1]);
		for (int i = l; i <= r; ++i) a[i] = b[i];
	}
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("cq.inp", "r")) {
		freopen("cq.inp", "r", stdin);
		freopen("cq.out", "w", stdout);
	}

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	for (int i = 1; i <= n; i += 4) {
		if (i+3 <= n) sol(i, i+3);
		else sol(n-3, n);
	}

	cout << ans.size() << '\n';
	for (data tmp : ans) cout << tmp.i << ' ' << tmp.j << ' ' << tmp.k << ' ' << tmp.t << '\n';

	return 0;
}