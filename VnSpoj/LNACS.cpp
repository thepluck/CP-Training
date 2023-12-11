#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) cin >> b[j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			if (a[i] == b[j]){
				if (i > 1 && j > 1) dp[i][j] = dp[i - 2][j - 2] + 1;
				else dp[i][j] = 1;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[n][m];
	return 0;
}