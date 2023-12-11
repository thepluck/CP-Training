#include<bits/stdc++.h>
using namespace std;

int main() {	
	long double res = 0;
	for (int i = 1; i <= 27; ++i) res += (long double) 2*i / (long double) (1<<i);
	cout << setprecision(5) << fixed << res << '\n';
}