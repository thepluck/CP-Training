#include <bits/stdc++.h>
using namespace std;

const int N = 300000;
const int K = 8;

int a[N][K], id[1 << K];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			cin >> a[i][j];
	int lo = 0, hi = 1e9, ans[2];
	while (lo <= hi) {
		int mi = (lo + hi) / 2;
		int tmp[] = {-1, -1};
		memset(id, -1, sizeof id);
		for (int i = 0; i < n; i++) {
			int msk = 0;
			for (int j = 0; j < k; j++)
				if (a[i][j] >= mi)
					msk ^= 1 << j;
			id[msk] = i;
		}
		for (int i = 0; i < (1 << k); i++)
			for (int j = 0; j < (1 << k); j++)
				if (~id[i] && ~id[j]
				&& (i | j) + 1 == (1 << k)) {
					tmp[0] = id[i];
					tmp[1] = id[j];
				}
		if (~tmp[0]) {
			lo = mi + 1; swap(ans, tmp);
		}
		else hi = mi - 1;
	}
	ans[0]++; ans[1]++;
	cout << ans[0] << ' ' << ans[1] << '\n';
} 