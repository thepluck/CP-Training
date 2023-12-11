#include <bits/stdc++.h>
using namespace std;

bool check(long a){
	long k = sqrt(2 * a);
	return k * (k + 1) == 2 * a;
}

int main() {
	long n; cin >> n;
	vector<long> v(n);
	for (auto &i : v) cin >> i;
	long f = 0; long maxv = 0;
	if (check(v[0])) f = 1;
	for (long i = 1; i < n; i++){
		if (check(v[i])){
			if (v[i] >= v[i - 1]) f++;
			else f = 1;
			maxv = max(maxv, f);
		}
		else f = 0;
	}
	cout << maxv;
	return 0;
}