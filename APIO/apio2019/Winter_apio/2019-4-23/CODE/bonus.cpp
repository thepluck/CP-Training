#include<bits/stdc++.h>
#define int 				long long
using namespace std;

const int MOD = 111539768;
int m, n, k, x, y, u, v;

int Pow(int a, int b) {
	if (b == 0) return 1;
	int tmp = Pow(a, b/2);
	if (b % 2 == 0) return tmp * tmp % MOD;
	return tmp * tmp % MOD * a % MOD;
}

int calc(int a, int b, int mul) {
	if (b == 0) return 1;
	if (b % 2 == 0) return calc(a, b-1, mul) + Pow(a, b*mul);

	int tmp = calc(a, b/2, mul);
	return tmp * ( 1 + Pow(a, (b/2+1) * mul) ) % MOD;
}

void sol() {
	int L = (y-1) * m + x-1;
	int R = L + (u-x+1) - 1;

		// cerr << "# " << (x-1) * m + y-1 << '\n';
		// cerr << "# " << L << " " << R << '\n';

	int res1 = calc(k, R-L, 1) % MOD;
	int res2 = Pow(k, L) * calc(k, v-y, m) % MOD;
		// cerr << "# " << v-y << '\n';
		// cerr << "# " << v-y << '\n';
		// cerr << "# " << Pow(k, L) << '\n';
		// cerr  << "? " << m-x+y << " " << y << '\n';

	cout << res1 * res2 % MOD;
}

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("bonus.inp", "r")) {
		freopen("bonus.inp", "r", stdin);
		freopen("bonus.out", "w", stdout);
	}

	// cin >> m >> n >> k >> x >> y >> u >> v;
	cin >> n >> m >> k >> y >> x >> v >> u;

	sol();

	return 0;
}