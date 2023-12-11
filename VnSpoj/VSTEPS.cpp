#include <bits/stdc++.h>
using namespace std;
const int mod = 14062008;
bool stair[100010];
long long dp[100010];
inline void fastscan(int &x){
	x = 0;
	register int c = getchar();
	for (; c > 47 && c < 58; c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
}
int main() {
	// your code goes here
	int n, k; fastscan(n);
	memset(stair, 1, sizeof stair);
	fastscan(k); int x;
	while (k--){
		fastscan(x); stair[x] = 0;
	}
	if (!stair[1]){
		cout << 0; return 0;
	}
	dp[1] = 1;
	dp[2] = stair[2] ? 1 : 0;
	for (int i = 3; i <= n; i++){
		if (!stair[i] || !(stair[i - 1] || stair[i - 2])){
			dp[i] = 0; continue;
		}
		if (!stair[i - 1]) dp[i] = dp[i - 2];
		else if (!stair[i - 2]) dp[i] = dp[i - 1];
		else dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n];
	return 0;
}