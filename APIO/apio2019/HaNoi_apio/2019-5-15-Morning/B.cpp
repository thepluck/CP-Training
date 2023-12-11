#include<bits/stdc++.h>
#define int 			long long
using namespace std;

const int N = 1e5 + 4;
int n, a[N];

main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];

	reverse(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) cout << a[i] << " ";

	return 0;
}