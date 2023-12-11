#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 5, LG = 18;

int nxtl[LG][N], nxtr[LG][N];
ll suml[LG][N], sumr[LG][N];
int n, m, q, x[N];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> x[i];
	cin >> q;
}

void init() {
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && x[j] - x[i] < m) j++;
		nxtl[0][i] = j; suml[0][i] = j;
	}
	for (int i = n - 1, j = i; ~i; i--) {
		while (~j && x[i] - x[j] < m) j--;
		nxtr[0][i] = j; sumr[0][i] = j + 1;
	}
	for (int k = 1; k < LG; k++)
		for (int i = 0; i < n; i++) {
			if (nxtl[k - 1][i] < n) {
				nxtl[k][i] = nxtl
				[k - 1][nxtl[k - 1][i]];
				suml[k][i] = suml[k - 1][i]
				+ suml[k - 1][nxtl[k - 1][i]];
			}
			else nxtl[k][i] = n;
			if (~nxtr[k - 1][i]) {
				nxtr[k][i] = nxtr
				[k - 1][nxtr[k - 1][i]];
				sumr[k][i] = sumr[k - 1][i]
				+ sumr[k - 1][nxtr[k - 1][i]];
			}
			else nxtr[k][i] = -1;
		}
}

int query(int l, int r) {
	ll sl = l, sr = r + 1;
	int curl = l, curr = r;
	for (int k = LG - 1; ~k; k--) {
		if (nxtl[k][curl] <= r) {
			sl += suml[k][curl];
			curl = nxtl[k][curl];
		}
		if (nxtr[k][curr] >= l) {
			sr += sumr[k][curr];
			curr = nxtr[k][curr];
		}
	}
	return sr - sl;
}

void process() {
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(l - 1, r - 1) << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	input(); init(); process();
}