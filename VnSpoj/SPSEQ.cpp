#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], f[N], g[N], t[N], maxlen;

int main() {
	// your code goes here
	int n; cin >> n; t[0] = INT_MIN;
	for (int i = 1, len = 0, tmp; i <= n; i++){
		cin >> a[i];
		tmp = lower_bound(t, t + len + 1, a[i]) - t;
		t[tmp] = a[i]; f[i] = tmp; 
		len = max(len, tmp);
	}
	for (int i = n, len = 0, tmp; i >= 1; i--){
		tmp = lower_bound(t, t + len + 1, a[i]) - t;
		t[tmp] = a[i]; g[i] = tmp; 
		len = max(len, tmp);
		maxlen = max(maxlen, min(f[i], g[i]) * 2 - 1);
	}
	cout << maxlen;
	return 0;
}