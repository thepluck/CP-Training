#include<bits/stdc++.h>
#define int 			long long
using namespace std;

int m, n;

struct frac {
	int A, B;
	frac() {}; frac(int A, int B) : A(A), B(B) {};

	void optimize() {
		int gcd = __gcd(A, B);
		A /= gcd; B /= gcd;
	}

	void Print() { 
		if (B < 0) { A = -A; B = -B; }
		cout << A << "/" << B << '\n'; 
	}
};

frac operator * (frac a, frac b) {
	frac ans = frac(a.A * b.A, a.B * b.B);
	ans.optimize();
	return ans;
}

frac operator + (frac a, frac b) {
	frac ans = frac(a.A * b.B + a.B * b.A, a.B * b.B);
	ans.optimize();
	return ans;
}

main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("bwball.inp", "r")) {
		freopen("bwball.inp", "r", stdin);
		freopen("bwball.out", "w", stdout);
	}

	cin >> m >> n;

	frac p = frac(1, 1), res = frac(0, 1);
	int a = 0;

	for (int turn = 1; turn <= m+1; ++turn) {
		a = (turn % 2 == 1) ? -abs(a) - 5 : abs(a) + 5;

		frac mul = frac(n, n+m-turn+1);
		res = res + p * mul * frac(a, 1); res.optimize();
		p = p * frac(m-turn+1, n+m-turn+1); p.optimize(); 
	}
	res.Print();

	return 0;
}