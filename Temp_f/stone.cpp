#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

long long dp[N][N], s[N];
int p[N][N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i]; dp[i][i] = 0;
		p[i][i] = i; s[i] += s[i - 1];
	}
	for (int j = 2; j <= n; j++) {
		for (int i = j - 1; i > 0; i--) {
			dp[i][j] = LLONG_MAX;
			for (int k = p[i][j - 1];
			k <= min(p[i + 1][j], j - 1); k++) {
				if (dp[i][j] > dp[i][k] + dp[k + 1][j]) {
					dp[i][j] = dp[i][k] + dp[k + 1][j];
					p[i][j] = k;
				}
			}
			dp[i][j] += s[j] - s[i - 1]; 
		}
	}
	cout << dp[1][n] << '\n';
}