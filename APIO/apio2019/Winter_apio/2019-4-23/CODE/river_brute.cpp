#include<bits/stdc++.h>
using namespace std;

const int N = 18;
int n;

int val[N], Match[N];
bool Disable[N];

bool ore_cek(int l, int r, int low, int high) {
	if (l > r) return true;

	int Next = (Match[l] == 0) ? l : Match[l];
	if (Next > high) return false;
	
	bool ok1 = ore_cek(l+1, Next-1, l, Next);
	if (!ok1) return false;

	bool ok2 = ore_cek(Next+1, r, low, high);
	if (!ok2) return false;

	return true;
}

bool Check(int pos) {
	int St = 0;
	for (int id = 0; id <= 1; ++id) {
		bool ok = true;

		St++; //if (id != 1) continue;
		for (int i = St; i <= pos; i += 2) {
			Match[val[i]] = val[i+1];
			Match[val[i+1]] = val[i];

			if ( id == 1 && i < pos && min(val[i], val[i+1]) < val[1] && val[1] < max(val[i], val[i+1]) ) { 
				ok = false; break; 
			} 
		}

		if (!ok) {
			for (int i = St; i <= pos; ++i) Match[val[i]] = Match[val[i+1]] = 0;
			return false;
		}

		ok = ore_cek(1, n, 0, n+1);
		for (int i = St; i <= pos; ++i) Match[val[i]] = Match[val[i+1]] = 0;

		if (!ok) return false;
	}

	if (pos == n) {
		if (n % 2 == 1) St = 1; else St = 2;
		for (int i = St; i <= n; i += 2) 
			if ( min(val[i], val[i+1]) < val[n] && val[n] < max(val[i], val[i+1]) ) return false;
	}
	return true;
}

int calc(int pos) {	
	bool cc = Check(pos-1);
	// for (int i = 1; i < pos; ++i) cerr << val[i] << " "; cerr << '\n';
	// cerr << "CEK : " << cc << '\n';
	if (!cc) return 0;

	if (pos == n+1) return 1;

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (Disable[i]) continue;
		Disable[i] = true; val[pos] = i;
		res += calc(pos+1);
		Disable[i] = false; val[pos] = 0;
 	}
 	return res;
}

void sol() {
		// val[1] = 1; val[2] = 2;
		// bool cc = Check(2);
		// cerr << "T_T: " << cc << '\n';
		// exit(0);
 
	int res = calc(1);
	cout << res * 2 << '\n';
}

int main() {
	if (fopen("input.txt", "r")) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	else if (fopen("river.inp", "r")) {
		freopen("river.inp", "r", stdin);
		freopen("river.out", "w", stdout);
	}

	cin >> n;
	if (n == 1) { cout << 2 << '\n'; exit(0); }

	sol();

	// Const_Array();

	return 0;
}